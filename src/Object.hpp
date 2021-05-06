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
#include "Window.hpp"

#include <memory>

class Player;

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
    void set_coordinates(const double x, const double y, const double z);

    // Returns the coordinates of the top left corner of the object.
    std::shared_ptr<Coordinate3D> get_coordinates() const;

    // Returns the size of the object.
    std::shared_ptr<Size3D> get_size() const;

    // Returns the color of the object.
    std::shared_ptr<RGBColor> get_color() const;

    /* Draws the object.
     *
     * @param w pointer to window in which the object will be drawn.
     * @param p pointer to player which is viewing the object.
     */
    virtual void draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const;

    /*
     * Tests if the obstacle hit the player.
     *
     * @param player The player.
     * 
     * @return 1 if player hit the obstacle.
     *         0 if player did not hit obstacle.
     *         -1 error.
     */
    virtual int test_hit(std::shared_ptr<Player> player) const = 0;

protected:
    // Size of the object.
    std::shared_ptr<Size3D> size;
    // 3D coordinates of the top left corner of the object.
    std::shared_ptr<Coordinate3D> topLeft;
    // RGB color of the obstacle.
    std::shared_ptr<RGBColor> color;
};

#endif
