#include "mediumLevel.h"
#include "mediumEnemy.h"

MediumLevel::MediumLevel() {};

MediumEnemy* MediumLevel::createEnemy(int x, int y, char displayLetter){
    return new MediumEnemy(x,y,displayLetter);
}