/*
 * A color of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __RGB_COLOR__
#define __RGB_COLOR__

#include <cstdint>

// Represents a RGB color.
class RGBColor{

public:
    /*
     * Constructor.
     *
     * @param r Value for red component.
     * @param g Value for green component.
     * @param b Value for blue component.
     */
    RGBColor(const uint8_t r = 0, const uint8_t g = 0, const uint8_t b = 0);

    /*
     * Sets the value for the red component.
     */
    void set_red(const uint8_t r);
    /*
     * Gets the value for the red component.
     */
    uint8_t get_red() const;

    /*
     * Sets the value for the green component.
     */
    void set_green(const uint8_t g);
    /*
     * Gets the value for the green component.
     */
    uint8_t get_green() const;

    /*
     * Sets the value for the blue component.
     */
    void set_blue(const uint8_t b);
    /*
     * Gets the value for the blue component.
     */
    uint8_t get_blue() const;

private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#endif
