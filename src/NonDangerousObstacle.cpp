/*
 * Implementation of the non dangerous obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "NonDangerousObstacle.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"

#include <memory>

using namespace std;

NonDangerousObstacle::NonDangerousObstacle(): Obstacle(){}

NonDangerousObstacle::NonDangerousObstacle(
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

int NonDangerousObstacle::test_hit(shared_ptr<Player>) const{
    // The player will never trip on a non-dangerous obstacle.
    return 0;
}
