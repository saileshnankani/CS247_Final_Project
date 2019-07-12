#ifndef COMBATANT_H_
#define COMBATANT_H_

#include "character.h"

class Combatant : public Character{
    public:
        Combatant(int x,int y);
        virtual ~Combatant();
        virtual void takeDamage(int);
        virtual void notify(Character &source);
};

#endif