/*
 * Implementation of the rubbish object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Rubbish.hpp"
#include "NonDangerousObstacle.hpp"

#include <iostream>

using namespace std;

Rubbish::Rubbish(
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

Rubbish::Rubbish(const double x, const double y, const double z)
: NonDangerousObstacle(
    DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_DEPTH,
    DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE,
    x, y, z
){}

int Rubbish::test_hit(shared_ptr<Player> player) const {
    return NonDangerousObstacle::test_hit(player);
}

void Rubbish::draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const{
    Object::draw(w, p);
}
