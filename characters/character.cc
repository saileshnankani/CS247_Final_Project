/**
 * This is the abstract base case for all the characters in the game. The 
 * concrete floors that are dervied from this class are all the Enemies, 
 * the Player, and all NPCs 
 */

#include "character.h"

Character::Character(int x, int y) : coordinates(x,y) {}
Character::~Character() {}

void Character::notify(Character &source){

}