/*
 * Implementation of the dangerous obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "DangerousObstacle.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Size3D.hpp"
#include "Coordinate3D.hpp"

#include <cstdint>
#include <memory>

using namespace std;

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

int DangerousObstacle::test_hit(shared_ptr<Player> player) const{
    if(!player)
        return -1;

    shared_ptr<Coordinate3D> playerPos = player->get_coordinates();
    if(!playerPos)
        return -1;
    shared_ptr<Size3D> playerSize = player->get_size();
    if(!playerSize)
        return -1;
    
    if(!topLeft || !size)
        return -1;

    double playerXmin = playerPos->get_x();
    double playerYmin = playerPos->get_y();
    double playerZmin = playerPos->get_z();

    double obstacleXmin = topLeft->get_x();
    double obstacleXmax = obstacleXmin + size->get_width();
    double obstacleYtop = topLeft->get_y();
    double obstacleYbottom = obstacleYtop - size->get_height();
    double obstacleZmin = topLeft->get_z();
    double obstacleZmax = obstacleZmin + size->get_depth();

    bool inObstacleXrange = false, inObstacleYrange = false, inObstacleZrange = false;

    if(playerXmin >= obstacleXmin && playerXmin <= obstacleXmax)
        inObstacleXrange = true;
    if(playerYmin <= obstacleYtop && playerYmin >= obstacleYbottom)
        inObstacleYrange = true;
    if(playerZmin >= obstacleZmin && playerZmin <= obstacleZmax)
        inObstacleZrange = true;

    if(inObstacleXrange && inObstacleYrange && inObstacleZrange)
        return 1;

    return 0;
}
