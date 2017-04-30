/***********************************************************************
 * display.cpp:
 *    Source code for display.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Display the timer and messages for pomodoro class.
 ************************************************************************/
#include <iostream>
#include "display.h"
#include "ncurses.h"
using namespace std;

display::display()
{
  //initialize window
  initscr(); //start curses mode
  cbreak(); //Disable line buffering
  curs_set(0); //Don't show curser
  noecho(); //Don't echo
  refresh(); //Now refresh screen

  //setup top bar
  topBar = newwin(1, 20, 0, 0); //create new window
  //box(topBar, 0, 0);

  //setup timer window
  timerWin = newwin(3, 20, 1, 0);
  box(timerWin, 0, 0); //drawoutline of window
  setClock("00:00"); //draw clock
  wrefresh(timerWin); //refresh timer window
  
  //setup bottom bar
  bottomBar = newwin(1, 30, 4, 0); //create new window
  keypad(bottomBar, TRUE); //setup to receive input from user
  wrefresh(bottomBar); //refresh
}

void display::displayMessage(string message)
{
  //do some other necessary stuff
  int length = message.length(); //get length of message
  
  wmove(topBar, 0, 0); //move curser back to beginning
  
  //wmove(topBar, 0, 40 - length/2 - 1); //move cursor to center text
  wprintw(topBar,message.c_str()); //print message
  wrefresh(topBar); //refresh
}

void display::setClock(string time)
{
  wmove(timerWin, 1, 1); //move curser to start of line
  wprintw(timerWin, "     "); //erase line
  wmove(timerWin, 1, 1); //move curser back
  wprintw(timerWin, time.c_str()); //print
  wrefresh(timerWin); //refresh
}

char display::getUserInput(string message)
{
  curs_set(2); //make cursor visible
  char a;
  wmove(bottomBar, 0, 0); //move below line
  wclrtoeol(bottomBar); //erase line
  wprintw(bottomBar, message.c_str()); //print prompt
  wrefresh(bottomBar); //refresh
  a = wgetch(bottomBar); //get message
  curs_set(0); //make cursor invisible again
  return a; //return char
}

display::~display()
{
  endwin(); //end ncurses mode
}
