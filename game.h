#ifndef GAME_H_
#define GAME_H_

#include "location.h"
#include <vector>

class Game{
    std::vector<Location*> locations;
    int currentLocation;

    public:
        Game();
        ~Game();
        bool gameOver;
};

#endif