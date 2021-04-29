/*
 * A crate object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __CRATE__
#define __CRATE__

#include "NonDangerousObstacle.hpp"

#include <memory>

// Represents a crate object of the game.
class Crate : public NonDangerousObstacle{
    public:
        // Constructor.
        Crate();

        // Tests if the obstacle hit the player.
        void test_hit();

        // Draws the crate.
        virtual void draw() const;
};

#endif
