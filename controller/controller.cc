#include "controller.h"
#include "../model/model.h"
#include "../view/standard.h"
#include "../view/curseView.h"
#include "../view/graphic.h"
#include <iostream>
#include <memory>

using namespace std;

Controller::Controller(Model & model) : model{model} {};

void Controller::updateGameUntilGameOver(bool ncurses, bool graphics){
    cout<<"Choose a difficulty level: easy(E), medium(M), or hard(H)"<<endl;
    char levelChar;
    cin >> levelChar;

    model.initializeLevel(levelChar);
    model.initializeLocations();
    
    if(ncurses){
        model.addView(std::move(std::make_unique<Curses>(model.getCurrentLocation())));
    }
    else if(graphics){
        model.addView(std::move(std::make_unique<Graphic>(model.getCurrentLocation())));
    }
    else{
        model.addView(std::move(std::make_unique<Standard>(model.getCurrentLocation())));
    }

    while(!model.getIsGameOver()){
        model.displayViews();
        model.updateCurrentLocationState();
    }
}