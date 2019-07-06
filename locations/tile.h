#ifndef TILE_H_
#define TILE_H_

#include "../locations/tile.h"

class Tile{
        Character& occupant;
        enum tileType {wall, enemy, open, npc};
    public: 
        Tile();
        ~Tile();
};  

#endif