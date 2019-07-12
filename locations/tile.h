#ifndef TILE_H_
#define TILE_H_

#include "../characters/character.h"

class Tile{
        public:
        enum TileType {wall, open, teleporter};

        Tile(TileType);
        
        ~Tile();
        TileType getTileType() const;

        // Returns true if the tile is occupied
        bool isOccupied() const;

        char calculateDisplayedLetter() const;

        // Makes the passed character the tile's occupant
        void addOccupant(Character *c);

        // Removes the occupant of the tile
        void evictOccupant();

        // Calls the notify method of the occupant
        void notifyOccupant(Character &source);
        private:
        Character* occupant;
        
        TileType type;
        
};  

#endif