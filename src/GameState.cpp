/*
 * Implementation of the game state of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "GameState.hpp"

GameState::GameState(): travelledDist{0.0}, status{GameStateStatus::ended}{}

double GameState::get_travelled_dist() const{
    return travelledDist;
}

void GameState::set_travelled_dist(double newDist){
    travelledDist = newDist;
}

void GameState::increase_travelled_dist(double increase){
    travelledDist+=increase;
}

GameStateStatus GameState::get_status() const{
    return status;
}

void GameState::set_status(GameStateStatus newStatus){
    status = newStatus;
}
