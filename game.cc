#include "locations/location.h"
#include "locations/tile.h"
#include "characters/character.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "game.h"

using namespace std;

Game::Game() : gameOver{true} {

    string line;

    ifstream mcFile;
    ifstream tathamFile;
    ifstream californiaFile;

    mcFile.open("locations/mc.in");
    tathamFile.open("locations/tatham.in");
    californiaFile.open("locations/california.in");



    if(mcFile.is_open()){
        Location* mc = new Location();
        while(getline(mcFile,line)){
            Tile* tile;
            for(char c: line){
                tile = new Tile();
            }
        }   
        mcFile.close();
        locations.push_back(mc);
    }

    if(tathamFile.is_open()){
        while(getline(tathamFile,line)){
            cout<<line<<endl;
        }   
        tathamFile.close();
    }

    if(californiaFile.is_open()){
        while(getline(californiaFile,line)){
            cout<<line<<endl;
        }   
        californiaFile.close();
    }

    run();
}

Game::~Game(){}

void Game::run() {
    gameOver = false;
}


int main(){
    char cmd;
    Game game;

    while(!game.gameOver && cin>>cmd && cmd!='q'){
        switch(cmd){
            case 'n':
                break;
            case 's':
                break;
            case 'w':
                break;
            case 'e':
                break;
        }

    }
}