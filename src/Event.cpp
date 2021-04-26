/*
 * Implementation of the events of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Event.hpp"

#include <SDL2/SDL.h>

DrunkRunEvent Event::get_event(SDL_Event& sdlEvent){
    // X of window
    if(sdlEvent.type == SDL_QUIT)
        return DrunkRunEvent::close;

    if(sdlEvent.type == SDL_KEYDOWN){
        switch (sdlEvent.key.keysym.sym){
            case SDLK_l: // Left with l key
               return DrunkRunEvent::left;
            case SDLK_m: // Right with m key
                return DrunkRunEvent::right;

            case SDLK_LEFT: // Left with left arrow
                return DrunkRunEvent::left;
            case SDLK_RIGHT: // Right with right arrow
                return DrunkRunEvent::right;
            
            default:
                return DrunkRunEvent::unknown;
        }
    }else
        return DrunkRunEvent::unknown;
}
