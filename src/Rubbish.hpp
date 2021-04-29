/*
 * A rubbish obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __RUBBISH__
#define __RUBBISH__

#include "NonDangerousObstacle.hpp"

// Represents a rubbish of the game.
class Rubbish : public NonDangerousObstacle{ // to fill

public:
    // Constructor.
    Rubbish();
    // Tests if the obstacle hit the player.
    void test_hit();

    // Draws the rubbish.
    virtual void draw() const;
};

#endif