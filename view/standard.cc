#include "standard.h"
#include <iostream>

using namespace std;

Standard::Standard(Location* currentLocation) : View{currentLocation} {};

void Standard::updateView(){

    cout<<"-----------------------------------------"<<endl;

    const int health = currentLocation->getPlayerHealth();

    cout<<"Current Location: "<<currentLocation->getName()<<endl;
    cout<<"Health: "<<health<<endl;
    cout<<endl;

    for(const auto &row : currentLocation->getGrid())
    {
        for(const auto &tile : row){
            std::cout<<tile.calculateDisplayedLetter()<<" ";
        }
        std::cout<<std::endl;
    }
    cout<<endl;
    cout<<"Enter your next move"<<endl<<endl;
    cout<<"-----------------------------------------"<<endl<<endl;
}