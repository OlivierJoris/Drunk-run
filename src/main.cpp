/*
 * Main function for drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "App.hpp"
#include "Window.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[]){
    // Initializes SDL
    int initSDL = SDL_Init(SDL_INIT_VIDEO);
    if(initSDL < 0){
        cerr << "Error while initializing SDL: " << SDL_GetError() << endl;
        return -1;
    }

    // Initializes TTF
    int initTTF = TTF_Init();
    if(initTTF < 0){
        cerr << "Error while initializing TTF: " << TTF_GetError() << endl;
        SDL_Quit();
        return -1;
    }

    // Builds app
    shared_ptr<App> app = make_shared<App>();
    if(app == nullptr){
        cerr << "Error while creating the app" << endl;
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Starts app
    int runStatus = app->run();
    if(runStatus < 0){
        cerr << "Error while running the game" << endl;
        app->quit();
        return runStatus;
    }

    // Quits app
    app->quit();
    
    return 0;
}
