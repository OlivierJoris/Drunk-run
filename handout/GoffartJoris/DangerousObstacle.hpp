/*
 * A dangerous obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __DANGEROUS_OBSTACLE__
#define __DANGEROUS_OBSTACLE__

#include "Obstacle.hpp"
#include "Player.hpp"
#include "Window.hpp"

#include <memory>

// Represents a dangerous obstacle of the game.
class DangerousObstacle: public Obstacle{

public:
    // Number of different random dangerous obstacles (barrier, person).
    static const unsigned int NB_RANDOM_D_OBSTACLES = 2;

    // Constructor.
    DangerousObstacle();

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
    DangerousObstacle(
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
    virtual ~DangerousObstacle() = default;

    /* Draws the obstacle.
     *
     * @param w Pointer to window in which the object will be drawn.
     * @param p Pointer to player which is viewing the object.
     */
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const = 0;

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
