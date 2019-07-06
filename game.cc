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

    ifstream mcFile;
    ifstream tathamFile;
    ifstream californiaFile;

    mcFile.open("locations/mc.in");
    tathamFile.open("locations/tatham.in");
    californiaFile.open("locations/california.in");

    if(mcFile.is_open()){
        while(getline(mcFile,line)){
            cout<<line<<endl;
        }   
        mcFile.close();
    }
    cout<<endl;

    if(tathamFile.is_open()){
        while(getline(tathamFile,line)){
            cout<<line<<endl;
        }   
        tathamFile.close();
    }
    cout<<endl;

    if(californiaFile.is_open()){
        while(getline(californiaFile,line)){
            cout<<line<<endl;
        }   
        californiaFile.close();
    }
    cout<<endl;
}

Game::~Game(){}



int main(){
    char cmd;
    Game game;

    while(!game.gameOver && cmd!='q'){
        
    }
}