/*
 * Implementation of the kerb object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Kerb.hpp"
#include "DangerousObstacle.hpp"

#include <iostream>

using namespace std;

Kerb::Kerb(
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

int Kerb::test_hit(shared_ptr<Player> player) const {
    // temporary
    return 0;
}

void Kerb::draw() const{
    // temporary
    cout << "kerb" << endl;
}
