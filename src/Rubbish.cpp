/*
 * Implementation of the rubbish object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Rubbish.hpp"

#include <iostream>

using namespace std;

// 15x7x7 cm³ gray obstacle
Rubbish::Rubbish():NonDangerousObstacle(15, 7, 7, 128, 128, 128){
    // to fill
}

void Rubbish::test_hit(){}

void Rubbish::draw() const{
    // temporary
    cout << "rubbish" << endl;
}