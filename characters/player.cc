#include "player.h"

Player::Player(int x, int y) : Combatant(x,y) {}

Player::~Player() {}

class Player::Player_impl{
    int health;
    public:
        Player_impl();
};


Player::Player_impl::Player_impl() : health{100} {}

void Player::notify(Character &source){

}