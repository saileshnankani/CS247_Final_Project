#include "easyEnemy.h"
#include "../enemy.h"

EasyEnemy::EasyEnemy(int x, int y, char displayLetter, int health, int damageAmount) : Enemy(x,y,health,damageAmount, displayLetter) {}; 