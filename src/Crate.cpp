/*
 * Implementation of the crate object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Crate.hpp"

#include <iostream>

using namespace std;

// 45x18x30 cm³ yellow obstacle
Crate::Crate():NonDangerousObstacle(45, 18, 30, 255, 255, 0){
    // to fill
}

void Crate::test_hit(){

}

void Crate::draw() const{
    cout << "crate" << endl;
}