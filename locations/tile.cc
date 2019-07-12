#include "tile.h"

Tile::Tile(TileType type = open) : type{type}, occupant{nullptr}{}

Tile::~Tile() {}

Tile::TileType Tile::getTileType() const{
    return type;
}

bool Tile::isOccupied() const
{
    return occupant != nullptr;
}

char Tile::calculateDisplayedLetter() const{
    if(isOccupied()){
        return occupant->getDisplayLetter();
    } else {
        switch (type){
            case wall:
                return 'X';
            case open:
                return 'O';
            case teleporter:
                return 'T';
            default:
                throw;
        }

    }
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

