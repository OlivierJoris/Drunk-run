/*
 * An obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __OBSTACLE__
#define __OBSTACLE__

#include "Object.hpp"

#include <memory>

// Represents an obstacle of the game.
class Obstacle : public Object{ 

public:
    // Constructor.
    Obstacle();
    
   /* Constructor.
    *
    * @param height : height of the obstacle.
    * @param width : width of the obstacle.
    * @param depth : depth of the obstacle.
    * @param r : red value of the obstacle color.
    * @param g : green value of the obstacle color.
    * @param b : blue value of the obstacle color.
    */
    Obstacle(const unsigned int height, const unsigned int width, 
             const unsigned int depth, const uint8_t r, const uint8_t g, 
             const uint8_t b);

    // Test if the obstacle hit the player
    virtual void test_hit() = 0;
};

#endif
