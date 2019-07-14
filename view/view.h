#ifndef ___VIEW___H__
#define ___VIEW___H__

#include <string>

class View{
 public:
  virtual ~View() = default;
  virtual void update(const std::string& msg) = 0;
  virtual void updateView(Location*) = 0;
};

#endif
