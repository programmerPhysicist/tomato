/***********************************************************************
* Header File:
*   pomodoro.h
* Author:
*   Alexander Marvin
* Summary:
*   Header file for pomodoro class
************************************************************************/
#ifndef POMODORO_H
#define POMODORO_H

/******************Choose between operating systems*********************/

/****************************WINDOWS************************************/
#ifdef _WIN32
#include <windows.h>
#include "tchar.h"
#define WAIT Sleep
#define SECOND 1000
#define CONFIG_FILE ".tomato"
/**************************UNIX OR LINUX*********************************/
#elif defined(__unix__) || defined(__linux__)
#include <ctime>
#include <unistd.h>
#define LINUX_UNIX
#define WAIT usleep
#define SECOND 1000000
#define CONFIG_FILE ".tomato"
#define TOMATO_PATH "/usr/local/share/tomato"
#define SOUND_FILE "/sounds/alarm_tones/bell.wav"
#endif // ENDIF for operating system choice
/*************************************************************************/

/*************************************************************************
 * pomodoro class definition
 *************************************************************************/
#include "display.h"

class pomodoro
{
 public:
  //constructors
  pomodoro() {};
  pomodoro(int work, int shortB, int longB, std::string home);
  //methods
  void work(); //time to work
  void rest(); //time for break
  void longBreak(); //runs longer break
  void quit(); //quit and return to normal terminal
  //variables
  int workTime;
  int breakTime;
  int longTime;
  std::string tomatoHome;
  ~pomodoro(); //destructor
 private:
  void timer(int minutes); //run timer
  void playAlarm(); //play an audiable alarm
  void waitForUser(); //wait for input from user
  std::string itoa(int a);
  display Display; //display object
};

#endif // POMODORO_H
