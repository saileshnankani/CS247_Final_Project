#ifndef ENEMY_H_
#define ENEMY_H_

#include "combatant.h"

class Enemy : public Combatant{
        int health;
        int damageAmount;
    public:
        Enemy(int x, int y, int health, int damageAmount);

        void notify(Player &source);
        void notify(Enemy &source);
        virtual ~Enemy();
        virtual void takeDamage(int) override;
        virtual int getHealth(); 
        int getDamage() override;
        void interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords) override;
};

#endif