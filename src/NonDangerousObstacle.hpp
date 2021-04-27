/*
 * An object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#ifndef __NON_DANGEROUS_OBSTACLE__
#define __NON_DANGEROUS_OBSTACLE__

#include "Obstacle.hpp"

#include <memory>

// Represents a non-dangerous obstacle of the game.
class NonDangerousObstacle : public Obstacle{
    public:
        NonDangerousObstacle();
};

#endif