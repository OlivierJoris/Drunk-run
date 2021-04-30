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

int Rubbish::test_hit(shared_ptr<Player> player) const {
    // temporary
    return 0;
}

void Rubbish::draw() const{
    // temporary
    cout << "rubbish" << endl;
}
