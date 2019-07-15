#ifndef PLAYER_H_
#define PLAYER_H_

#include "combatant.h"
#include <memory>


class Player : public Combatant{
    
    public:        
        class Player_impl; 
        static std::unique_ptr<Player_impl> pimpl;
        virtual void notify(Character &source);
        Player(int x, int y);
        ~Player();
        int getHealth() const; 
};

#endif