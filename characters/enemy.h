#ifndef ENEMY_H_
#define ENEMY_H_

#include "combatant.h"

class Enemy : public Combatant{
        int health;
        int damageAmount;
    public:
        Enemy(int,int,int,int);

        virtual void notify(Character &source);
        virtual ~Enemy();
        virtual void takeDamage(int) override;
        virtual int getHealth(); 
};

#endif