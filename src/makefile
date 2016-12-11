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
EXDIR = $(ROOT_TOMATO)/bin
OBJDIR = $(ROOT_TOMATO)/obj
TARGET = $(EXDIR)/tomato
OBJECTS = $(addprefix $(OBJDIR)/, settings.o tomato.o)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CFLAGS)

#########################################################################
# General rules
#########################################################################
clean:
	rm -f $(TARGET) $(OBJDIR)/*.o

all: $(TARGET)
