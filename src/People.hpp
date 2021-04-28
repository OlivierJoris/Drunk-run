/*
 * A people obstacle of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __PEOPLE__
#define __PEOPLE__

#include "DangerousObstacle.hpp"

#include <memory>

// Represents a dangerous obstacle of the game.
class People : public DangerousObstacle{
    public:
        People();
        void test_hit();
};

#endif
