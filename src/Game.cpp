/*
 * Implementation of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Game.hpp"

#include <memory>
#include <vector>
#include <list>

using namespace std;

Game::Game(
    unsigned int frameRate,
    double clearingDistance,
    double dangerousRate
): frameRate{frameRate}, clearance{clearingDistance}, dangerousObstacleRate{dangerousRate}{

    state = make_shared<GameState>();
    player = make_shared<Player>();
    path = make_shared<Path>();

    kerbs = vector<Kerb>();
    kerbs.push_back(Kerb());
    kerbs.push_back(Kerb());

    obstacles = list<Object>();
}

void Game::draw(shared_ptr<Window> w){
    // to be filled
}

shared_ptr<GameState> Game::get_game_state() const{
    return state;
}

shared_ptr<Player> Game::get_player() const{
    return player;
}

shared_ptr<Path> Game::get_path() const{
    return path;
}

const vector<Kerb>& Game::get_kerbs() const{
    return kerbs;
}

const list<Object>& Game::get_obstacles() const{
    return obstacles;
}

void Game::add_obstacle(Object& obstacle){
    /* TO DO: modifies in order to keep the list sorted by distance.
        Requires the Object class to be implemented. */
    obstacles.push_back(obstacle);
}

unsigned int Game::get_frame_rate() const{
    return frameRate;
}

double Game::get_clearance_dist() const{
    return clearance;
}

double Game::get_distribution_dangerous() const{
    return dangerousObstacleRate;
}
