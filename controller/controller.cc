#include "controller.h"
#include "../model/model.h"
#include <iostream>


using namespace std;

Controller::Controller(Model& m) : model(m) {};

void Controller::updateGameUntilGameOver(){
    cout<<"Choose a difficulty level: easy(E), medium(M), or hard(H)"<<endl;
    char levelInput;
    cin >> levelInput;

    switch(levelInput){
        case 'E':
            model.initializeEasyLevel();
            break;
        case 'M':
            break;
        case 'H':
            break;
    }


    while(!model.getIsGameOver()){
        model.updateCurrentLocationState();
    }
}