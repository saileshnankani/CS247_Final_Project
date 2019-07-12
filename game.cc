#include "game.h"

Game::Game() : model(), controller(model){}

Game::~Game(){}

void Game::run() {
    controller.updateGameUntilGameOver();
}

int main(){
    Game game;
    game.run();
}