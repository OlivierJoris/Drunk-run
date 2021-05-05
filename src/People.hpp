/*
 * A people obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PEOPLE__
#define __PEOPLE__

#include "DangerousObstacle.hpp"
#include "Window.hpp"
#include "Player.hpp"

#include <memory>

// Represents a people obstacle of the game.
class People: public DangerousObstacle{

public:
    // Default height of the player in cm.
    static const unsigned int DEFAULT_HEIGHT = 180;
    // Default width of the player in cm.
    static const unsigned int DEFAULT_WIDTH = 40;
    // Default depth of the player in cm.
    static const unsigned int DEFAULT_DEPTH = 40;
    // Default color - red.
    static const uint8_t DEFAULT_RED = 0;
    // Default color - green.
    static const uint8_t DEFAULT_GREEN = 0;
    // Default color - blue.
    static const uint8_t DEFAULT_BLUE = 255;

    // Constructor.
    People(
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
    People(const double x, const double y, const double z);

    // Draws the person.
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
