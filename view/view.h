#ifndef ___VIEW___H__
#define ___VIEW___H__

#include "../locations/location.h"

class View{
    protected:
        
    public:
        View(Location* currentLocation);
        virtual ~View();
        virtual void updateView() = 0;
        Location* currentLocation;
};

#endif