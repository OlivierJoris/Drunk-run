/*
 * A dangerous obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __NON_DANGEROUS_OBSTACLE__
#define __NON_DANGEROUS_OBSTACLE__

#include "Obstacle.hpp"

#include <memory>

// Represents a non-dangerous obstacle of the game.
class NonDangerousObstacle: public Obstacle{

public:
    // Number of different random non-dangerous obstacles (rubbish, crate).
    static const unsigned int NB_RANDOM_ND_OBSTACLES = 2;

    // Constuctor.
    NonDangerousObstacle();

    /*
     * Constructor.
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
    NonDangerousObstacle(
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

    // Destructor.
    virtual ~NonDangerousObstacle() = default;

    // Draws the obstacle.
    virtual void draw() const = 0;

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