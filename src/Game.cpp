/*
 * Implementation of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Game.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cmath>

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

int Game::draw(shared_ptr<Window> w){
    if(!w)
        return -1;

    // Black background
    if(SDL_SetRenderDrawColor(w->get_sdl_renderer(), 0, 0, 0, 255) < 0){
        cerr << "Error while setting background color" << endl;
        return -1;
    }
    if(SDL_RenderClear(w->get_sdl_renderer()) < 0){
        cerr << "Error while printing background color" << endl;
        return -1;
    }

    RGBColor red(255, 0, 0);
    if(w->draw_line(0, 0, w->get_width(), w->get_height(), red) < 0)
        return -1;

    if(w->draw_line(0, w->get_height(), w->get_width(), 0, red) < 0)
        return -1;

    RGBColor blue(0, 0, 255);
    int drawRect;
    drawRect = w->draw_rect(
        w->get_height()/2,
        w->get_width()/2,
        w->get_width()/4,
        w->get_height()/4,
        blue
    );
    if(drawRect < 0)
        return -1;

    unsigned int score;
    score = static_cast<unsigned int>(floor(state->get_travelled_dist()));
    string scoreTxt = to_string(score);
    scoreTxt+=" m";

    RGBColor white(255, 255, 255);
    unsigned int pos = (w->get_width() / 2) - 25;
    if(w->draw_text(scoreTxt, 48, white, 50, 50, pos, 0) < 0)
        return -1;

    // Draws other elements
    //path->draw();
    //kerbs[0]->draw();
    //kerbs[1]->draw();
    // Draw obstacles but only the want in the DoV (depth of view)

    return 0;
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

void Game::add_obstacle(const Object& obstacle){
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

void Game::update_score(const double increment) const{
    if(state)
        state->increase_travelled_dist(increment);
}
