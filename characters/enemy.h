#ifndef ENEMY_H_
#define ENEMY_H_

#include "combatant.h"

class Enemy : public Combatant{
        int health;
        int damageAmount;
    public:
        Enemy(int x, int y, int health, int damageAmount, char displayLetter);

        void notify(Player &source) override;
        void notify(Enemy &source) override;
        virtual ~Enemy();
        virtual void takeDamage(int) override;
        virtual int getHealth() const; 
        bool isDead() const;
        int getDamage() override;
        void interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords) override;
};

#endif