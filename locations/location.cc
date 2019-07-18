#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <algorithm>
#include "location.h"
#include "../characters/enemy.h"
#include "../characters/npc.h"
#include "../characters/interviewer.h"
#include "../characters/player.h"
#include "tile.h"
#include "../characters/levels/level.h"
#include "../controller/action.h"

using namespace std;

//TODO: move this somewhere else as the responsibility of a view

Location::Location(string name, Level &level) : name{name}
{
    // Temporary variable that holds the most recent line read in from some file
    string line;

    ifstream map;
    ifstream mapCharacters;
    ifstream mapNPC;
    ifstream mapInterviewers;

    // It seems like the path is relative to where the executable is created,
    // not sure why.
    map.open("locations/" + name + ".in");
    mapCharacters.open("characters/" + name + "Characters.in");
    mapNPC.open("characters/" + name + "NPC.in");
    mapInterviewers.open("characters/" + name + "Interviewers.in");

    std::cout << map.is_open() << mapCharacters.is_open() << mapNPC.is_open() << mapInterviewers.is_open()<<std::endl;

    if (map.is_open() && mapCharacters.is_open() && mapNPC.is_open() && mapInterviewers.is_open())
    {
        while (getline(map, line))
        {
            std::vector<Tile> row;
            for (char c : line)
            {
                switch (c)
                {
                case 'X':
                    row.emplace_back(Tile::TileType::wall);
                    break;
                case 'O':
                    row.emplace_back(Tile::TileType::open);
                    break;
                // case 'G':
                //     enemies.push_back(make_unique<Enemy>());
                //     grid.push_back(new Tile(Tile::TileType::open));
                //     break;
                case 'T':
                    row.emplace_back(Tile::TileType::teleporter);
                    break;
                default:
                    // grid.push_back(new Tile(Tile::TileType::open));
                    break;
                }
            }
            grid.push_back(row);
        }

        char characterLetter;
        int pos_x;
        int pos_y;
        while (getline(mapCharacters, line))
        {
            stringstream ss(line);
            ss >> characterLetter >> pos_x >> pos_y;
            switch (characterLetter)
            {
            case 'P':
            {
                Player *newPlayer = new Player(pos_x, pos_y);
                player = std::unique_ptr<Player>(newPlayer);
                Tile &tile = tileAt(make_pair(pos_x, pos_y));
                tile.addOccupant(newPlayer);
                break;
            }
            case 'G':
            {
                Enemy *newEnemy = level.createEnemy(pos_x, pos_y);
                enemies.emplace_back(std::unique_ptr<Enemy>(newEnemy));
                Tile &tile = tileAt(make_pair(pos_x, pos_y));
                tile.addOccupant(newEnemy);
                break;
            }
            default:
                throw;
            }
        }

        // NPCs must have a conversation (even if it is only 1 node large)
        while (getline(mapNPC, line))
        {
            char npcLetter;
            int npc_pos_x;
            int npc_pos_y;
            stringstream ss(line);
            // TODO: Allow NPCs to take a single-letter name.
            ss >> npcLetter >> npc_pos_x >> npc_pos_y;
            NPC *newNPC = new NPC(npc_pos_x, npc_pos_y, mapNPC);
            nonPlayerCharacters.emplace_back(std::unique_ptr<NPC>(newNPC));
            Tile &tile = tileAt(make_pair(npc_pos_x, npc_pos_y));
            tile.addOccupant(newNPC);
        }

        // Interviewers must have an interview (even if it is only 1 node large)
        while (getline(mapInterviewers, line))
        {
            char interviewerLetter;
            int interviewer_pos_x;
            int interviewer_pos_y;
            stringstream ss(line);
            // TODO: Allow NPCs to take a single-letter name.
            ss >> interviewerLetter >> interviewer_pos_x >> interviewer_pos_y;
            Interviewer *newInterviewer = new Interviewer(interviewer_pos_x, interviewer_pos_y, mapInterviewers);
            interviewers.emplace_back(std::unique_ptr<Interviewer>(newInterviewer));
            Tile &tile = tileAt(make_pair(interviewer_pos_x, interviewer_pos_y));
            tile.addOccupant(newInterviewer);
        }
    }

    map.close();
    mapCharacters.close();
    mapNPC.close();
    mapInterviewers.close();
}

