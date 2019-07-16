#ifndef COMBATANT_H_
#define COMBATANT_H_

#include "character.h"

class Combatant : public Character{
    public:
        Combatant(int x,int y);
        virtual ~Combatant();
        virtual int getDamage() =0;
        virtual int getHealth() const =0; 
        //TODO: Remove this function
        virtual void takeDamage(int);
        //TODO: Remove this function
        //virtual void notify(Character &source);
};

#endif