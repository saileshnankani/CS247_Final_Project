#include "tile.h"

Tile::Tile(enum tileType = wall, Character* occupant = nullptr) : tileType{tileType}, occupant{occupant} {
    if(occupant!=nullptr){
        isOccupied = true;
    }

}

bool Tile::isOccupied()
{
    return occupant != nullptr;
}

void Tile::addOccupant(Character &c)
{
    occupant = &c;
}
void Tile::evictOccupant()
{
    occupant = nullptr;
}
void Tile::notifyOccupant(Character &source)
{
    occupant->notify(source);
}

