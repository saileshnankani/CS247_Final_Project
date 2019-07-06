#ifndef GAME_H_
#define GAME_H_

#include "locations/location.h"
#include "subjectObserver/subject.h"
#include <vector>
#include <memory>

class Game : public Subject{
    std::vector<Location*> locations;
    int currentLocation;

    public:
        Game();
        ~Game();
        bool gameOver;
        void run();
};

#endif