#ifndef __STANDARD___H__
#define __STANDARD___H__

#include "view.h"


class Standard : public View {
  public:
    Standard(Location* currentLocation);
    virtual void updateView() override;
    Location* returnCurrentLocation;
};
#endif
