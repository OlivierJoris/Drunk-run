/*
 * Implementation of the player of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Player.hpp"

#include <iostream>

using namespace std;

Player::Player(): Object(DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_DEPTH, 0, 0, 0){
    set_coordinates(
        0 - static_cast<double>(DEFAULT_WIDTH/2),
        -(405.0/2 - 180),
        0
    );
}

void Player::increaseXPosition(double increase){
    double currentX = topleft->get_x();
    topleft->set_x(currentX + increase);
}

void Player::player_goes_forward(double increase){
    double currentZ = topleft->get_z();
    topleft->set_z(currentZ + increase);
}

void Player::player_goes_left(){
    double currentX = topleft->get_x();
    topleft->set_x(currentX - LATERAL_MOVEMENT_SIZE);
}

void Player::player_goes_right(){
    double currentX = topleft->get_x();
    topleft->set_x(currentX + LATERAL_MOVEMENT_SIZE);
}

unsigned int Player::get_min_movement_range() const{
    return MIN_RANGE_MOVEMENT;
}

unsigned int Player::get_max_movement_range() const{
    return MAX_RANGE_MOVEMENT;
}

unsigned int Player::get_movement_rate() const{
    return MOVEMENT_RATE;
}

unsigned int Player::get_movement_size() const{
    return LATERAL_MOVEMENT_SIZE;
}

double Player::get_x() const{
    return topleft->get_x();
}

unsigned int Player::get_fov() const{
    return FOV;
}
