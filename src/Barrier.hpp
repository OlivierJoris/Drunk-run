/*
 * A barrier object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __BARRIER__
#define __BARRIER__

#include "DangerousObstacle.hpp"

#include <memory>

// Represents a barrier object of the game.
class Barrier : public DangerousObstacle{
    public:
        Barrier();
        void test_hit();
};

#endif
