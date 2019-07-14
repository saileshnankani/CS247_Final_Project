/**
 * This is the abstract base case for all the "floors" in the game. The 
 * concrete floors that are dervied from this class are MC, Tatham Centre,
 * and California.
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include<vector>
#include<string>
#include<memory>
#include "../characters/player.h"
#include "../characters/combatant.h"
#include "tile.h"
#include "../characters/levels/level.h"
#include "../controller/action.h"

class Location
{
private:
    // A location has all of the characters within it.
    // These are made separate since the operations involving these are usually different.
    std::unique_ptr<Player> player;
    //std::vector<std::unique_ptr<NPC>> nonPlayerCharacters; // I split up the array 'characters' because NPCs don't take a turn, as we see at the bottom of this class
    std::vector<std::unique_ptr<Enemy>> enemies;

    std::vector<std::vector<Tile>> grid;
    // Doesn't really matter how grid is indexed, that is, x first VS. y first; don't get hung up on it
    // Nor does it matter whether y increases downwards VS. upwards - the math is a tiny bit different for each case.
    // Note that in computer graphics, the origin is usually in the top left (top left is (0,0))
    /*
    Following this convention, and y-first addressing allows us to easily visualize and print the grids
        e.x., the following grid that follows the above convention is stored in the same orientation it will be displayed:
        (in the same notation as the maze from A2)
        {{X, X, X, S},
         {X, X, O, P},
         {T, O, O, O},
         {X, O, O, X}}
     */

    // Helper to make accessing the grid friendlier
    Tile &tileAt(const std::pair<int, int> &coords);

    // Returns true if the tile with the specified coordinates is in-bounds and not a wall
    bool isInteractiveTile(std::pair<int, int> coords);

    // Return true if the coordinate is out of the current location's map area
    bool isOutofBounds(std::pair<int, int> coords);

    std::string name;

public:
    //TODO: move this somewhere else as the responsibility of a view
    void printGrid();

    // Currently only executes the Player and Enemys' turns. TODO immediately next.
    void updateState(Action a);

    Location(std::string, Level&);
    ~Location();
    const std::vector<std::vector<Tile>> getMap();

    // Runs the player's turn
    void executePlayerTurn(Action a);

    // Runs the enemy's turn
    void executeEnemyTurns();
};

#endif