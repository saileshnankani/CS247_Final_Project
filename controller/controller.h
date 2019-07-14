// #ifndef CONTROLLER_H
// #define CONTROLLER_H

// #include<memory>

// class Model;

// class Controller
// {
//     Model& model;
// public:
//     Controller(Model & model);
//     // Allows the game to execute by repeatedly updating the game state.
//     void updateGameUntilGameOver();
// };

// #endif

#ifndef ___CONTROLLER___H__
#define ___CONTROLLER___H__

#include "action.h"
#include <string>

class Controller{
  virtual Action action() = 0;
 public:
  Action getAction();
  virtual ~Controller() = default;
};
#endif
