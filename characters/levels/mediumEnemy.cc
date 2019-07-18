#include "mediumEnemy.h"
#include "../enemy.h"

MediumEnemy::MediumEnemy(int x, int y, char displayLetter, int health, int damageAmount) : Enemy(x,y,health,damageAmount, displayLetter) {}; 