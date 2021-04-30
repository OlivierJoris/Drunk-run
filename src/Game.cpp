/*
 * Implementation of the game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Game.hpp"
#include "GameState.hpp"
#include "Renderer.hpp"
#include "Obstacle.hpp"
#include "DangerousObstacle.hpp"
#include "NonDangerousObstacle.hpp"
#include "People.hpp"
#include "Barrier.hpp"
#include "Rubbish.hpp"
#include "Crate.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cmath>
#include <random>
#include <chrono>

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

    obstacles = list<shared_ptr<Object>>();

    randomGenerator = minstd_rand(chrono::system_clock::now().time_since_epoch().count());
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
    //for(auto iter = obstacles.cbegin(); iter != obstacles.cend(); iter++)
    //    iter->get()->draw();

    // If game is over, adds "game over" text
    if(state->get_status() == GameStateStatus::ended){
        unsigned int height = 100, width = 250;
        unsigned int xTop = (w->get_width() / 2) - 125;
        unsigned int yTop = (w->get_height() / 2) - 50;
        if(w->draw_text("Game Over!", 96, white, height, width, xTop, yTop))
            return -1;
    }

    return 0;
}

shared_ptr<GameState> Game::get_game_state() const{
    return state;
}

GameStateStatus Game::get_game_status() const{
    if(state)
        return state->get_status();
    else
        return GameStateStatus::ended;
}

void Game::set_game_status(GameStateStatus status){
    if(state)
        state->set_status(status);
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

const list<shared_ptr<Object>>& Game::get_obstacles() const{
    return obstacles;
}

void Game::add_obstacle(const Object& obstacle){
    /* TO DO: modifies in order to keep the list sorted by distance.
        Requires the Object class to be implemented. */
    obstacles.push_back(make_shared<Object>(obstacle));
}

void Game::add_random_obstacle(){
    unsigned int dangerousOrNot = get_random(10);
    unsigned int type;

    if(dangerousOrNot < DEFAULT_DANGEROUS_RATE){
        // Needs to generate a dangerous obstacle
        type = get_random(DangerousObstacle::NB_RANDOM_D_OBSTACLES);
        if(type == 0)
            obstacles.push_back(make_shared<Barrier>());
        else
            obstacles.push_back(make_shared<People>());
    }else{
        // Needs to generate a non-dangerous obstacle
        type = get_random(NonDangerousObstacle::NB_RANDOM_ND_OBSTACLES);
        if(type == 0)
            obstacles.push_back(make_shared<Rubbish>());
        else
            obstacles.push_back(make_shared<Crate>());
    }
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

void Game::increment_score(const double increment) const{
    if(state)
        state->increase_travelled_dist(increment);
}

unsigned int Game::get_random(unsigned int upperLimit){
    return randomGenerator() % upperLimit;
}

void Game::player_random_movement(){
    // Need to take into account the current position of Cymi.
    unsigned int movSizeMin = player->get_min_movement_range();
    unsigned int movSizeMax = player->get_max_movement_range();
    unsigned int randMovSize = get_random(movSizeMax - movSizeMin + 1);
    
    double increaseX;

    if(get_random(2) == 0)
        increaseX = randMovSize * player->get_movement_size();
    else
        increaseX = (- static_cast<double>(randMovSize)) * player->get_movement_size();

    player->increaseXPosition(increaseX);
}
