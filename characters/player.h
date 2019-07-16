#ifndef PLAYER_H_
#define PLAYER_H_

#include "combatant.h"
#include <memory>


class Player : public Combatant{
    
    public:        
        class Player_impl; 
        static std::unique_ptr<Player_impl> pimpl;

        void notify(Player &source);
        void notify(Enemy &source);
        int getDamage() override;
        void takeDamage(int damage);
        Player(int x, int y);
        ~Player();
        void interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords) override;
        int getHealth() const; 
        static bool isDead();
};

#endif