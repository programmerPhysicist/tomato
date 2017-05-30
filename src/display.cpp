/***********************************************************************
 * display.cpp:
 *    Source code for display.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Display the timer and messages for pomodoro class.
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
#include "display.h"
#include "ncurses.h"
using namespace std;

display::display()
{
  //initialize window
  initscr(); //start curses mode
  if(has_colors() == FALSE) //check to see if terminal supports colors
    {
      endwin();
      printf("Tomato does not support your terminal!");
      exit(1);
    }
  start_color(); //turn color mode on
  init_pair(1, COLOR_BLACK, COLOR_GREEN); //set colors
  cbreak(); //Disable line buffering
  curs_set(0); //Don't show curser
  noecho(); //Don't echo
  refresh(); //Now refresh screen

  //setup top bar
  /*topBar = newwin(1, 2, 0, 0); //create new window
  wattron(topBar, COLOR_PAIR(1));
  wprintw(topBar, ">> ");
  wrefresh(topBar);

  //setup timer window
  /*timerWin = newwin(1, 1, 0, 7);
  wattron(timerWin,COLOR_PAIR(1));
  wbkgd(timerWin, COLOR_PAIR(1));
  //setClock("00:00"); //draw clock
  wrefresh(timerWin); //refresh timer window
  */
  //setup message bar
  msgBar = newwin(1, 40, 0, 0); //create new window
  wattron(msgBar, COLOR_PAIR(1));
  wbkgd(msgBar, COLOR_PAIR(1));
  keypad(msgBar, TRUE); //setup to receive input from user
  wrefresh(msgBar); //refresh
}

void display::displayMessage(string message)
{
  //do some other necessary stuff
  int length = message.length(); //get length of message
  
  wmove(msgBar, 0, 0); //move curser back to beginning
  
  //wmove(topBar, 0, 40 - length/2 - 1); //move cursor to center text
  wprintw(msgBar, message.c_str()); //print message
  wrefresh(msgBar); //refresh
}

void display::setClock(string time)
{
  wmove(msgBar, 0, 0); //move curser to start of line
  wclrtoeol(msgBar);
  wprintw(msgBar, time.c_str()); //print
  wrefresh(msgBar); //refresh
}

char display::getUserInput(string message)
{
  curs_set(2); //make cursor visible
  char a;
  //wmove(bottomBar, 0, 0); //move below line
  wprintw(msgBar, message.c_str()); //print prompt
  wrefresh(msgBar); //refresh
  a = wgetch(msgBar); //get message
  curs_set(0); //make cursor invisible again
  return a; //return char
}

display::~display()
{
  endwin(); //end ncurses mode
}
