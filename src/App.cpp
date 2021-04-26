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

    // Sets the state as running
    game->get_game_state()->set_status(GameStateStatus::ongoing);

    while(game->get_game_state()->get_status() == GameStateStatus::ongoing){

        while(SDL_PollEvent(&event)){
            DrunkRunEvent drEvent = Event::get_event(event);
            handle_event(drEvent);
        }

        SDL_UpdateWindowSurface(window->get_sdl());
    }

    return 0;
}

void App::quit(){
    SDL_DestroyWindow(window->get_sdl());
    SDL_Quit();
}

void App::handle_event(DrunkRunEvent& event) const {

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
