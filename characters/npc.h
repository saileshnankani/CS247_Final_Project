#ifndef NPC_H_
#define NPC_H_

#include <vector>
#include <fstream>
#include <string>
#include "character.h"

class Player;
class Enemy;

class NPC : public Character
{
    class Conversation
    {
        class ConversationNode
        {
            std::string response;
            std::vector<std::string> playerChoices;
            std::vector<ConversationNode> playerChoiceNodes;

        public:
            // Will probably need to depend on the view; maybe use streams here?
            // Just the basic idea of printing the NPC's response first, then the player's choices
            void print();
            int getNumPlayerChoices();
            ConversationNode *getChoiceNodePointer(int choice);

            ConversationNode(std::string response, std::vector<std::string> playerChoices, std::vector<ConversationNode> playerChoiceNodes);
        };
        ConversationNode root;
        ConversationNode *current;

        ConversationNode createNodeFromConversationTree(std::ifstream &npcFile);

    public:
        // Should be a passed reference so that npcs can use the same stream,
        // and we can read all NPCs in a map from the same file as a result
        // (If we don't do this, and we reopen the file in each new NPC conversation,
        // the stream will take input starting from the *top* of the file, but we
        // want to be able to take NPCs conversations as input
        // in an order controlled by the thing that makes them)
        // We assume this stream is already open.
        Conversation(std::ifstream &npcFile);
        void startConversationFromCurrentNode();
    };

    Conversation conversation;

public:
    NPC(int x, int y, std::ifstream &npcFile, char displayLetter);

    void notify(Player &source);
    void notify(Enemy &source);
    void interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords) override;
};

#endif