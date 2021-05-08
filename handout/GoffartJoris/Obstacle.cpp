/*
 * Implementation of the obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Obstacle.hpp"
#include "Object.hpp"

Obstacle::Obstacle(): Object(){}

Obstacle::Obstacle(
    const unsigned int height,
    const unsigned int width,
    const unsigned int depth,
    const uint8_t r,
    const uint8_t g,
    const uint8_t b,
    const double x,
    const double y,
    const double z
): Object(height, width, depth, r, g, b, x, y, z){}
