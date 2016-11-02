/***********************************************************************
 * tomato:
 *    Source code for tomato.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A timer
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include "stdio.h"
#include "tomato.h"
#include "settings.h"
using namespace std;

bool timer(int minutes);
void playAlarm();

int main()
{
  //initialize stuff
  settings config;
  config.loadConfig(CONFIG_FILE);
  bool success;
  while(true)
    {
      for (int i = 0; i < 4; i++)
	{
	  cout << "Time to work!\n";
	  playAlarm();
	  success = timer(config.workTime);
	  cout << "Breaktime!\n";
	  playAlarm();
	  success = timer(config.shortBreak);
	}
      cout << "Time for long break!\n";
      playAlarm();
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

void playAlarm()
{
  system("paplay 'sounds/alarm_tones/ringing.wav'");
}
