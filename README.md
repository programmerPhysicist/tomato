Tomato

Version: 0.3, beta 02/12/2019

Author: Alex Marvin

Introduction
------------

This program allows one to use the Pomodoro techique on the command line.
The Pomodoro technique is a productivity technique in which you work for
25 minutes and then take a 5 minute break. Then you work for another 25
minutes. Each 25 minute period is known as a Pomodoro. You repeat as many
times as necessary. After 4 Pomodoros, you take a longer break.

Running
-------
To run:

    tomato

A bar will show up at the top. Press `s` to start the timer. Depending on the message, 
it will start the break or work timer.

To stop the program, simply press `CTRL+C`

Installation
------------
Make sure that the prequisites below are installed before installation.

Run `make` in the **tomato** directory to compile the code.

Then run 

    sudo ./install.sh
    
If you don't have sudoer privileges, run the above script. 
You will have to set the path for the executable though.

Prerequisites
-------------
    
*Required Libraries*

Run the following command for
Debian based systems:

    sudo apt-get install libboost-all-dev libncurses5-dev libncursesw5-dev
    
On Redhat based systems:

    yum install boost-devel ncurses-devel

Configuration
-------------

Find the .tomato file and open using your favorite text editor

The first line is the work time, second is the length of the break, and
the last line is that of the long break. Numbers are in minutes.

The format is:
`keyword = 5`
* keyword is either *worktime*, *breaktime*, or *longbreak*
* "5" is the number of minutes
