#ifndef EASYENEMY_H_
#define EASYENEMY_H_

#include "../enemy.h"

class EasyEnemy : public Enemy{
    public:
        EasyEnemy(int x,int y, int health = 100, int damageAmount = 5);
};

#endif  