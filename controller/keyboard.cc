#include "keyboard.h"
#include <string>

Keyboard::Keyboard(std::istream&in): in{in} {
  theMap["w"] = Action::UP;
  theMap["d"] = Action::RIGHT;
  theMap["s"] = Action::DOWN;
  theMap["a"] = Action::LEFT;
  theMap["q"] = Action::QUIT;
  theMap["y"] = Action::YES;
  theMap["n"] = Action::NO;
}

Action Keyboard::action(){
  std::string buffer;
  in >> buffer;
  if ( in ){
    if ( buffer == "remap" ){
      std::string oldCmd, newCmd;
      in >> oldCmd >> newCmd;
      return Action::NONE;
    } else {
      return theMap[buffer];
    }
  }
  return Action::INVALID;
}
