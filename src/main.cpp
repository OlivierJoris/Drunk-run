/*
 * Main function for drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "App.hpp"
#include "Window.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize SDL
    int init = SDL_Init(SDL_INIT_VIDEO);
    if(init < 0){
        cerr << "Error while initializing SDL: " << SDL_GetError() << endl;
    }

    // Builds app
    shared_ptr<App> app = make_shared<App>();

    // Starts app
    int runStatus = app->run();
    if(runStatus < 0){
        cerr << "Error while running the game" << endl;
        return runStatus;
    }

    // Quits app
    app->quit();
    
    return 0;
}
