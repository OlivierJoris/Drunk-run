# Makefile for building a C++ project
#
# Maxime Goffart (180521) & Olivier Joris (182113)

CXX=g++
SDL_LIB=-lSDL2 -lSDL2_image -lSDL2_ttf
SDL_INCLUDE=-I/usr/include/SDL2
FLAGS=-std=c++17 --pedantic -Wall -Wextra
APP=drunkrun

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(APP)

$(APP): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(SDL_LIB)

%.o: %.cpp
	$(CXX) $(SDL_LIB) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm $(APP)
	clear
