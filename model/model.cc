#include "model.h"
#include <vector>
#include <string>

using namespace std;

bool Model::getIsGameOver()
{
    return isGameOver;
}

void Model::updateCurrentLocationState()
{
    currentLocation->updateState();
}

void Model::initializeEasyLevel(){
    level = make_unique<EasyLevel>();
}

void Model::initializeMediumLevel(){
    level = make_unique<MediumLevel>();
}

void Model::initializeHardLevel(){
    level = make_unique<HardLevel>();
}

Model::Model(){
    vector<string> locationNames{"mc","tatham"};
    
    for(auto str : locationNames){
        // shared_ptr for later
        Location* newLocation = new Location(str,*level);
        locations.push_back(newLocation);
        if(str=="mc"){
            currentLocation = newLocation;
        }
    }    
}