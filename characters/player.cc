#include "player.h"
#include "enemy.h"
#include "../locations/tile.h"
#include <memory>
#include<iostream>

std::unique_ptr<Player::Player_impl> Player::pimpl = std::make_unique<Player::Player_impl>();

class Player::Player_impl
{
    int health;
    int damageAmount;

public:
    Player_impl();
    int getDamage();
    void takeDamage(int damage);
    int getHealth() const;
};

Player::Player_impl::Player_impl() : health{100}, damageAmount{10} {}

int Player::Player_impl::getDamage()
{
    return damageAmount;
}

void Player::Player_impl::takeDamage(int damage)
{
    health -= damage;
    //TODO: Remove this print statement
    std::cout<<"You took "<<damage<<" damage!"<<std::endl;
    if (damage < 0)
    {
        // call location to remove the enemy
        // (probably) REMEMBER TO REMOVE THE ENEMY FROM ITS TILE
    }
}

Player::Player(int x, int y) : Combatant(x, y) {}

Player::~Player() {}

void Player::notify(Player &source)
{
    // Do nothing; players currently cannot be notified by a Player
}
void Player::notify(Enemy &source)
{
    takeDamage(source.getDamage());
}

int Player::Player_impl::getHealth() const{
    return health;
}


int Player::getDamage()
{
    pimpl->getDamage();
}

void Player::takeDamage(int damage)
{
    pimpl->takeDamage(damage);
}

void Player::interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords)
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

int Player::getHealth() const{
    return pimpl->getHealth();
}
