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
  wmove(topBar, 0,0); //move curser back to begining
  wrefresh(topBar); //refresh
  whline(topBar, '_',80); //draw line for bottom
  wprintw(topBar,message.c_str()); //print message
  wrefresh(topBar); //refresh
}

display::display()
{
  //initialize window
  initscr(); //start curses mode
  cbreak(); //Disable line buffering
  curs_set(0); //Don't show curser
  refresh(); //Now refresh screen

  //setup bottom bar
  bottomBar = newwin(2, 80, 22, 0); //create new window
  whline(bottomBar, '_', 80); //draw line
  wrefresh(bottomBar); //refresh

  //setup top bar
  topBar = newwin(0, 80, 0, 0); //create new window
  wattron(topBar, A_UNDERLINE); //text is to be underlined
  
}

display::~display()
{
  endwin();
}
