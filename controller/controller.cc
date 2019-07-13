#include "controller.h"
#include "../model/model.h"
#include <iostream>
#include<memory>

using namespace std;

Controller::Controller(Model & model) : model{model} {};

void Controller::updateGameUntilGameOver(){
    cout<<"Choose a difficulty level: easy(E), medium(M), or hard(H)"<<endl;
    char levelChar;
    cin >> levelChar;

    model.initializeLevel(levelChar);
    model.initializeLocations();


    while(!model.getIsGameOver()){
        model.updateCurrentLocationState();
    }
}