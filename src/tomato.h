/***********************************************************************
* Header File:
*   tomato.h
* Author:
*   Alexander Marvin
* Summary:
*   Header file for tomato program
************************************************************************/
#ifndef TOMATO_H
#define TOMATO_H

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

//define name/directory for config file

#ifndef NDEBUG
#define CONFIG_FILE ".tomato"
#endif // define config file

#endif // ENDIF for operating system choice
/*************************************************************************/

/*************************************************************************
 * pomodoro class definition
 *************************************************************************/
#include "display.h"
#include "settings.h"

class pomodoro
{
 public:
  //methods
  pomodoro();
  void timer(int minutes);
  void playAlarm();
  void waitForUser();
  display Display;
  void quit();
  ~pomodoro();
 private:
  std::string itoa(int a);
  settings config;
};

#endif // TOMATO_H
