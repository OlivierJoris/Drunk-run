/*
 * The player (Cymi) of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PLAYER__
#define __PLAYER__

#include "Object.hpp"

#include <memory>

class Player: public Object {

public:

    // Default height of the player in cm.
    static const unsigned int DEFAULT_HEIGHT = 180;
    // Default width of the player in cm.
    static const unsigned int DEFAULT_WIDTH = 40;
    // Default depth of the player in cm.
    static const unsigned int DEFAULT_DEPTH = 40;

    // Constuctor.
    Player();

    // Draws the player.
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const {};

    /*
     * Increases/Decreases the position of the player on the x axis.
     *
     * @param increase Value to add to the position on the x axis.
     */
    void increaseXPosition(double increase);

    /*
     * Player goes forward with a movement of size increase.
     *
     * @param increase Increase in depth.
     */
    void player_goes_forward(double increase);

    /*
     * Player does one movement to the left.
     */
    void player_goes_left();

    /*
     * Player does one movement to the right.
     */
    void player_goes_right();

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

    double get_x() const;

    unsigned get_fov() const;

private:
    // FOV in degree.
    const unsigned int FOV = 60; 
    // DOV in cm.
    const unsigned int DOV = 15000;
    // Cm per second.
    const unsigned int SPEED = 100;
    // Min range for drunk movement.
    const unsigned int MIN_RANGE_MOVEMENT = 1;
    // Max range for drunk movement.
    const unsigned int MAX_RANGE_MOVEMENT = 6;
    // Drunk movement in seconds.
    const unsigned int MOVEMENT_RATE = 2;
    // Size of a movement in cm.
    const unsigned int LATERAL_MOVEMENT_SIZE = 5;
};

#endif
