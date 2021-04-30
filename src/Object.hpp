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
     * Constructor.
     *
     * @param height Height of the object.
     * @param width Width of the object.
     * @param depth Depth of the object.
     * @param r Red value of the object color.
     * @param g Green value of the object color.
     * @param b Blue value of the object color.
     * @param x X coordinate of top left corner.
     * @param y Y coordinate of top left corner.
     * @param z Z coordinate of top left corner.
     */
    Object(
        const unsigned int height,
        const unsigned int width,
        const unsigned int depth,
        const uint8_t r,
        const uint8_t g, 
        const uint8_t b,
        const double x = 0.0,
        const double y = 0.0,
        const double z = 0.0
    );
        
    /*
     * Default destructor.
     */
    virtual ~Object() = default;

    /*
     * Sets the 3D coordinates of the object.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param z Z coordinate.
     */
    void set_coordinates(double x, double y, double z);
           
    // Draws the object.
    virtual void draw() const;

protected:
    // Size of the object.
    std::shared_ptr<Size3D> size;
    // 3D coordinates of the top left corner of the object.
    std::shared_ptr<Coordinate3D> topleft;
    // RGB color of the obstacle.
    std::shared_ptr<RGBColor> color;
};

#endif
