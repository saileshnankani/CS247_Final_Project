#include "enemy.h"
#include "player.h"
#include "../locations/tile.h"
#include<iostream>

Enemy::Enemy(int x, int y, int health, int damageAmount) : Combatant(x, y),
                                                           health{health}, damageAmount{damageAmount} {};

Enemy::~Enemy(){};

void Enemy::takeDamage(int damage)
{
    health -= damage;
    //TODO: Remove this print statement
    std::cout<<"The enemy took "<<damage<<" damage!"<<std::endl;
    if (damage < 0)
    {
        // call location to remove the enemy
    }
}

int Enemy::getHealth()
{
    return health;
}

int Enemy::getDamage()
{
    return damageAmount;
}

void Enemy::notify(Player &source)
{
    takeDamage(source.getDamage());
}
void Enemy::notify(Enemy &source)
{
    // Do nothing; enemies should not attack one another.
}

void Enemy::interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords)
{
    if (to.isOccupied())
    {
        to.notifyOccupant(*this); // Notifies the occupant of 'to' that *this is interacting with it.
    }
    else
    {
        from.evictOccupant();
        to.addOccupant(this);
        setCoordinates(targetCoords);
    }
}