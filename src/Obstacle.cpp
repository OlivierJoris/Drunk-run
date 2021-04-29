/*
 * Implementation of the obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#include "Obstacle.hpp"

#include <memory>

Obstacle::Obstacle():Object(){
}

Obstacle::Obstacle(const unsigned int height, const unsigned int width, 
             const unsigned int depth, const uint8_t r, const uint8_t g, 
             const uint8_t b):Object(height, width, depth, r, g, b){}