# Makefile for building a C++ project
#
# Maxime Goffart (180521) & Olivier Joris (182113)

CXX=g++
CXXFLAGS=-std=c++17 --pedantic -Wall -Wextra $(shell sdl2-config --cflags)
LDFLAGS=$(shell sdl2-config --libs) -lSDL2_ttf
APP=drunkrun

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(APP)

$(APP): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm $(APP)
	clear
