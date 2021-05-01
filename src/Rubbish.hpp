/*
 * A rubbish obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __RUBBISH__
#define __RUBBISH__

#include "NonDangerousObstacle.hpp"

// Represents a rubbish of the game.
class Rubbish: public NonDangerousObstacle{ // to fill

public:
    // Default height of the player in cm.
    static const unsigned int DEFAULT_HEIGHT = 18;
    // Default width of the player in cm.
    static const unsigned int DEFAULT_WIDTH = 45;
    // Default depth of the player in cm.
    static const unsigned int DEFAULT_DEPTH = 30;
    // Default color - red.
    static const uint8_t DEFAULT_RED = 255;
    // Default color - green.
    static const uint8_t DEFAULT_GREEN = 153;
    // Default color - blue.
    static const uint8_t DEFAULT_BLUE = 51;

    // Constructor.
    Rubbish(
        const unsigned int height = DEFAULT_HEIGHT,
        const unsigned int width = DEFAULT_WIDTH,
        const unsigned int depth = 0,
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
    Rubbish(const double x, const double y, const double z);

    /*
     * Tests if the obstacle hit the player.
     *
     * @param player The player.
     * 
     * @return 1 if player hit the obstacle.
     *         0 if player did not hit obstacle.
     *         -1 error.
     */
    virtual int test_hit(std::shared_ptr<Player> player) const;

    // Draws the rubbish.
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const;
};

#endif
