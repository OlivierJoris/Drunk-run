/*
 * Implementation of the path object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Path.hpp"

#include <iostream>

using namespace std;

// The path does not really have height and the depth is infinite.
Path::Path(): Object(0, DEFAULT_WIDTH, 0, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR){
    set_coordinates(-200, -202.5, 0);
}

void Path::draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const{
    //temporary
    cout << "path" << endl;
}