Tile &Location::tileAt(const std::pair<int, int> &coords)
{
    int x = coords.first;
    int y = coords.second;
    return grid.at(y).at(x);
}

// Returns true if the tile with the specified coordinates is in-bounds and not a wall
bool Location::isInteractiveTile(std::pair<int, int> coords)
{
    int x = coords.first;
    int y = coords.second;
    return (y >= 0 && y < grid.size() && x >= 0 && x < grid.at(y).size() && grid.at(y).at(x).getTileType() != Tile::wall);
}

void Location::executePlayerTurn(Action a)
{
    // calculateMove just takes input and returns a pair.  If desired we can move this user input to the controller.
    //std::pair<int, int> targetTileCoords = player->calculateMove();
    int x = player->getCoordinates().first;
    int y = player->getCoordinates().second;
    //TODO: move this somewhere else as the responsibility of a view
    // printGrid();

    switch (a)
    {
    case NONE:
        break;
    case UP:
        y -= 1;
        break;
    case DOWN:
        y += 1;
        break;
    case RIGHT:
        x += 1;
        break;
    case LEFT:
        x -= 1;
        break;
    case INVALID:
        cout << "Sorry, incorrect move" << endl;
        return;
        break;
    }

    std::pair<int, int> targetTileCoords(x, y);
    if (isInteractiveTile(targetTileCoords))
    {
        player->interactFromTileToTile(
            tileAt(player->getCoordinates()),
            tileAt(targetTileCoords),
            targetTileCoords);
    }
}

void Location::executeEnemyTurns()
{
    int playerX = player->getCoordinates().first;
    int playerY = player->getCoordinates().second;

    for (auto &enemy : enemies)
    {
        int enemyX = enemy->getCoordinates().first;
        int enemyY = enemy->getCoordinates().second;

        // Added a teeeeensy bit of pathfinding to the enemies;
        // Note that if the enemy is blocked in x-movement, it will move in y due to separate if-statements
        if (enemyX != playerX)
        {
            int enemyTargetX = (enemyX < playerX) ? enemyX + 1 : enemyX - 1; // Determine whether to try moving left or right
            std::pair<int, int> enemyTargetCoords(enemyTargetX, enemyY);

            if (isInteractiveTile(enemyTargetCoords))
            {
                enemy->interactFromTileToTile(
                    tileAt(enemy->getCoordinates()),
                    tileAt(enemyTargetCoords),
                    enemyTargetCoords);
                continue;
            }
        }
        if (enemyY != playerY)
        {
            int enemyTargetY = (enemyY < playerY) ? enemyY + 1 : enemyY - 1; // Determine whether to try moving down or up
            std::pair<int, int> enemyTargetCoords(enemyX, enemyTargetY);

            if (isInteractiveTile(enemyTargetCoords))
            {
                enemy->interactFromTileToTile(
                    tileAt(enemy->getCoordinates()),
                    tileAt(enemyTargetCoords),
                    enemyTargetCoords);
                continue;
            }
        }
    }
}

void Location::updateState(Action a)
{
    executePlayerTurn(a);
    executeEnemyTurns();
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&](auto const &ePtr) -> bool { 
        if(ePtr->isDead()){
        this->tileAt(ePtr->getCoordinates()).evictOccupant();
        return true;
        }
        else{
        return false; } }), enemies.end());
}

std::vector<std::vector<Tile>> Location::getGrid()
{
    return grid;
}

int Location::getPlayerHealth() const
{
    return player->getHealth();
}

bool Location::isNextTileTeleporter(Action a)
{
    int x = player->getCoordinates().first;
    int y = player->getCoordinates().second;

    switch (a)
    {
    case NONE:
        break;
    case UP:
        y -= 1;
        break;
    case DOWN:
        y += 1;
        break;
    case RIGHT:
        x += 1;
        break;
    case LEFT:
        x -= 1;
        break;
    case INVALID:
        cout << "Sorry, incorrect move" << endl;
        return false;
        break;
    }

    std::pair<int, int> targetTileCoords(x, y);
    if (isInteractiveTile(targetTileCoords))
    {
        if(tileAt(targetTileCoords).getTileType()==tileAt(targetTileCoords).teleporter){
            return true;
        }
        else{
            return false;
        }
    }
    return false;

}

string Location::getName(){
    return name;
}
