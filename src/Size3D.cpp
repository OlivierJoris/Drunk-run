/*
 * Implementation of the Size3D.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Size3D.hpp"

Size3D::Size3D(){}

Size3D::Size3D(const unsigned int height, const unsigned int width, 
               const unsigned int depth):height{height}, width{width}, depth{depth}{
}

void Size3D::set_height(const unsigned int height){
    Size3D::height = height;
}

unsigned int Size3D::get_height() const{
    return Size3D::height;
}

void Size3D::set_width(const unsigned int width){
    Size3D::width = width;
}

unsigned int Size3D::get_width() const{
    return Size3D::width;
}
   
void Size3D::set_depth(const unsigned int depth){
    Size3D::depth = depth;
}
    
unsigned int Size3D::get_depth() const{
    return Size3D::depth;
}
