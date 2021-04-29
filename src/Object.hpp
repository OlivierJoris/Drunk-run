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

    /*
     * Default destructor.
     */
    virtual ~Object() = default;

   /* Constructor.
    *
    * @param height : height of the object.
    * @param width : width of the object.
    * @param depth : depth of the object.
    * @param r : red value of the object color.
    * @param g : green value of the object color.
    * @param b : blue value of the object color.
    */
    Object(const unsigned int height, const unsigned int width, 
           const unsigned int depth, const uint8_t r, const uint8_t g, 
           const uint8_t b);

    void set_coordinates(double x, double y, double z);
           
    // Draws the object.
    virtual void draw() const;

protected:
    // Size of the object
    std::shared_ptr<Size3D> size;
    // 3D coordinates of the top left coin of the object
    std::shared_ptr<Coordinate3D> topleft;
    // RGB color of the obstacle
    std::shared_ptr<RGBColor> color;
};

#endif
