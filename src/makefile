#########################################################################
# Program:
#    Tomato - timer for Pomodoro technique
# Author:
#    Alexander Marvin
# Summary: 
#    Makefile for Tomato
#########################################################################
SHELL = /bin/sh
CXX=g++
CFLAGS=-I.
DEPS = settings.h
OBJ = settings.o tomato.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

tomato: tomato.o settings.o
	$(CXX) -o $@ $^ $(CFLAGS)

#########################################################################
# General rules
#########################################################################
clean:
	rm a.out *.o

all: tomato
