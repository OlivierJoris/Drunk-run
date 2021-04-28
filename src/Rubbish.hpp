/*
 * A kerb of the game drunk run.
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
    void test_hit();
};

#endif