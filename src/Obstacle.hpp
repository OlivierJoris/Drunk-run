/*
 * An object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __OBSTACLE__
#define __OBSTACLE__

#include "Object.hpp"

#include <memory>

// Represents an obstacle of the game.
class Obstacle{ 

public:
    Obstacle();
    // Test if the obstacle hit the player
    virtual void test_hit() = 0;

protected:
    // Object composing the obstacle
    std::shared_ptr<Object> object;
};

#endif
