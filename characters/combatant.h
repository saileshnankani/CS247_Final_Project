#ifndef COMBATANT_H_
#define COMBATANT_H_

#include "character.h"

class Combatant : public Character{
        bool isPlayer;
    protected: 
        int health;
    public:
        Combatant();
        virtual ~Combatant();
        virtual void takeDamage(int);
        virtual int getHealth();
};

#endif