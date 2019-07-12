#include "tile.h"

Tile::Tile(TileType type = open) : type{type}, occupant{nullptr}{}

Tile::~Tile() {}

bool Tile::isOccupied()
{
    return occupant != nullptr;
}

void Tile::addOccupant(Character *c)
{
    occupant = c;
}
void Tile::evictOccupant()
{
    occupant = nullptr;
}
void Tile::notifyOccupant(Character &source)
{
    occupant->notify(source);
}

