#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <utility>

class Location;

class Character {
        std::pair<int,int> coordinates;
        Location* location;
    public:
        Character(int x,int y);
        virtual ~Character() = 0;

        // Should be a function that allows a character to be interacted with,
        // and possibly retrieve information from the source Character of the interaction.
        virtual void notify(Character &source) = 0;
};

#endif


