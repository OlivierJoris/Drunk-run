/*
 * Implementation of a color of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "RGBColor.hpp"

#include <cstdint>
  
void RGBColor::set_red(uint8_t r){
    red = r;
}

uint8_t RGBColor::get_red() const{
    return red;
}

void RGBColor::set_green(uint8_t g){
    green = g;
}

uint8_t RGBColor::get_green() const{
    return green;
}

void RGBColor::set_blue(uint8_t b){
    blue = b;
}

uint8_t RGBColor::get_blue() const{
    return blue;
}
