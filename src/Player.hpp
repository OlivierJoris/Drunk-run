/*
 * The player (Cymi) of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PLAYER__
#define __PLAYER__

#include "Object.hpp"

#include <memory>

class Player : public Object{

public:
    // Constuctor.
    Player();

    virtual void draw() const;

    /*
     * Increase/Decrease the position of the player on the x axis.
     *
     * @param increase Value to add to the position on the x axis.
     */
    void increaseXPosition(double increase);

    /*
     * Returns the minimum size of a movement of the player.
     */
    unsigned int get_min_movement_range() const;

    /*
     * Returns the maximum size of a movement of the player.
     */
    unsigned int get_max_movement_range() const;

    /*
     * Returns the rate of random movement.
     */
    unsigned int get_movement_rate() const;

    /*
     * Returns the size of a movement.
     */
    unsigned int get_movement_size() const;

private:
    // FOV in degree
    const unsigned int FOV = 60; 
    // DOV in cm
    const unsigned int DOV = 15000;
    // Cm per second
    const unsigned int SPEED = 10;
    // Min range for drunk movement 
    const unsigned int MIN_RANGE_MOVEMENT = 1;
    // Max range for drunk movement
    const unsigned int MAX_RANGE_MOVEMENT = 6;
    // Drunk movement in seconds
    const unsigned int MOVEMENT_RATE = 2;
    // Size of a movement in cm
    const unsigned int LATERAL_MOVEMENT_SIZE = 5;
};

#endif
