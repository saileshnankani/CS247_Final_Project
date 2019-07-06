#include"character.h"

class Tile{
        Character& occupant;
        bool isOccupied;
        char c;   // so this indicates whether it is 
    public: 
        Tile();
        ~Tile();
};  