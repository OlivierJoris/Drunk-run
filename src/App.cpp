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
    if(window == nullptr || game == nullptr){
        cerr << "Unable to run game" << endl;
        return -1;
    }

    SDL_Event event;
    Uint32 time = 0, frameCounter = 0;
    const Uint32 TIME_PER_FRAME = 1000/game->get_frame_rate();
    // With this, 1 meter = 1 second
    const double SCORE_INCREMENT = 1.0/game->get_frame_rate();

    // Sets the state as running
    game->get_game_state()->set_status(GameStateStatus::ongoing);

    while(game->get_game_state()->get_status() == GameStateStatus::ongoing){

        // Generates random object every 50 cm (0,5 sec)
        if(game->get_game_state()->get_travelled_dist() > game->get_clearance_dist()){
            frameCounter++;
            if(frameCounter >= game->get_frame_rate() / 2){
                game->add_random_obstacle();
                frameCounter = 0;
            }
        }
        time = SDL_GetTicks();
    
        // Gets the events & reacts to them
        while(SDL_PollEvent(&event)){
            DrunkRunEvent drEvent = Event::get_event(event);
            handle_event(drEvent);
        }

        // Updates score
        game->update_score(SCORE_INCREMENT);

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

    if(game->draw(window) < 0)
        return -1;
    SDL_Delay(1000 * 2); // Show game over message for 2 seconds


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
