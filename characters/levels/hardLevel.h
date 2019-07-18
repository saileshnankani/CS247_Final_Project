#ifndef HARDLEVEL_H_
#define HARDLEVEL_H_

#include "hardEnemy.h"
#include "level.h"

class HardLevel : public Level{
    public: 
        HardEnemy* createEnemy(int x, int y, char displayLetter) override;
        HardLevel();
};

#endif  