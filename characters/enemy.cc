#include "enemy.h"

Enemy::Enemy(int x, int y, int health, int damageAmount) : Combatant(x,y), \
             health{health}, damageAmount{damageAmount} {}; 

Enemy::~Enemy() {};

void Enemy::takeDamage(int damage){
    health-=damage;
    if(damage<0){
        // call location to remove the enemy
    }
}

int Enemy::getHealth(){
    return health;
}

void Enemy::notify(Character &source){

}