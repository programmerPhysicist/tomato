/***********************************************************************
 * Header File:
 *    settings.h
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A class to hold settings for tomato
 ************************************************************************/
#ifndef TOMATO_SETTINGS_H
#define TOMATO_SETTINGS_H


class settings
{
 public:
  settings()
    {
      workTime = 25;
      shortBreak = 5;
      longBreak = 15;
      //std::cerr << "I have been initialized\n";
    };
  settings(unsigned int work, unsigned int s, unsigned int l)
    {
      workTime = work;
      shortBreak = s;
      longBreak = l;
    };
  bool loadConfig(std::string configFileName);
  //variables
  unsigned int workTime;
  unsigned int shortBreak;
  unsigned int longBreak;
 private:
  void putInVariable(std::string key, int value);
};

#endif // TOMATO_SETTINGS_H
