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

void timer(int minutes);
void playAlarm();
void waitForUser();
void displayMessage(string message);
string itoa(int a);

int main()
{
  //initialize stuff
  settings config; //initialize settings object
  config.loadConfig(CONFIG_FILE); //load settings into config
  while(true) //loop forever, or until user
    {
      for (int i = 0; i < 3; i++) //loop thru 4 pomodoros
	{
	  //work
	  displayMessage("**Time to work!**");
	  playAlarm();
	  waitForUser();
	  timer(config.workTime);
	  //break
	  displayMessage("**Breaktime!**");
	  playAlarm();
	  waitForUser();
	  timer(config.shortBreak);
	}
      //do work
      displayMessage("**Time to work!**");
      playAlarm();
      waitForUser();
      timer(config.workTime);
      //then long break
      displayMessage("**Time for long break!**");
      playAlarm();
      waitForUser();
      timer(config.longBreak);
    }
  return 0;
}

void timer(int minutes)
{
  int waitTime = 60*SECOND; //one minute
  for (int i = 0; i < minutes; i++) //loop thru minutes
    {
      //display
      cout << endl;
      displayMessage("Time left: "+itoa(minutes-i)+"m");
      //wait
      WAIT(waitTime); //wait one minute
    }
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

void displayMessage(string message)
{
  cout << "\t" << message << endl;
}

string itoa(int a)
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
