#ifndef GAME_H_
#define GAME_H_

#include "model/model.h"
#include "controller/controller.h"

class Game : Model {
    public:
        Game(bool curses);
        ~Game();
        void play();
};

#endif