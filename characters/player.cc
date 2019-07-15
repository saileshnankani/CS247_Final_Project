#include "player.h"
#include <memory>

std::unique_ptr<Player::Player_impl> Player::pimpl = std::make_unique<Player::Player_impl>();

Player::Player(int x, int y) : Combatant(x,y) {}

Player::~Player() {}

class Player::Player_impl{
    int health;
    public:
        Player_impl();
        int getHealth() const;
};

int Player::Player_impl::getHealth() const{
    return health;
}


Player::Player_impl::Player_impl() : health{100} {}

void Player::notify(Character &source){

}

int Player::getHealth() const{
    return pimpl->getHealth();
}