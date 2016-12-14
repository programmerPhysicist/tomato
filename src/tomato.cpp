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
#include <curses.h>
#include "stdio.h"
#include "tomato.h"
#include "settings.h"
using namespace std;

bool timer(int minutes);
void playAlarm();
void waitForUser();

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
	  waitForUser();
	  success = timer(config.workTime);
	  cout << endl << "\t**Breaktime!**\n";
	  playAlarm();
	  waitForUser();
	  success = timer(config.shortBreak);
	}
      //then long break
      cout << "\t**Time for long break!**\n";
      playAlarm();
      waitForUser();
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
  #ifdef LINUX_UNIX
  //play ringing sound
  system("paplay 'sounds/alarm_tones/ringing.wav'");
  #endif
}

void waitForUser()
{ //wait for user to start timer
  char a;
  do
    {
      cout << "\tStart timer(y/n): ";
      cin >> a;
      if (a == 'n' || a == 'N')
	{ //if no, ask if they want to quit
	  cout << "\tWould you like to quit(y/n): ";
	  cin >> a;
	  if (a == 'y' || a == 'Y')
	    exit(0); //if yes, quit application
	}
    }
  while (a != 'y' && a != 'Y');
  //if yes exit loop and return
  return;
}
