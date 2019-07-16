#ifndef __GRAPHIC_VIEW___H__
#define __GRAPHIC_VIEW___H__

#include "view.h"
#include "window.h"

class Graphic : public View
{
        Xwindow *window;
        int maxWidth;
        int height;
        const int squareSize = 25;
        const int pad = 2;

    public:
        Graphic(Location *currentLocation);
        ~Graphic();
        void updateView() override;
};
#endif
