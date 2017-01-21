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
OBJDIR = build
TARGET = bin/tomato
OBJECTS = $(addprefix $(OBJDIR)/, settings.o tomato.o)
LIBRARIES = $(addprefix -l, ncurses)

#########################################################################
# General rules
#########################################################################
all: $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) *~ src/*~ .*~

#########################################################################
# Generic build rules
#########################################################################
$(OBJDIR)/%.o: src/%.cpp
	$(CXX) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBRARIES)
