/*
 * Implementation of the player of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Player.hpp"

#include <iostream>

using namespace std;

Player::Player(
    const unsigned int fov,
    const unsigned int dov,
    const unsigned int drunkMovRate,
    const unsigned int distanceEyeGround,
    const unsigned int distanceEyeScreen
): Object(DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_DEPTH, 0, 0, 0){
    Player::fov = fov;
    Player::dov = dov;
    Player::drunkMovRate = drunkMovRate;
    Player::distanceEyeGround = distanceEyeGround;
    Player::distanceEyeScreen = distanceEyeScreen;
    set_coordinates(
        0 - static_cast<double>(DEFAULT_WIDTH / 2),
        10,
        0
    );
}

void Player::increase_x_position(const double increase){
    double currentX = topLeft->get_x();
    topLeft->set_x(currentX + increase);
}

void Player::player_goes_forward(const double increase){
    double currentZ = topLeft->get_z();
    topLeft->set_z(currentZ + increase);
}

void Player::player_goes_left(){
    double currentX = topLeft->get_x();
    topLeft->set_x(currentX - LATERAL_MOVEMENT_SIZE);
}

void Player::player_goes_right(){
    double currentX = topLeft->get_x();
    topLeft->set_x(currentX + LATERAL_MOVEMENT_SIZE);
}

unsigned int Player::get_min_movement_range() const{
    return MIN_RANGE_MOVEMENT;
}

unsigned int Player::get_max_movement_range() const{
    return MAX_RANGE_MOVEMENT;
}

unsigned int Player::get_movement_rate() const{
    return drunkMovRate;
}

unsigned int Player::get_movement_size() const{
    return LATERAL_MOVEMENT_SIZE;
}

unsigned int Player::get_fov() const{
    return fov;
}

unsigned int Player::get_dov() const{
    return dov;
}

unsigned int Player::get_distance_eye_ground() const{
    return distanceEyeGround;
}

unsigned int Player::get_distance_eye_screen() const{
    return distanceEyeScreen;
}

Coordinate3D Player::get_position_eye() const{
    return Coordinate3D(
        topLeft->get_x() + (static_cast<double>(size->get_width()) / 2.0),
        0,
        -get_distance_eye_screen()
    );
}
