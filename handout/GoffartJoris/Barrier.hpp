/*
 * A barrier object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __BARRIER__
#define __BARRIER__

#include "DangerousObstacle.hpp"

#include <memory>

// Represents a barrier object of the game.
class Barrier: public DangerousObstacle{

public:
    // Default height of the barrier in cm.
    static const unsigned int DEFAULT_HEIGHT = 90;
    // Default width of the barrier in cm.
    static const unsigned int DEFAULT_WIDTH = 120;
    // Default depth of the barrier in cm.
    static const unsigned int DEFAULT_DEPTH = 20;
    // Default color - red.
    static const uint8_t DEFAULT_RED = 255;
    // Default color - green.
    static const uint8_t DEFAULT_GREEN = 0;
    // Default color - blue.
    static const uint8_t DEFAULT_BLUE = 0;

    // Constructor.
    Barrier(
        const unsigned int height = DEFAULT_HEIGHT,
        const unsigned int width = DEFAULT_WIDTH,
        const unsigned int depth = DEFAULT_DEPTH,
        const uint8_t r = DEFAULT_RED,
        const uint8_t g = DEFAULT_GREEN,
        const uint8_t b = DEFAULT_BLUE,
        const double x = 0.0,
        const double y = 0.0,
        const double z = 0.0
    );

    /*
     * Constructor.
     *
     * @param x X coordinate of top left corner.
     * @param y Y coordinate of top left corner.
     * @param z Z coordinate of top left corner.
     */
    Barrier(const double x, const double y, const double z);

    /* Draws the barrier.
     *
     * @param w Pointer to window in which the object will be drawn.
     * @param p Pointer to player which is viewing the object.
     */
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const;

    /*
     * Tests if the player is going to trip on the obstacle.
     *
     * @param player The player.
     * 
     * @return 1 The player is going to trip.
     *         0 The player is not going to trip.
     *         -1 Error.
     */
    virtual int test_hit(std::shared_ptr<Player> player) const;

};

#endif
