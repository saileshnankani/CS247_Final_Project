#include "easyLevel.h"
#include "easyEnemy.h"

EasyLevel::EasyLevel() {};

EasyEnemy* EasyLevel::createEnemy(int x, int y){
    return new EasyEnemy(x,y);
}