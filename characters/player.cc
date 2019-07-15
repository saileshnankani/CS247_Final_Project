#include "player.h"
#include "enemy.h"
#include "../locations/tile.h"

class Player::Player_impl
{
    int health;
    int damageAmount;

public:
    Player_impl();
    int getDamage();
    void takeDamage(int damage);
};

Player::Player_impl::Player_impl() : health{100}, damageAmount{10} {}

int Player::Player_impl::getDamage()
{
    return damageAmount;
}

void Player::Player_impl::takeDamage(int damage)
{
    health -= damage;
    if (damage < 0)
    {
        // call location to remove the enemy
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
    source.getDamage();
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
