#include "standard.h"
#include <iostream>

using namespace std;

Standard::Standard(Location* currentLocation) : View{currentLocation} {};

void Standard::updateView(){
    
    for(const auto &row : currentLocation->getGrid())
    {
        for(const auto &tile : row){
            std::cout<<tile.calculateDisplayedLetter()<<" ";
        }
        std::cout<<std::endl;
    }
}