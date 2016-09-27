/***********************************************************************
 * settings.cpp:
 *    Source code for settings class
 * Author:
 *    Alexander Marvin
 * Summary:
 *    Code to read in config file
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "settings.h"
using namespace std;

bool settings::loadConfig(string configFileName)
{
  cout << "loading configuration\n";
  //initialize
  ifstream fin;
  string line;
  string key;
  int value;
  int split;

  //open our file
  fin.open(".tomato");

  //check to see if open
  if (!fin.is_open())
    {
      cerr << "Unable to open file\n";
      return false;
    }

  //read in stuff
  while (!fin.eof())
    {
      getline(fin, line);
      if (line[0] == '#') //ignore lines with #
	continue;
      //process lines
      split = line.find('=');
      key = line.substr(0,split-1);
      value = atoi((line.substr(split+1)).c_str());
      putInVariable(key,value);
    }

  //close file
  fin.close();

  return true;
};

void settings::putInVariable(string key, int value)
{
  if (key == "worktime")
    workTime = value;
  else if (key == "breaktime")
    shortBreak = value;
  else if (key == "longbreak")
    longBreak = value;
  else
    cerr << "Invalid key: " << "\"" << key << "\"" << endl;    
}
