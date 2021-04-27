/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Object.hpp"

#include <memory>

Object::Object(){
    size = std::make_shared<Size3D>();
    topleft = std::make_shared<Coordinate3D>();
    color = std::make_shared<RGBColor>();
}

void Object::draw(){
    // TO DO: fill
}
