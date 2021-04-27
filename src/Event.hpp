/*
 * The events of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __DRUNK_RUN_EVENT__
#define __DRUNK_RUN_EVENT__

#include <SDL2/SDL.h>

// An event of the game.
enum DrunkRunEvent {close, left, right, unknown};

// Represents the events of the game.
class Event{

public:
    /*
     * Returns a DrunkRunEvent based on a SDL_event.
     *
     * @param sdlEvent The SDL event.
     * 
     * @return The DrunkRunEvent associated to the given SDL event.
     */
    static DrunkRunEvent get_event(const SDL_Event& sdlEvent);
};

#endif
