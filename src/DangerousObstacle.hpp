/*
 * A dangerous obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __DANGEROUS_OBSTACLE__
#define __DANGEROUS_OBSTACLE__

#include "Obstacle.hpp"

#include <memory>

// Represents a dangerous obstacle of the game.
class DangerousObstacle : public Obstacle{
    public:
        // Constructor.
        DangerousObstacle();

       /* Constructor.
        *
        * @param height : height of the obstacle.
        * @param width : width of the obstacle.
        * @param depth : depth of the obstacle.
        * @param r : red value of the obstacle color.
        * @param g : green value of the obstacle color.
        * @param b : blue value of the obstacle color.
        */
        DangerousObstacle(const unsigned int height, const unsigned int width, 
             const unsigned int depth, const uint8_t r, const uint8_t g, 
             const uint8_t b);
             
};

#endif
