/***********************************************************************
 * pomodoro:
 *    Source code for pomodoro.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Pomodoro class that has everything need to run one pomodoro.
 ************************************************************************/
#include <string>
#include <iostream>
#include "pomodoro.h"
using namespace std;

pomodoro::pomodoro(int work, int shortB, int longB, string home)
{
  workTime = work;
  breakTime = shortB;
  longTime = longB;
  tomatoHome = home;
}

void pomodoro::timer(int minutes)
{
  int waitTime = 60*SECOND; //one minute

  Display.displayMessage("Timer started!");
  
  for (int i = minutes; i > 0; i--) //loop thru minutes
    {
      //display clock
      Display.setClock(itoa(i)+ ":00");
      WAIT(waitTime); //wait one minute
    }
}

void pomodoro::playAlarm()
{
  //play simple alarm
  //Display.alarm();
}

void pomodoro::waitForUser()
{ //wait for user to start timer
  char a = 'n';
  do
    {
      a = Display.getUserInput("");
      if (a == 'n' || a == 'N')
	{ //if no, ask if they want to quit
	  a = Display.getUserInput("Do you want to quit(y/n): ");
	  if (a == 'y' || a == 'Y')
	    {
	      this->~pomodoro();
	    }
	}
    }
    while (a != 's' && a != 'S');
  //if yes exit loop and return
  return;
}

void pomodoro::work()
{
  Display.displayMessage("Time to work!");
  playAlarm();
  waitForUser();
  timer(workTime);
}

void pomodoro::rest()
{
  Display.displayMessage("Breaktime!");
  playAlarm();
  waitForUser();
  timer(breakTime);
}

void pomodoro::longBreak()
{
  Display.displayMessage("Time for a long break!");
  playAlarm();
  waitForUser();
  timer(longTime);
}

void pomodoro::quit()
{
  this->~pomodoro();
}

pomodoro::~pomodoro()
{
  Display.~display();
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
