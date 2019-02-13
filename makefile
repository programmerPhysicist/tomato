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
CFLAGS=-I./include/
INCLDDIR = include
DEPS=$(addprefix $(INCLDDIR)/, pomodoro.h display.h)
OBJDIR = build
TARGET = bin/tomato
OBJECTS = $(addprefix $(OBJDIR)/, pomodoro.o tomato.o display.o)
LIBRARIES = $(addprefix -l, ncurses boost_program_options)

#########################################################################
# General rules
#########################################################################
all: $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) *~ src/*~ .*~

#########################################################################
# Generic build rules
#########################################################################
$(OBJDIR)/tomato.o: src/tomato.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/%.o: src/%.cpp include/%.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBRARIES)
	chmod +x install.sh
