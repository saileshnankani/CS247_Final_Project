#include "location.h"
#include "character.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "game.h"

using namespace std;

Game::Game() : gameOver{false} {
    string line;

    ifstream mcFile ("/locations/mc.in");

    if(mcFile.is_open()){
        cout<<"Sailesh"<<endl;
        while(getline(mcFile,line)){
            cout<<line<<endl;
        }
        mcFile.close();
    }
}

Game::~Game(){}



int main(){
    char cmd;
    Game game;

    while(!game.gameOver && cmd!='q'){
        
    }
}