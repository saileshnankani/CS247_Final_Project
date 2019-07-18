#ifndef EASYLEVEL_H_
#define EASYLEVEL_H_

#include "easyEnemy.h"
#include "level.h"

class EasyLevel : public Level{
    public: 
        EasyEnemy* createEnemy(int x, int y, char displayLetter) override;
        EasyLevel();
};

#endif  
