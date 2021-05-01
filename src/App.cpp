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
    Uint32 time = 0, frameCounter = 0, randomMovCounter = 0;
    // Time per frame in ms
    const Uint32 TIME_PER_FRAME = 1000 / game->get_frame_rate();
    // Score increment per frame. With this, 1 meter = 1 second
    const double SCORE_INCREMENT = 1.0 / game->get_frame_rate();

    // Sets the status as running
    game->set_game_status(GameStateStatus::ongoing);

    while(game->get_game_status() == GameStateStatus::ongoing){
        time = SDL_GetTicks();

        // Generates random object every 50 cm (0,5 sec) after clearance
        if(game->get_game_state()->get_travelled_dist() > game->get_clearance_dist()){
            if(frameCounter >= game->get_frame_rate() / 2){
                game->add_random_obstacle();
                frameCounter = 0;
            }else
                frameCounter++;
        }

        // One random movement at a given rate (2 seconds as default)
        if(randomMovCounter >= game->get_player()->get_movement_rate()){
            game->player_random_movement();
            randomMovCounter = 0;
        }else
            randomMovCounter+=1;

        /* Cymi is always walking forward. Since the score is the distance,
            we can use the score increment for the distance */
        game->get_player()->player_goes_forward(SCORE_INCREMENT);
    
        // Gets the events & reacts to them
        while(SDL_PollEvent(&event)){
            DrunkRunEvent drEvent = Event::get_event(event);
            handle_event(drEvent);
        }

        // Increments score
        game->increment_score(SCORE_INCREMENT);

        // Draws the game
        if(game->draw(window) < 0)
            return -1;

        // Updates screen
        SDL_RenderPresent(window->get_sdl_renderer());

        // Lock rendering at given frame rate
        Uint32 diffTime = SDL_GetTicks() - time;
        if(diffTime < TIME_PER_FRAME){
            SDL_Delay(TIME_PER_FRAME - diffTime);
        }
    }

    // If game is ended, shows game over message for 2 seconds.
    if(game->draw(window) < 0)
        return -1;

    SDL_Delay(1000 * GAME_OVER_TIME);

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
            if(game && game->get_player())
                game->get_player()->player_goes_left();
            break;
        
        case DrunkRunEvent::right:
            if(game && game->get_player())
                game->get_player()->player_goes_right();
            break;
        
        default:
            break;
    }
}
