#include "game.h"
#include "controller/action.h"
#include "controller/keyboard.h"
#include "controller/curseControl.h"
#include "controller/controller.h"
#include "model/model.h"
#include "view/view.h"
#include "view/CurseView.h"
#include "view/standard.h"
#include <iostream>

using namespace std;

Game::Game(bool curses){
    if( curses ){
        addView(std::move(std::make_unique<Curses>(cols, rows, *this))); // add curses view
        if ( !hasController() ){
            addController(std::move(std::make_unique<CurseKeyboard>())); // curse Keyboard controller
        }
    }
    else{ // NO CURSES 
        addView(std::move(std::make_unique<Standard>(cols, rows, *this))); // add standard view
        addView(std::move(std::make_unique<Written>(cols, rows, *this))); // add written view
        if ( !hasController() ){
        addController(std::move(std::make_unique<Keyboard>())); // Keyboard controller
        }
    }
}

Game::~Game(){}

void Game::play() {
    Action a;
    Location* currentLocation = getCurrentLocation();
    while(cin){
        displayViews();
        a = getAction();
        currentLocation->updateState(a);
    }   
}

