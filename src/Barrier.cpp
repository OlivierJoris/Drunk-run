/*
 * Implementation of the barrier object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#include "Barrier.hpp"

#include <memory>

// 120x90x20 cm³ red obstacle
Barrier::Barrier():DangerousObstacle(120, 90, 20, 255, 0, 0){}

void Barrier::test_hit(){}
