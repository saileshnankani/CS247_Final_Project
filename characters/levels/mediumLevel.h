#ifndef MEDIUMLEVEL_H_
#define MEDIUMLEVEL_H_

#include "mediumEnemy.h"
#include "level.h"

class MediumLevel : public Level{
    public: 
        MediumEnemy* createEnemy(int x, int y) override;
        MediumLevel();
};

#endif