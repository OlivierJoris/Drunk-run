/*
 * A path of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PATH__
#define __PATH__

#include "Object.hpp"

class Path: public Object{

public:
    // Default width in cm.
    static const unsigned int DEFAULT_WIDTH = 400;
    // Default color value (grey if used for the 3 components).
    static const uint8_t DEFAULT_COLOR = 128;

    // Constructor.
    Path();

    // Draws the path.
    virtual void draw() const;
};

#endif
