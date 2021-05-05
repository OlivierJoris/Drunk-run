/*
 * Implementation of the kerb object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Kerb.hpp"
#include "Object.hpp"
#include "DangerousObstacle.hpp"
#include "Player.hpp"
#include "Window.hpp"

#include <iostream>
#include <cmath>

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
    shared_ptr<Coordinate3D> playerPos = player->get_coordinates();
    if(!playerPos)
        return -1;

    return abs(playerPos->get_x()) >= abs(topLeft->get_x());
}

void Kerb::draw(shared_ptr<Window> w, shared_ptr<Player> p) const{
    Object::draw(w, p);
}
