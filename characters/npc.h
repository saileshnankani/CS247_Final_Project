#ifndef NPC_H_
#define NPC_H_

#include <string>
#include "character.h"

class NPC : public Character{
        std::vector<std::string> conversation;
    protected: 
        int health;
    public:
        NPC();
        virtual ~NPC();
        void startConversation();

};

#endif