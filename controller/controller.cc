#include "controller.h"
#include "../model/model.h"

void Controller::updateGameUntilGameOver()
    {
        while(!model.getIsGameOver()){
            model.updateCurrentLocationState();
        }
    }