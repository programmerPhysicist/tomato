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
#include <string>
#include <ncurses.h>
#include "stdio.h"
#include "tomato.h"
#include "settings.h"
using namespace std;

int main()
{
  //initialize stuff
  //settings config; //initialize settings object
  pomodoro instance;
  
  //displayMessage("Testing!");
  
  while(true) //loop forever, or until user
    {
      for (int i = 0; i < 3; i++) //loop thru 4 pomodoros
	{
	  //work
	  instance.Display.displayMessage("**Time to work!**");
	  instance.playAlarm();
	  //waitForUser();
	  //timer(config.workTime);
	  //break
	  return 0;
	  instance.Display.displayMessage("**Breaktime!**");
	  instance.playAlarm();
	  instance.waitForUser();
	  //instance.timer(config.shortBreak);
	}
      //do work
      instance.Display.displayMessage("**Time to work!**");
      instance.playAlarm();
      instance.waitForUser();
      //instance.timer(config.workTime);
      //then long break
      instance.Display.displayMessage("**Time for long break!**");
      instance.playAlarm();
      instance.waitForUser();
      //instance.timer(config.longBreak);
      }
  return 0;
}

pomodoro::pomodoro()
{
  //initialize configuration object
  config.loadConfig(CONFIG_FILE); //load settings into config
  //display constructor called automatically
}

void pomodoro::timer(int minutes)
{
  int waitTime = 60*SECOND; //one minute
  for (int i = 0; i < minutes; i++) //loop thru minutes
    {
      //display
      cout << endl;
      Display.displayMessage("Time left: "+itoa(minutes-i)+"m");
      //wait
      WAIT(waitTime); //wait one minute
    }
}

void pomodoro::playAlarm()
{
  #ifdef LINUX_UNIX
  //play ringing sound
  system("paplay 'sounds/alarm_tones/ringing.wav'");
  #endif
}

void pomodoro::waitForUser()
{ //wait for user to start timer
  char a;
  do
    {
      cout << "\nStart timer(y/n): ";
      cin >> a;
      if (a == 'n' || a == 'N')
	{ //if no, ask if they want to quit
	  cout << "Would you like to quit(y/n): ";
	  cin >> a;
	  if (a == 'y' || a == 'Y')
	     //if yes, quit application
	    return;
	}
    }
  while (a != 'y' && a != 'Y');
  //if yes exit loop and return
  return;
}

pomodoro::~pomodoro()
{
}

string pomodoro::itoa(int a)
{
    string ss="";   //create empty string
    while(a)
    {
        int x=a%10;
        a/=10;
        char i='0';
        i=i+x;
        ss=i+ss;      //append new character at the front of the string!
    }
    return ss;
}
