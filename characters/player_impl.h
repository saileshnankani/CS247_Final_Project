#include"player.h"

class Player::Player_impl
{
    int health;
    int damageAmount;

public:
    Player_impl();
    int getDamage();
    void takeDamage(int damage);
    int getHealth() const;
    bool isDead() const;
};