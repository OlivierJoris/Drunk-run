/*
 * Implementation of the crate object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Crate.hpp"
#include "NonDangerousObstacle.hpp"

#include <iostream>

using namespace std;

Crate::Crate(
    const unsigned int height,
    const unsigned int width,
    const unsigned int depth,
    const uint8_t r,
    const uint8_t g,
    const uint8_t b,
    const double x,
    const double y,
    const double z
): NonDangerousObstacle(height, width, depth, r, g, b, x, y, z){}

Crate::Crate(const double x, const double y, const double z)
: NonDangerousObstacle(
    DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_DEPTH,
    DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE,
    x, y, z
){}

int Crate::test_hit(shared_ptr<Player> player) const {
    // temporary
    return 0;
}

void Crate::draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const{
    Object::draw(w, p);
    // cout << "crate" << endl;
}
