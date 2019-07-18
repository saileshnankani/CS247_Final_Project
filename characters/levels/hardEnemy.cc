#include "hardEnemy.h"
#include "../enemy.h"

HardEnemy::HardEnemy(int x, int y, char displayLetter, int health, int damageAmount ) : Enemy(x,y,health,damageAmount, displayLetter) {}; 