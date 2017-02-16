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

class display
{
 public:
  display();
  void displayMessage(std::string message);
  ~display();
};


#endif // TOMATO_DISPLAY_H
