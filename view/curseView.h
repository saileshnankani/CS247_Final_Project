#ifndef __CURSES_VIEW___H__
#define __CURSES_VIEW___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>


class Curses: public View{
 public:
  Curses(Location* currentLocation);
  ~Curses();
  void updateView() override;
};
#endif
