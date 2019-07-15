#ifndef GAME_H_
#define GAME_H_

#include "model/model.h"
#include "controller/controller.h"

class Game {
        Model model;
    public:
        Game(bool ncurses, bool graphic);
        ~Game();
        void run();
};

#endif