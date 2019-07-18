#include "hardLevel.h"
#include "hardEnemy.h"

HardLevel::HardLevel() {};

HardEnemy* HardLevel::createEnemy(int x, int y, char displayLetter){
    return new HardEnemy(x,y, displayLetter);
}