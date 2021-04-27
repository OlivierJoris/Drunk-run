/*
 * Implementation of the application of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "App.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "Event.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

using namespace std;

App::App(){
    window = make_shared<Window>();
    game = make_shared<Game>();
}

shared_ptr<Window> App::get_window() const{
    return window;
}

shared_ptr<Game> App::get_game() const {
    return game;
}

int App::run(){
    cout << "* Starting the game *" << endl;

    if(window == nullptr || game == nullptr){
        cerr << "Unable to run game" << endl;
        return -1;
    }

    SDL_Event event;
    Uint32 time = 0;
    const Uint32 TIME_PER_FRAME = 1000/game->get_frame_rate();

    // Sets the state as running
    game->get_game_state()->set_status(GameStateStatus::ongoing);

    while(game->get_game_state()->get_status() == GameStateStatus::ongoing){
        time = SDL_GetTicks();
        // Gets the events & reacts to them
        while(SDL_PollEvent(&event)){
            DrunkRunEvent drEvent = Event::get_event(event);
            handle_event(drEvent);
        }

        // Draws the game
        if(game->draw(window) < 0)
            return -1;

        // Updates screen
        SDL_RenderPresent(window->get_sdl_renderer());

        // Lock rendering at 30 fps
        Uint32 diffTime = SDL_GetTicks() - time;
        if(diffTime < TIME_PER_FRAME){
            SDL_Delay(TIME_PER_FRAME - diffTime);
        }
    }

    return 0;
}

void App::quit(){
    SDL_DestroyRenderer(window->get_sdl_renderer());
    SDL_DestroyWindow(window->get_sdl_window());
    TTF_Quit();
    SDL_Quit();
}

void App::handle_event(const DrunkRunEvent& event) const {

    switch(event) {
        case DrunkRunEvent::close:
            game->get_game_state()->set_status(GameStateStatus::ended);
            break;
        
        case DrunkRunEvent::left:
            cout << "Cymi going left" << endl;
            // Need to call the adequate function inside the Player class
            break;
        
        case DrunkRunEvent::right:
            cout << "Cymi going right" << endl;
            // Need to call the adequate function inside the Player class
            break;
        
        default:
            break;
    }
}
