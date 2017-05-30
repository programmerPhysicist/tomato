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
  topBar = newwin(1, 7, 0, 0); //create new window
  wattron(topBar, COLOR_PAIR(1));
  wprintw(topBar, "Tomato ");
  wrefresh(topBar);

  //setup timer window
  timerWin = newwin(1, 1, 0, 7);
  wattron(timerWin,COLOR_PAIR(1));
  wbkgd(timerWin, COLOR_PAIR(1));
  //setClock("00:00"); //draw clock
  wrefresh(timerWin); //refresh timer window
  
  //setup bottom bar
  bottomBar = newwin(1, 72, 0, 8); //create new window
  wattron(bottomBar, COLOR_PAIR(1));
  wbkgd(bottomBar, COLOR_PAIR(1));
  keypad(bottomBar, TRUE); //setup to receive input from user
  wrefresh(bottomBar); //refresh
}

void display::displayMessage(string message)
{
  //do some other necessary stuff
  int length = message.length(); //get length of message
  
  wmove(bottomBar, 0, 0); //move curser back to beginning
  
  //wmove(topBar, 0, 40 - length/2 - 1); //move cursor to center text
  wprintw(bottomBar, message.c_str()); //print message
  wrefresh(bottomBar); //refresh
}

void display::setClock(string time)
{
  wmove(bottomBar, 0, 0); //move curser to start of line
  wclrtoeol(bottomBar);
  wprintw(bottomBar, time.c_str()); //print
  wrefresh(bottomBar); //refresh
}

char display::getUserInput(string message)
{
  curs_set(2); //make cursor visible
  char a;
  //wmove(bottomBar, 0, 0); //move below line
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
