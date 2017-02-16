/***********************************************************************
 * display.cpp:
 *    Source code for display.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Display the timer and messages for pomodoro class.
 ************************************************************************/
#include "display.h"
#include "ncurses.h"
using namespace std;

void display::displayMessage(string message)
{
  move(0,0);
  clrtoeol();
  printw(message.c_str());
  refresh();
}

display::display()
{
  //initialize window
  initscr(); //start curses mode
  cbreak(); //Disable line buffering
  refresh(); //Now refresh screen

  //setup bottom bar
  WINDOW *bar = newwin(2, 80, 22, 0); //create new window
  whline(bar, '_', 80); //draw line
  wrefresh(bar); //refresh

  //setup top bar
  WINDOW *bar2 = newwin(2, 80, 1, 0); //create new window
  whline(bar2, '_', 80);
  wrefresh(bar2);
  getch();
}

display::~display()
{
  endwin();
}
