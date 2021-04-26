/*
 * Implementation of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Game.hpp"

#include <memory>

using namespace std;

Game::Game(){
    state = make_shared<GameState>();
}

shared_ptr<GameState> Game::get_game_state() const{
    return state;
}
