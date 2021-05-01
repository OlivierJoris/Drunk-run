/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "People.hpp"
#include "Player.hpp"

#include <iostream>
#include <memory>

using namespace std;

People::People(
    const unsigned int height,
    const unsigned int width,
    const unsigned int depth,
    const uint8_t r,
    const uint8_t g,
    const uint8_t b,
    const double x,
    const double y,
    const double z
): DangerousObstacle(height, width, depth, r, g, b, x, y, z){}

People::People(const double x, const double y, const double z)
: DangerousObstacle(
    DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_DEPTH,
    DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE,
    x, y, z
){}

int People::test_hit(shared_ptr<Player>) const {
    // temporary
    return 0;
}

void People::draw() const{
    // temporary
    cout << "people" << endl;
}
