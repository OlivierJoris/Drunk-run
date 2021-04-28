/*
 * A crate object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __CRATE__
#define __CRATE__

#include "NonDangerousObstacle.hpp"

#include <memory>

// Represents a dangerous obstacle of the game.
class Crate : public NonDangerousObstacle{
    public:
        Crate();
        void test_hit();
};

#endif
