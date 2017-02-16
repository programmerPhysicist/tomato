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
  settings config; //initialize settings object
  pomodoro instance;
  config.loadConfig(CONFIG_FILE); //load settings into config
  //initialize our screen
  
  instance.initializeDisplay();
  //displayMessage("Testing!");
  
  while(true) //loop forever, or until user
    {
      for (int i = 0; i < 3; i++) //loop thru 4 pomodoros
	{
	  //work
	  instance.displayMessage("**Time to work!**");
	  instance.playAlarm();
	  //waitForUser();
	  //timer(config.workTime);
	  //break
	  instance.end();
	  instance.displayMessage("**Breaktime!**");
	  instance.playAlarm();
	  instance.waitForUser();
	  instance.timer(config.shortBreak);
	}
      //do work
      instance.displayMessage("**Time to work!**");
      instance.playAlarm();
      instance.waitForUser();
      instance.timer(config.workTime);
      //then long break
      instance.displayMessage("**Time for long break!**");
      instance.playAlarm();
      instance.waitForUser();
      instance.timer(config.longBreak);
      }
  instance.end();
  return 0;
}

void pomodoro::timer(int minutes)
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
	    end();
	}
    }
  while (a != 'y' && a != 'Y');
  //if yes exit loop and return
  return;
}

void pomodoro::displayMessage(string message)
{
  //cout << "\t" << message << endl;
  move(0,0);
  clrtoeol();
  printw(message.c_str());
  refresh();
}

void pomodoro::initializeDisplay()
{
  //initialize window
  initscr(); //start curses mode
  cbreak(); //Disable line buffering
  refresh(); //Now refresh screen

  //setup bottom bar
  WINDOW *bar = newwin(2, 80, 22, 0); //create new window
  whline(bar, '_', 80); //draw line
  wrefresh(bar); //refresh

  //setup top bar
  WINDOW *bar2 = newwin(2, 80, 1, 0); //create new window
  whline(bar2, '_', 80);
  wrefresh(bar2);
  getch();
}

void pomodoro::end()
{
  endwin();
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
