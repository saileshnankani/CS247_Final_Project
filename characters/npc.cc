#include "npc.h"
#include "player.h"
#include "../locations/tile.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

NPC::NPC(int x, int y, std::ifstream &npcFile) : Character{x, y}, conversation{npcFile} {}

NPC::Conversation::ConversationNode::ConversationNode(std::string response, std::vector<std::string> playerChoices, std::vector<ConversationNode> playerChoiceNodes)
    : response{response}, playerChoices{playerChoices}, playerChoiceNodes{playerChoiceNodes} {}

void NPC::Conversation::ConversationNode::print()
{
    std::cout << response << std::endl;
    for (int i = 0; i < playerChoices.size(); ++i)
    {
        std::cout << i << ". " << playerChoices.at(i) << std::endl;
    }
}

int NPC::Conversation::ConversationNode::getNumPlayerChoices()
{
    return playerChoices.size();
}

NPC::Conversation::ConversationNode *NPC::Conversation::ConversationNode::getChoiceNodePointer(int choice)
{
    return &(playerChoiceNodes[choice]);
}

NPC::Conversation::Conversation(std::ifstream &npcFile) : root{createNodeFromConversationTree(npcFile)}, current{&root} {}

NPC::Conversation::ConversationNode NPC::Conversation::createNodeFromConversationTree(std::ifstream &npcFile)
{
    std::string response;
    int numPlayerChoices;
    std::vector<std::string> playerChoices;
    std::vector<ConversationNode> playerChoiceNodes;

    std::getline(npcFile>>std::ws, response);
    npcFile >> numPlayerChoices;

    std::string newline;
    std::getline(npcFile, newline);

    // Record the player's choices
    for (int i = 0; i < numPlayerChoices; ++i)
    {
        std::string choice;
        std::getline(npcFile>>std::ws, choice);
        playerChoices.emplace_back(choice);
    }
    for (int j = 0; j < numPlayerChoices; ++j)
    {
        // maybe we can std::move the below
        playerChoiceNodes.emplace_back(createNodeFromConversationTree(npcFile));
    }
    // The arguments below can probably be std::move'd
    return ConversationNode{response, playerChoices, playerChoiceNodes};
}

void NPC::Conversation::startConversationFromCurrentNode()
{
    current->print();
    // If there are choices available, the conversation continues
    if (current->getNumPlayerChoices() > 0)
    {
        // Take in the player's choice as input
        int choice;
        std::cin >> choice;
        while (choice < 0 && choice >= current->getNumPlayerChoices())
        {
            std::cin >> choice;
        }
        // Go to the chosen child node in the conversation
        current = current->getChoiceNodePointer(choice);
        startConversationFromCurrentNode();
    }
    // If there are no choices to be made, the conversation ends.
    else
    {
        current = &root;
    }
}

void NPC::notify(Player &source)
{
    conversation.startConversationFromCurrentNode();
}

void NPC::notify(Enemy &source)
{
    conversation.startConversationFromCurrentNode();
}

void NPC::interactFromTileToTile(Tile &from, Tile &to, std::pair<int,int> targetCoords)
{
    // NPCs don't interact.
}