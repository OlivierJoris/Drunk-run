/*
 * An object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __DRUNK_RUN_OBJECT__
#define __DRUNK_RUN_OBJECT__

#include "Size3D.hpp"
#include "Coordinate3D.hpp"
#include "RGBColor.hpp"

#include <memory>

// Represents an object of the game.
class Object{ 

public:
    // Constructor.
    Object();
    // Draw the object.
    void draw();

private:
    // Size of the object
    std::shared_ptr<Size3D> size;
    // 3D coordinates of the top left coin of the object
    std::shared_ptr<Coordinate3D> topleft;
    // RGB color of the obstacle
    std::shared_ptr<RGBColor> color;
};


#endif
