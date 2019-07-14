#include "graphic.h"

Graphic::Graphic(Location *currentLocation) : View{currentLocation} {

    maxWidth = 0;

    height = currentLocation->getGrid().size();
    for(int i=0; i<currentLocation->getGrid().size(); i++){
        maxWidth = currentLocation->getGrid().at(i).size() > maxWidth ? currentLocation->getGrid().at(i).size() : maxWidth;
    }

    window = new Xwindow{squareSize*maxWidth + pad*(maxWidth+1),
                        squareSize*height + pad*(height+1)};
};

Graphic::~Graphic() {
    delete window;
};

void Graphic::updateView(){
    window->fillRectangle(0, 0, squareSize*maxWidth + pad*(maxWidth+1),
                        squareSize*height + pad*(height+1));

    int x = pad, y = pad;
    char tile;

    for(const auto &row : currentLocation->getGrid())
    {
        for(const auto &tile : row){
            tile = tile.calculateDisplayedLetter();

            int colour = 1;

            if (c == 'O') {
                // Open tiles are white.
                colour = 0;
            }
            else if(c == 'A'){
                colour = 4;
            }
            else if (c == 'T') {
                // Teleporters are red
                colour = 2;
            }
            
            window->fillRectangle(x, y, squareSize, squareSize, colour);
            x += squareSize + pad;
        }

        y += squareSize + pad;
        x = pad;
    }
    
}