/**
 * This is the abstract base case for all the characters in the game. The 
 * concrete floors that are dervied from this class are all the Enemies, 
 * the Player, and all NPCs 
 */

#include "character.h"
#include "../locations/tile.h"
#include<utility>

//TODO: Make all characters take a display letter, and change this MIL
Character::Character(int x, int y, char displayLetter) : coordinates(x,y), displayLetter{displayLetter} {}
Character::~Character() {}

void Character::setCoordinates(std::pair<int, int> newCoordinates){
    coordinates = newCoordinates;
}

char Character::getDisplayLetter() const {
    return displayLetter;
}

std::pair<int,int> Character::getCoordinates(){
    return coordinates;
}