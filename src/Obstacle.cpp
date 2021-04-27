/*
 * Implementation of the obstacle class of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#include "Obstacle.hpp"

#include <memory>

Obstacle::Obstacle(){
    object = std::make_shared<Object>();
}
