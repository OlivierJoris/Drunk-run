/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */
#include "People.hpp"

#include <iostream>
#include <memory>

using namespace std;

// 40x180x40 cm³ blue obstacle.
People::People():DangerousObstacle(40, 180, 40, 0, 0, 255){}

void People::test_hit(){}

void People::draw() const{
    // temporary
    cout << "people" << endl;
}