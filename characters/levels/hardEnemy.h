#ifndef HARDENEMY_H_
#define HARDENEMY_H_

#include "../enemy.h"

class HardEnemy : public Enemy{
    public:
        HardEnemy(int x,int y, int health = 200, int damageAmount = 20);
};

#endif  