#include "game.h"
#include <string>

using namespace std;    

Game::Game() : model(), controller(model){}

Game::~Game(){}

void Game::run(bool ncurses, bool graphic) {
    controller.updateGameUntilGameOver(ncurses, graphic);
}

int main(int argc, char* argv[]){
    bool ncurses = false;
    bool graphic = false;
    if(argc == 2){
        string input = argv[1];
        if("ncurses" == input){
            ncurses = true;
        }
        else if("graphic" == input){
            graphic = true;
        }
    }
    Game game;
    game.run(ncurses, graphic);
}