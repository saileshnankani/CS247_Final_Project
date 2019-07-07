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

        // Should be a function that allows a character to be interacted with,
        // and possibly retrieve information from the source Character of the interaction.
        virtual void notify(Character &source) override;
};

#endif


