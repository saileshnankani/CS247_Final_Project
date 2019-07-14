#include "model.h"
#include <vector>
#include <string>
#include<iostream>

using namespace std;

bool Model::getIsGameOver()
{
    return isGameOver;
}

Location* getcurrentLocation(){
    return currentLocation;
}

void Model::initializeLocations(){
    vector<string> locationNames{"mc","tatham"};
    
    for(auto str : locationNames){
        // shared_ptr for later
        Location* newLocation = new Location(str, *level);
        locations.push_back(newLocation);
        if(str=="mc"){
            currentLocation = newLocation;
        }
    }  
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

void Model::initializeLevel(char levelChar){
    while(true){
        switch(levelChar){
            case 'E':
                initializeEasyLevel();
                return;
            case 'M':
                initializeMediumLevel();
                return;
            case 'H':
                initializeHardLevel();
                return;
            default:
            // TODO: change this to a proper output stream
            std::cout<< "Invalid input. Please enter E, M, or H."<<std::endl;
        }
    }
        
}


//TODO: probably make it so that isGameOver can be set to false/true some time.
Model::Model() : isGameOver{false}, currentLocation{nullptr} {}

void Model::displayViews(){
  for( auto& view: views ){
    view->updateView(currentLocation);
  }
}

Action Model::getAction(){
  return control->getAction();
}

