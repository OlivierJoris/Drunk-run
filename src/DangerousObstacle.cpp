/*
 * Implementation of the dangerous obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "DangerousObstacle.hpp"

#include <memory>

DangerousObstacle::DangerousObstacle(): Obstacle(){}

DangerousObstacle::DangerousObstacle(
    const unsigned int height,
    const unsigned int width,
    const unsigned int depth,
    const uint8_t r,
    const uint8_t g,
    const uint8_t b,
    const double x,
    const double y,
    const double z
): Obstacle(height, width, depth, r, g, b, x, y, z){}
