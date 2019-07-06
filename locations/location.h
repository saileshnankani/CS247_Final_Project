/**
 * This is the abstract base case for all the "floors" in the game. The 
 * concrete floors that are dervied from this class are MC, Tatham Centre,
 * and California.
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include<vector>
#include "tile.h"
#include "../characters/character.h"

class Location {
        std::vector<std::vector<Tile*>> grid;
        std::vector<Character> characters;
    public:
        Location();
        ~Location();
};

#endif