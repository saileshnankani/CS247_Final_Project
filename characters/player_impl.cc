#include "player.h"
#include "player_impl.h"
#include <iostream>

Player::Player_impl::Player_impl() : health{100}, damageAmount{10} {}

int Player::Player_impl::getDamage()
{
    return damageAmount;
}

void Player::Player_impl::takeDamage(int damage)
{
    health -= damage;
    //TODO: Remove this print statement
    std::cout << "You took " << damage << " damage!" << std::endl;
}

bool Player::Player_impl::isDead() const
{
    return health <= 0;
}