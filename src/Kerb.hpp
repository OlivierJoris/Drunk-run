/*
 * A kerb of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __KERB__
#define __KERB__

#include "DangerousObstacle.hpp"

// Represents a kerb of the game.
class Kerb: public DangerousObstacle{ // to fill

public:
    // Default height of the player in cm.
    static const unsigned int DEFAULT_HEIGHT = 20;
    // Default width of the player in cm.
    static const unsigned int DEFAULT_WIDTH = 20;
    // Default color - red.
    static const uint8_t DEFAULT_COLOR = 64;

    // Constructor.
    Kerb(
        const unsigned int height = DEFAULT_HEIGHT,
        const unsigned int width = DEFAULT_WIDTH,
        const unsigned int depth = 0,
        const uint8_t r = DEFAULT_COLOR,
        const uint8_t g = DEFAULT_COLOR,
        const uint8_t b = DEFAULT_COLOR,
        const double x = 0.0,
        const double y = 0.0,
        const double z = 0.0
    );
    
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

    // Draws the kerb.
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const;
};

#endif
