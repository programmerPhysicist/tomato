/***********************************************************************
 * tomato:
 *    Source code for tomato.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A timer
 ************************************************************************/
#include <iostream>
#ifdef _WIN32
//windows stuff
#include <windows.h>
//#include "tchar.h"
#define WAIT Sleep
#define SECOND 1000
#elif defined(__unix__) || defined(__linux__)
//linux and unix stuff
#include <ctime>
#include <unistd.h>
#define WAIT usleep
#define SECOND 1000000
#endif
using namespace std;

bool timer(int minutes);

int main()
{
  //get time
  //time_t initialTime = time(NULL); //get current time

  //initialize stuff
  //time_t now;
  bool success;
  
  //double seconds;
  
  success = timer(5);
  
  cout << "Your time is up!\n";
}

bool timer(int minutes)
{
  int waitTime = 60*SECOND;
  for (int i = 0; i < minutes; i++)
    {
      //display
      cout << (minutes - i) << " minutes remaining\n";
      //wait
      WAIT(waitTime);
    }
  return true;
}
