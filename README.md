Tomato

Version: 0.1, beta 12/26/2016

Author: Alex Marvin

Introduction
------------

This program allows one to use the Pomodoro techique on the command line.
The Pomodoro technique is a productivity technique in which you work for
25 minutes and then take a 5 minute break. Then you work for another 25
minutes. Each 25 minute period is known as a Pomodoro. You repeat as many
times as necessary. After 4 Pomodoros, you take a longer break.

Getting Started/Running
-----------------------

Simply run `make` in the **tomato** directory to compile the code.

To run:

    cd source_code_folder/bin
    ./tomato

To run while doing other work on command line:

    ./tomato&

Before the timer starts it will ask you if you want to start. Press _y_ to
start. To quit press _n_, and press _y_ when it asks you to quit.

Installation
------------

To install, open tomato.sh and set the value of **TOMATO_DIR** to the file
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
keyword = #
* keyword is either *worktime*, *breaktime*, or *longbreak*
* # is any integer
* There must be spaces before and after each equal sign
* Any extra white spaces beyond those may cause the program to throw an
  error.
