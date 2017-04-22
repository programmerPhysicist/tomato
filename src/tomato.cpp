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
  pomodoro instance;
  
  while(true) //loop forever, or until user
    {
      for (int i = 0; i < 3; i++) //loop thru 4 pomodoros
	{
	  //work
	  instance.work();
	  //take a rest
	  instance.rest();
	}
      //do work
      instance.work();
      //then long break
      instance.longBreak();
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
  
  for (int i = minutes; i > 0; i--) //loop thru minutes
    {
      //display clock
      Display.setClock(itoa(i)+ ":00");
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
  char a = 'n';
  do
    {
      a = Display.getUserInput("Start time(y/n): ");
      if (a == 'n' || a == 'N')
	{ //if no, ask if they want to quit
	  a = Display.getUserInput("Do you want to quit(y/n): ");
	  if (a == 'y' || a == 'Y')
	    {
	      this->~pomodoro();
	    }
	}
    }
    while (a != 'y' && a != 'Y');
  //if yes exit loop and return
  return;
}

void pomodoro::work()
{
  Display.displayMessage("**Time to work!**");
  playAlarm();
  waitForUser();
  //timer(config.workTime);
  timer(25);
}

void pomodoro::rest()
{
  Display.displayMessage("**Breaktime!**");
  playAlarm();
  waitForUser();
  timer(config.shortBreak);
}

void pomodoro::longBreak()
{
  Display.displayMessage("**Time for long break!**");
  playAlarm();
  waitForUser();
  timer(config.longBreak);
}

void pomodoro::quit()
{
  this->~pomodoro();
}

pomodoro::~pomodoro()
{
  Display.~display();
  exit(0);
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
