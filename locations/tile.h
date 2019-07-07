#ifndef TILE_H_
#define TILE_H_

#include "../characters/character.h"

class Tile{
        Character* occupant;
    public: 
        Tile(tileType,Character*);
        ~Tile();
        enum tileType {wall, enemy, open, npc};

        // Returns true if the tile is occupied
        bool isOccupied();

        // Makes the passed character the tile's occupant
        void addOccupant(Character &c);

        // Removes the occupant of the tile
        void evictOccupant();

        // Calls the notify method of the occupant
        void notifyOccupant(Character &source);
        
};  

#endif