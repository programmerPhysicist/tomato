/***********************************************************************
 * tomato:
 *    Source code for tomato.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A Pomodoro timer command line application
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
  settings config; //initialize settings object
  config.loadConfig(CONFIG_FILE); //load settings into config
  bool success;
  while(true) //loop forever, or until user
    {
      for (int i = 0; i < 4; i++) //loop thru 4 pomodoros
	{
	  cout << endl << "\t**Time to work!**\n";
	  playAlarm();
	  success = timer(config.workTime);
	  cout << endl << "\t**Breaktime!**\n";
	  playAlarm();
	  success = timer(config.shortBreak);
	}
      //then long break
      cout << "\t**Time for long break!**\n";
      playAlarm();
      success = timer(config.longBreak);
    }
  return 0;
}

bool timer(int minutes)
{
  int waitTime = 60*SECOND; //one minute
  for (int i = 0; i < minutes; i++) //loop thru minutes
    {
      //display
      cout << endl;
      cout << "\tTime left:" << (minutes - i) << "m" << endl;
      //wait
      WAIT(waitTime); //wait one minute
    }
  return true;
}

void playAlarm()
{
  //play ringing sound
  system("paplay 'sounds/alarm_tones/ringing.wav'");
}
