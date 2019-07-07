#include "combatant.h"

Combatant::Combatant() : health{100} {}
Combatant::~Combatant(){}
void Combatant::takeDamage(int damage){
    health-=damage;
    if(damage<0){
        Combatant::~Combatant();
    }
}
int Combatant::getHealth(){
    return health;
}

