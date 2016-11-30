/***********************************************************************
 * testSettings:
 *    Driver for settings class
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Testing settings class
 ************************************************************************/
#include <iostream>
#include <string>
#include "settings.h"
using namespace std;

int main()
{
  cout << "Testing settings class\n";
  //allocate settings class
  settings configuration(2,1,3);
  string filename = ".tomato";

  cout << "The amount of work time: "<< configuration.workTime << endl;
  cout << "The break time: " << configuration.shortBreak << endl;
  cout << "Long break time: " << configuration.longBreak << endl;

  configuration.loadConfig(filename);

  cout << "Values loaded into object.\n";

  cout << "The amount of work time: "<< configuration.workTime << endl;
  cout << "The break time: " << configuration.shortBreak << endl;
  cout << "Long break time: " << configuration.longBreak << endl;
}
