#include "model.h"

bool Model::getIsGameOver()
{
    return isGameOver;
}

void Model::updateCurrentLocationState()
{
    currentLocation->updateState();
}