/*
 * An obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __OBSTACLE__
#define __OBSTACLE__

#include "Object.hpp"
#include "Player.hpp"

#include <memory>

// Represents an obstacle of the game.
class Obstacle: public Object{ 

public:
    // Number of different random obstacles (barrier, person, rubish, crate).
    static const unsigned int NB_RANDOM_OBSTACLES = 4;

    // Constructor.
    Obstacle();
    
    /* Constructor.
     *
     * @param height Height of the obstacle.
     * @param width Width of the obstacle.
     * @param depth Depth of the obstacle.
     * @param r Red value of the obstacle color.
     * @param g Green value of the obstacle color.
     * @param b Blue value of the obstacle color.
     * @param x X coordinate of top left corner.
     * @param y Y coordinate of top left corner.
     * @param z Z coordinate of top left corner.
     */
    Obstacle(
        const unsigned int height,
        const unsigned int width,
        const unsigned int depth,
        const uint8_t r,
        const uint8_t g,
        const uint8_t b,
        const double x = 0.0,
        const double y = 0.0,
        const double z = 0.0
    );

    /* Draws the obstacle.
     *
     * @param w pointer to window in which the object will be drawn.
     * @param p pointer to player which is viewing the object.
     */
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const = 0;

    /*
     * Tests if the obstacle hit the player.
     *
     * @param player The player.
     * 
     * @return 1 if player hit the obstacle.
     *         0 if player did not hit obstacle.
     *         -1 error.
     */
    virtual int test_hit(std::shared_ptr<Player> player) const = 0;
};

#endif
