/***********************************************************************
 * tomato:
 *    Source code for tomato.cpp
 * Author:
 *    Alexander Marvin
 * Summary:
 *    A Pomodoro timer command line application
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include "pomodoro.h"
using namespace std;
namespace po = boost::program_options;

//function predefined
string parseEnvHelper(string envVar);

int main(int ac, char* av[])
{
  try {
    //do stuff with commandline
    int opt;
    string config_file = CONFIG_FILE;
    string tomatoHome = TOMATO_PATH;
    string location;
    string temp;
    //Declare the supported options.
    po::options_description generic("Generic options");
    generic.add_options()
      ("help", "produce help message")
    ;

    //Declare options for config file and command line
    po::options_description config("Configuration");
    config.add_options()
      ("worktime", po::value<int>(),
       "number of minutes for work period")
      ("breaktime", po::value<int>(),
       "number of minutes for break")
      ("longbreak", po::value<int>(),
       "number of minutes for the long break")
    ;

    //Declare positional options
    po::positional_options_description pd;
    pd.add("worktime", 1).add("breaktime", 1).add("longbreak", 1);

    //Declare hidden options
    po::options_description hidden("Hidden options");
    hidden.add_options()
      ("location,l", po::value<string>(),
       "location of config file .tomato")
    ;

    //group above options
    po::options_description cmdline_options;
    cmdline_options.add(generic).add(config).add(hidden);

    po::options_description config_file_options;
    config_file_options.add(config);

    po::options_description visible("Allowed options");
    visible.add(generic).add(config);

    //parse command line parameters
    po::variables_map vm;
    po::store(po::command_line_parser(ac, av).
	      options(cmdline_options).positional(pd).run(), vm);
    po::store(po::parse_environment(hidden, parseEnvHelper), vm);
    po::notify(vm);

    if (vm.count("help")) {
      cout << visible << "\n";
      return 0;
    }

    string path;
    if (vm.count("location"))
    {
      path = vm["location"].as<string>() + "/" + config_file;
    }
    else
      path = config_file;
    //parse config file
    ifstream ifs(path.c_str());
    if (!ifs)
    {
      cout << "Cannot open config file: " << path << "\n";
      return 1;
    }
    else
    {
      po::store(po::parse_config_file(ifs, config_file_options), vm);
      po::notify(vm);
    }
    
    //check that application directory exists
    if (!std::ifstream(tomatoHome.c_str()))
    {
      tomatoHome = vm["location"].as<string>() + "/" + "tomato";
      if (!std::ifstream(tomatoHome.c_str()))
      {
	cout << "ERROR: Cannot find application directory at "
	     << TOMATO_PATH << " or " << tomatoHome << endl;
	return 1;
      }
    }
    
    //initialize stuff
    pomodoro instance = pomodoro(vm["worktime"].as<int>(),
				 vm["breaktime"].as<int>(),
				 vm["longbreak"].as<int>(), tomatoHome);
  
    while(true) //loop forever, or until user hits CTRL+C
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
  catch(exception& e)
  {
    cout << e.what() << "\n";
    return 1;
  }
}

string parseEnvHelper(string envVar)
{
  if (envVar == "HOME")
    return "location";
  else
    return "";
}
