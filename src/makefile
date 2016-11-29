#########################################################################
# Program:
#    Tomato - timer for Pomodoro technique
# Author:
#    Alexander Marvin
# Summary: 
#    Makefile for Tomato
#########################################################################

#########################################################################
# tomato
#########################################################################
tomato: tomato.cpp tomato.h settings.o
	g++ -o tomato settings.o tomato.cpp

testSettings: settings.o testSettings.cpp
	g++ -o testSettings settings.o testSettings.cpp

#########################################################################
# Individual files
#########################################################################
settings.o: settings.h settings.cpp
	g++ -c settings.cpp

#########################################################################
# General rules
#########################################################################
clean:
	rm a.out *.o

all: tomato
