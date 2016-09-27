/***********************************************************************
 * tomato:
 *    Source code for tomato.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A timer
 ************************************************************************/
#include <iostream>
#include "tomato.h"
#include "settings.h"
using namespace std;

bool timer(int minutes);

int main()
{
  //get time
  //time_t initialTime = time(NULL); //get current time

  //initialize stuff
  //time_t now;
  settings config;
  config.loadConfig(CONFIG_FILE);
  bool success;
  while(true)
    {
      for (int i = 0; i < 4; i++)
	{
	  cout << "Time to work!\a\n";
	  success = timer(config.workTime);
	  cout << "Breaktime!\a\n";
	  success = timer(config.shortBreak);
	}
      cout << "Time for long break!\a\n";
      success = timer(config.longBreak);
    }
  return 0;
}

bool timer(int minutes)
{
  int waitTime = 60*SECOND;
  for (int i = 0; i < minutes; i++)
    {
      //display
      cout << endl;
      cout << (minutes - i) << " minutes remaining\n";
      //wait
      WAIT(waitTime);
    }
  return true;
}
