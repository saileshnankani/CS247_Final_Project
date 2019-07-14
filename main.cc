#include "game.h"
#include "model/model.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    bool curses = false;
    cout<<"Choose a difficulty level: easy(E), medium(M), or hard(H)"<<endl;
    char levelChar;
    cin >> levelChar;
    if(argv[1]=="curses"){
        curses = true;
    }
    Game game(curses);
    game.initializeLevel(levelChar);
    game.play();
}