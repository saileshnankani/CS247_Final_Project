#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <utility>
#include "../locations/location.h"
#include "../subjectObserver/subject.h"

class Location;

class Character : public Subject{
        std::pair<int,int> coordinates;
        Location* location;
    public:
        Character();
        virtual ~Character();
};

#endif

