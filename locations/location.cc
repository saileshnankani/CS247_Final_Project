#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "location.h"
#include "../characters/enemy.h"
#include "../characters/player.h"
#include "tile.h"
#include "../characters/levels/level.h"

using namespace std;

Location::Location(string name, Level& level) : name{name} {

    string line;
   
    ifstream map;
    ifstream mapCharacters;
    ifstream mapNPC;

    map.open("locations/"+name+".in");
    mapCharacters.open("../characters/"+name+"Characters.in");
    mapNPC.open("../characters/"+name+"NPC.in");

    if(map.is_open() && mapCharacters.is_open() && mapNPC.is_open()){
        vector<Tile*> grid; 
        while(getline(map,line)){
            for(char c: line){
                switch(c){
                    case 'X':
                        grid.push_back(new Tile(Tile::TileType::wall));
                        break;
                    // case 'O':
                    //     grid.push_back(new Tile(Tile::TileType::open));
                    //     break;
                    // case 'G':
                    //     enemies.push_back(make_unique<Enemy>());
                    //     grid.push_back(new Tile(Tile::TileType::open));
                    //     break;
                    // case 'T': 
                    //     grid.push_back(new Tile(Tile::TileType::open));
                    //     break;                   
                    default:  
                        grid.push_back(new Tile(Tile::TileType::open));
                        break;
                }
            }
        } 
    
        char character;
        int pos_x;
        int pos_y;
        while(getline(mapCharacters, line)){
            stringstream ss(line);
            ss>>character>>pos_x>>pos_y;
            switch(character){
                case 'P': {
                    Player* newPlayer= new Player(pos_x,pos_y);
                    player = std::unique_ptr<Player>(newPlayer);
                    Tile& tile = tileAt(make_pair(pos_x,pos_y));
                    tile.addOccupant(newPlayer);
                    break;
                }
                case 'G':{
                    Enemy* newEnemy = level.createEnemy(pos_x, pos_y);
                    enemies.emplace_back(std::unique_ptr<Enemy>(newEnemy));
                    Tile& tile = tileAt(make_pair(pos_x,pos_y));
                    tile.addOccupant(newEnemy);
                    break;
                }
                default:
                    throw; 
            }
        }
    }



    map.close();
    mapCharacters.close();
    mapNPC.close();
}

// TODO. JUST NEEDED TO COMPILE 
void Location::updateState(){

}

Tile &Location::tileAt(const std::pair<int, int> &coords)
{
    int x = coords.first;
    int y = coords.second;
    return grid.at(y).at(x);
}