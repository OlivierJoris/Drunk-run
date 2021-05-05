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
        0 - static_cast<double>(DEFAULT_WIDTH / 2),
        10,
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

unsigned int Player::get_dov() const{
    return DOV;
}

unsigned int Player::get_distance_eye_ground() const{
    return DEFAULT_DISTANCE_EYE_GROUND;
}

unsigned int Player::get_distance_eye_screen() const{
    return DEFAULT_DISTANCE_EYE_SCREEN;
}

Coordinate3D Player::get_position_eye() const{
    return Coordinate3D(
        topleft->get_x() + (static_cast<double>(DEFAULT_WIDTH) / 2.0),
        0,
        -get_distance_eye_screen()
    );
}

void Player::print_pos() const{
    cout << "Player : " << *topleft << endl;
}
