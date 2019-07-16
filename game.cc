#include "game.h"
#include "view/curseView.h"
#include "view/graphic.h"
#include "view/standard.h"
#include "controller/keyboard.h"
#include "controller/curseControl.h"

#include <string>
#include <iostream>

using namespace std;    

Game::Game(bool ncurses, bool graphic) : model(){

    cout<<"Choose a difficulty level: easy(E), medium(M), or hard(H)"<<endl;
    char levelChar;
    cin >> levelChar;

    model.initializeLevel(levelChar);
    model.initializeLocations();

    model.staticGraphic = graphic;
    model.staticNcurses = ncurses;
    
    if(ncurses){
        model.addView(std::move(std::make_unique<Curses>(model.getCurrentLocation())));
        if(!model.hasController()){
            model.addController(std::move(std::make_unique<CurseKeyboard>())); // Keyboard controller
        }
    }
    else if(graphic){
        model.addView(std::move(std::make_unique<Graphic>(model.getCurrentLocation())));
        if(!model.hasController()){
            model.addController(std::move(std::make_unique<Keyboard>())); // Keyboard controller
        }
    }
    else{
        model.addView(std::move(std::make_unique<Standard>(model.getCurrentLocation())));
        if(!model.hasController()){
            model.addController(std::move(std::make_unique<Keyboard>())); // Keyboard controller
        }
    }

}

Game::~Game(){}

void Game::run() {
    Action a;
    bool isTeleported = false;
    while(!model.getIsGameOver() && std::cin){
        model.displayViews();
        a = model.getAction(); 
        isTeleported = model.getTeleportationStatus(a);     
        if(isTeleported){
            model.setNextLocation();
            cout<<model.getCurrentLocation()->getName()<<endl;
            if(model.staticNcurses){
                model.replaceView(std::move(std::make_unique<Curses>(model.getCurrentLocation())));
            }
            else if(model.staticGraphic){
                model.replaceView(std::move(std::make_unique<Graphic>(model.getCurrentLocation())));
            }
            else{
                model.replaceView(std::move(std::make_unique<Standard>(model.getCurrentLocation())));
            }
            continue;
        }   
        model.updateCurrentLocationState(a);
    }
}

int main(int argc, char* argv[]){
    bool ncurses = false;
    bool graphic = false;
    if(argc == 2){
        string input = argv[1];
        if("ncurses" == input){
            ncurses = true;
        }
        else if("graphic" == input){
            graphic = true;
        }
    }
    Game game(ncurses, graphic);
    game.run();
}