#ifndef GAME_H_
#define GAME_H_

#include "model/model.h"
#include "controller/controller.h"

class Game {
        Model model;
        Controller controller;
    public:
        Game();
        ~Game();
        void run();
};

#endif