#include "standard.h"
#include "../locations/location.h"

Standard::Standard(int rows, int cols, Maze& m): maze{m}, out{std::cout}{
  displayMap[EMPTY] = ' '; //  setting display char mapping
  displayMap[WALL] = '#';
  displayMap[GOAL] = '*';
  displayMap[PLAYER] = '@';

  std::vector<char> row(cols+2, ' '); // a row with col+2 chars " "

  // make rows+2 rows
  for (int i = 0; i < rows+2; ++i ){
    display.emplace_back(row);
  }

  for (int i = 0; i < cols + 2; ++i){ 
    display[0][i] = displayMap[WALL]; // first row wall
    display[rows+1][i] =  displayMap[WALL]; // last row wall
  }
  for (int i = 0; i < rows + 2; ++i){
    display[i][0] =  displayMap[WALL]; // first col wall
    display[i][cols+1] =  displayMap[WALL]; // last col wall
  }
  // just drawn the boundary, rest of it will come when the random walls are generated
  // updated with update(int int state) function
}

void Standard::updateView(Location* location){
  location->printGrid();
  for(const auto &row : location->getMap()){
    for(const auto &tile : row){
      std::cout<<tile.calculateDisplayedLetter()<<" ";
    }
    std::cout<<"\n"<<std::endl;
 }
}

void Standard::update(const std::string& msg){
  out << msg << std::endl;
}

void Standard::update(int row, int col, State state){
  display[row+1][col+1] = displayMap[state];
}
