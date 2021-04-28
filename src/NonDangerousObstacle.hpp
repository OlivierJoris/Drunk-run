/*
 * An object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __NON_DANGEROUS_OBSTACLE__
#define __NON_DANGEROUS_OBSTACLE__

#include "Obstacle.hpp"

#include <memory>

// Represents a non-dangerous obstacle of the game.
class NonDangerousObstacle : public Obstacle{
    public:
        // Constuctor.
        NonDangerousObstacle();
        
       /* Constructor.
        *
        * @param height : height of the obstacle.
        * @param width : width of the obstacle.
        * @param depth : depth of the obstacle.
        * @param r : red value of the obstacle color.
        * @param g : green value of the obstacle color.
        * @param b : blue value of the obstacle color.
        */
        NonDangerousObstacle(const unsigned int height, const unsigned int width, 
             const unsigned int depth, const uint8_t r, const uint8_t g, 
             const uint8_t b);
};

#endif