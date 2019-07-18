#ifndef MEDIUMENEMY_H_
#define MEDIUMENEMY_H_

#include "../enemy.h"

class MediumEnemy : public Enemy{
    public:
        MediumEnemy(int x,int y, char displayLetter, int health = 150, int damageAmount = 10);
};

#endif  