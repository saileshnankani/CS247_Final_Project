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
    
    vector<ifstream> maps;
    vector<string> mapNames;

    mapNames[0] = "mc";
    mapNames[1] = "tatham";
    mapNames[2] = "california";
    maps.push_back(mcFile);
    maps.push_back(tathamFile);
    maps.push_back(californiaFile);

    for(int i=0; i<maps.size(); i++){
        maps.at(i).open("locations/"+mapNames.at(i)+".in");
    }

    Location* newLocation;
    
    for(int i=0; i<maps.size(); i++){
        if(maps.at(i).is_open()){
            vector<Tile*> grid; 
            while(getline(maps.at(i),line)){
                for(char c: line){
                    switch(c){
                        case 'X':
                            grid.push_back(new Tile(nullptr));
                            break;
                        case 'O':
                            grid.push_back(new Tile(nullptr));
                            break;
                        case 'G':
                            grid.push_back(new Tile(nullptr));
                            break;
                        default:  
                            cerr<<"Invalid Map"<<endl;
                            throw;
                    }
                }
            }   
            newLocation = new Location(grid,mapNames.at(i));
            locations.push_back(newLocation);
            maps.at(i).close();
            
        }
    }

    run();
}

bool Game::getGameStatus(){
    return gameOver;
}

Game::~Game(){}

void Game::run() {
    gameOver = false;
}


int main(){
    char cmd;
    Game game;

    while(!game.getGameStatus && cin>>cmd && cmd!='q'){
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