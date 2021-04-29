/*
 * A people obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __PEOPLE__
#define __PEOPLE__

#include "DangerousObstacle.hpp"

#include <memory>

// Represents a people obstacle of the game.
class People : public DangerousObstacle{
    public:
        // Constructor.
        People();
        // Test if the obstacle hit the player.
        void test_hit();

        // Draws the person.
        virtual void draw() const;
};

#endif
