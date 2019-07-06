/**
 * This is the abstract base case for all the "floors" in the game. The 
 * concrete floors that are dervied from this class are MC, Tatham Centre,
 * and California.
 */

#include<vector>
#include"tile.h"
#include"character.h"

class Location {
        std::vector<std::vector<Tile>> grid;
        std::vector<Character> characters;
    public:
        Location();
        ~Location();
        class Iterator{


        };

        Iterator begin();
        Iterator end();

        class ConstIterator{

        };

        ConstIterator cbegin();
        ConstIterator cend();
};