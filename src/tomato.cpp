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
#include <iomanip>
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
  
  while(true) //loop forever, or until user kills program
    {
      for (int i = 0; i < 3; i++) //loop thru 4 pomodoros
	{
	  cout << "**Time to work!**\n";
	  playAlarm();
	  waitForUser();
	  success = timer(config.workTime);
	  cout << "\033[A"; //move up
	  cout << "\033[10D"; //move left
	  cout << "\033[2K"; //erase line
	  cout << "**Breaktime!**\n";
	  playAlarm();
	  waitForUser();
	  success = timer(config.shortBreak);
	  cout << "\033[A";
	  cout << "\033[10D";
	  cout << "\033[2K";
	}
      //last pomodoro
      cout << "**Time to work!**\n";
      playAlarm();
      waitForUser();
      success = timer(config.workTime);
      //then long break
      cout << "\033[A";
      cout << "\033[10D";
      cout << "\033[2K";
      cout << "**Time for long break!**\n";
      playAlarm();
      waitForUser();
      success = timer(config.longBreak);
      //prepare to go back to work
      cout << "\033[A";
      cout << "\033[25D";
      cout << "\033[2K";
    }
  return 0;
}

bool timer(int minutes)
{
  int waitTime = 60*SECOND; //one minute
  cout << "Time left:";
  for (int i = 0; i < minutes; i++) //loop thru minutes
    {
      //display
      //display time in minutes
      cout << setw(3) << (minutes - i) << "m" << flush;
      //wait
      WAIT(waitTime); //wait one minute
      //move cursor back to write new time
      cout << "\033[4D";
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
  cout << "Start timer(y/n): ";
  cin >> a;
  while (a != 'y' && a != 'Y')
    {
      if (a == 'n' || a == 'N')
	{ //if no, ask if they want to quit
	  cout << "\033[A";
	  cout << "\033[18D";
	  cout << "\033[2K";
	  cout << "Would you like to quit(y/n): ";
	  cin >> a;
	  if (a == 'y' || a == 'Y')
	    exit(0); //if yes, quit application
	  cout << "\033[A";
	  cout << "\033[25D";
	  cout << "\033[2K";
	}
      else
	{
	  cout << "\033[A";
	  cout << "\033[18D";
	  cout << "\033[2K";
	  cout << "Please try again! ";
	}
      
      cout << "Start timer(y/n): ";
      cin >> a;
    }
  cout << "\033[A";
  cout << "\033[18D";
  cout << "\033[2K";
  //if yes exit loop and return
  return;
}
