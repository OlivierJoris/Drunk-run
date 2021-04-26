/*
 * Implementation of a window of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Window.hpp"

#include <iostream>

using namespace std;

Window::Window(): height{DEFAULT_HEIGHT}, width{DEFAULT_WIDTH}{
    build_window();
}

Window::Window(unsigned int width, unsigned int height)
: height{height}, width{width} {
    build_window();
}

void Window::build_window(){
    window = SDL_CreateWindow(
        "Drunk run",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if(!window){
        cerr << "Error while creating window %s" << SDL_GetError() << endl;
        return;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if(surface)
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 255, 255, 255));

}

unsigned int Window::get_height() const{
    return height;
}

unsigned int Window::get_width() const{
    return width;
}

SDL_Window* Window::get_sdl() const {
    return window;
}
