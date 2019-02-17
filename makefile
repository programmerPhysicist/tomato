#########################################################################
# Program:
#    Tomato - timer for Pomodoro technique
# Author:
#    Alexander Marvin
# Summary: 
#    Makefile for Tomato
#########################################################################
ifeq ($(OS),Windows_NT)
    SYSTEM=Windows
else
    SYSTEM=$(shell uname -s)
endif
SHELL = /bin/sh
CXX=g++
CFLAGS=-I./include/
INCLDDIR = include
DEPS=$(addprefix $(INCLDDIR)/, pomodoro.h display.h)
OBJDIR = build
BIN = bin/tomato
OBJECTS = $(addprefix $(OBJDIR)/, pomodoro.o tomato.o display.o)
LIBRARIES = $(addprefix -l, ncurses boost_program_options)

#########################################################################
# General rules
#########################################################################
all: $(BIN)

clean:
	rm -rf $(OBJDIR)/*.o $(BIN) target/ *~ src/*~ .*~

package: all
	mkdir -p target/tomato
	cp bin/tomato* target/tomato/
	cp -r src/resources/ target/tomato/resources/
	cp *.sh target/tomato/
	tar -czf target/tomato-0.3-install-$(SYSTEM).tar.gz target/tomato

#########################################################################
# Generic build rules
#########################################################################
$(OBJDIR)/tomato.o: src/tomato.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/%.o: src/%.cpp include/%.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJECTS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBRARIES)
	chmod +x *.sh
