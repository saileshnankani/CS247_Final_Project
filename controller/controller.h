#ifndef CONTROLLER_H
#define CONTROLLER_H

class Model;

class Controller
{
    Model &model;
    // Other stuff probably, like a reference to the model
public:
    Controller(Model&);
    // Allows the game to execute by repeatedly updating the game state.
    void updateGameUntilGameOver();
};

#endif