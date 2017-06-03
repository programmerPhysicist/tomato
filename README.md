Tomato

Version: 0.2, beta 06/03/2017

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

Then open tomato.sh and set the value of **TOMATO_DIR** to the file
path of the **tomato** folder.

Then run

    chmod +x tomato.sh

Next move tomato.sh to **/usr/local/bin** or **/usr/bin**.
Then, create a symlink called tomato in the bin folder.

Alternatively, you can create a symlink to the location of tomato.sh

Prerequisites
-------------

*PulseAudio sound server*

This should be installed by default on most Debian and Redhat desktop systems.
If it is not installed for whatever reason, to install:

Debian based systems:

    apt-get install pulseaudio

To install in Fedora or similar systems:

    dnf install pulseaudio 

Configuration
-------------

Find the .tomato file and open using your favorite text editor

The first line is the work time, second is the length of the break, and
the last line is that of the long break. Numbers are in minutes.

The format is:
`keyword = #`
* keyword is either *worktime*, *breaktime*, or *longbreak*
* "#" is any integer
* There must be spaces before and after each equal sign
* Any extra white spaces beyond those may cause the program to throw an
  error.
