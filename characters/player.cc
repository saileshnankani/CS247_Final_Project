#include "player.h"
#include "enemy.h"
#include "../locations/tile.h"
#include <memory>
#include<iostream>
#include"player_impl.h"

std::unique_ptr<Player::Player_impl> Player::pimpl = std::make_unique<Player::Player_impl>();

// We use P for player
Player::Player(int x, int y) : Combatant(x, y, 'P') {}

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

bool Player::isDead(){
    return pimpl->isDead();
}
