/*
 * Implementation of the non dangerous obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#include "NonDangerousObstacle.hpp"

#include <memory>

NonDangerousObstacle::NonDangerousObstacle():Obstacle(){}

NonDangerousObstacle::NonDangerousObstacle(const unsigned int height, const unsigned int width, 
             const unsigned int depth, const uint8_t r, const uint8_t g, 
             const uint8_t b):Obstacle(height, width, depth, r, g, b){}