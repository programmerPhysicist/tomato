/***********************************************************************
 * display.h:
 *    display class
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Displays the timer and messages for pomodoro class
 ************************************************************************/
#ifndef TOMATO_DISPLAY_H
#define TOMATO_DISPLAY_H

#include <string>
#include "ncurses.h"

class display
{
 public:
  //constructor
  display();
  //member methods
  void displayMessage(std::string message);  //put message out to screen
  char getUserInput(std::string message); //get user input
  //destructor
  ~display();
 private:
  WINDOW *bottomBar;
  WINDOW *topBar;
  WINDOW *timerWin;
};


#endif // TOMATO_DISPLAY_H
