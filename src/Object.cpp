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

Object::Object(const unsigned int height, const unsigned int width, 
               const unsigned int depth, const uint8_t r, const uint8_t g, 
               const uint8_t b){
    size = std::make_shared<Size3D>(height, width, depth);
    topleft = std::make_shared<Coordinate3D>();
    color = std::make_shared<RGBColor>(r, g, b);
}

void Object::set_coordinates(double x, double y, double z){
    topleft->set_x(x);
    topleft->set_y(y);
    topleft->set_z(z);
}

void Object::draw() const{}
