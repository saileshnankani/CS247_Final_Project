#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <utility>
#include "../locations/location.h"

class Location;

class Character{
        std::pair<int,int> coordinates;
        Location* location;
    public:
        Character();
        ~Character();
};

#endif

