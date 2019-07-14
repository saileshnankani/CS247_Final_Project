#ifndef __STANDARD___H__
#define __STANDARD___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>

class Maze;

class Standard: public View{
  std::vector<std::vector<char>> display;
  std::ostream& out;

  Maze& maze;
 public:
  Standard(int row, int col, Maze& m);
  void update(const std::string& msg) override;
  void updateView(Location*) override;
};
#endif
