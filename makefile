#########################################################################
# Program:
#    Tomato - timer for Pomodoro technique
# Author:
#    Alexander Marvin
# Summary: 
#    Makefile for Tomato
#########################################################################
SHELL = /bin/sh
BOOST_PATH = /usr/local/lib
CXX=g++
CFLAGS=-I.
OBJDIR = build
TARGET = bin/tomato
OBJECTS = $(addprefix $(OBJDIR)/, pomodoro.o tomato.o display.o)
LIBRARIES = $(addprefix -l, ncurses) $(BOOST_PATH)/libboost_program_options.a

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
