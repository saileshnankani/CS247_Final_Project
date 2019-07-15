#include "curseView.h"
#include <ncurses.h>

Curses::Curses(Location *currentLocation) : View(currentLocation)
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  int height = currentLocation->getGrid().size();


  wmove(stdscr, height+3,0);
  waddstr(stdscr,"                                              ");
  wmove(stdscr, height+3,0);

  int iterRow = 0, iterCol = 0;
  for (const auto &row : currentLocation->getGrid())
  {
    for (const auto &tile : row)
    {
      mvwaddch(stdscr, iterRow, iterCol, tile.calculateDisplayedLetter());
      iterCol++;
    }
    mvwaddch(stdscr, iterRow, iterCol, '\n');
    iterRow++;
    iterCol = 0;
  }
}

void Curses::updateView()
{

  int height = currentLocation->getGrid().size();

  wmove(stdscr, height+3,0);
  waddstr(stdscr,"                                              ");
  wmove(stdscr, height+3,0);

  int iterRow = 0, iterCol = 0;
  for (const auto &row : currentLocation->getGrid())
  {
    for (const auto &tile : row)
    {
      mvwaddch(stdscr, iterRow, iterCol, tile.calculateDisplayedLetter());
      iterCol++;
    }
    mvwaddch(stdscr, iterRow, iterCol, '\n');
    iterRow++;
    iterCol = 0;
  }

  refresh();
}

// void Curses::update(const std::string& msg){
//   wmove(stdscr, height+3,0);
//   waddstr(stdscr,"                                              ");
//   wmove(stdscr, height+3,0);
//   waddstr(stdscr,msg.c_str());
// }

// void Curses::update(int row, int col, State state){
//   mvwaddch(stdscr,row+1,col+1,displayMap[state]);
// }

Curses::~Curses() { endwin(); }
