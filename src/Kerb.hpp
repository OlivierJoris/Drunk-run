/*
 * A kerb of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __KERB__
#define __KERB__

#include "DangerousObstacle.hpp"

// Represents a kerb of the game.
class Kerb : public DangerousObstacle{ // to fill

public:
    // Constructor.
    Kerb();
    
    // Test if the obstacle has been hit by the player.
    void test_hit();

    // Draws the kerb.
    virtual void draw() const;
};

#endif
