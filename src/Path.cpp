/*
 * Implementation of the path object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Path.hpp"

#include <iostream>

using namespace std;

// The path does not really have height and the depth is infinite.
Path::Path(const unsigned int width): Object(0, width, 0, 0, 0, 0){}

double Path::get_width() const{
    return static_cast<double>(size->get_width());
}
