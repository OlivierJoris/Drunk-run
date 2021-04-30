/*
 * Implementation of the barrier object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Barrier.hpp"
#include "DangerousObstacle.hpp"
#include "Player.hpp"

#include <iostream>
#include <memory>

using namespace std;

Barrier::Barrier(
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

int Barrier::test_hit(shared_ptr<Player>) const{
    // temporary
    return 0;
}

void Barrier::draw() const{
    // temporary
    cout << "barrier" << endl;
}
