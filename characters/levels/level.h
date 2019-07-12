#ifndef LEVEL_H_
#define LEVEL_H_

#include "../enemy.h"
#include <memory>

class Level {
    public: 
        Level();
        virtual ~Level();
        virtual Enemy* createEnemy(int x, int y)=0;
};

#endif