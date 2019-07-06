#ifndef TILE_H_
#define TILE_H_

#include"character.h"

class Tile{
        Character& occupant;
        bool isOccupied;
        char c;   // so this indicates whether it is 
    public: 
        Tile();
        ~Tile();
};  

#endif