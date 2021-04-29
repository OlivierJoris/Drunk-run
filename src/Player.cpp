/*
 * Implementation of the player of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Player.hpp"


// The player represented as a 40x180x40 cm³ white object.
Player::Player(): Object(40, 180, 40, 0, 0, 0){
    set_coordinates(0, 0, 0);
}

void Player::increaseXPosition(double increase){
    double currentX = topleft->get_x();
    topleft->set_x(currentX + increase);
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

void Player::draw()const{}
