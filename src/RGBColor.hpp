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
    RGBColor(uint8_t r, uint8_t g, uint8_t b);

    /*
     * Sets the value for the red component.
     *
     * @param r New value for the red component.
     */
    void set_red(uint8_t r);
    /*
     * Gets the value for the red component.
     *
     * @return Value for the red component.
     */
    uint8_t get_red() const;

    /*
     * Sets the value for the green component.
     *
     * @param r New value for the green component.
     */
    void set_green(uint8_t g);
    /*
     * Gets the value for the green component.
     *
     * @return Value for the green component.
     */
    uint8_t get_green() const;

    /*
     * Sets the value for the blue component.
     *
     * @param r New value for the blue component.
     */
    void set_blue(uint8_t b);
    /*
     * Gets the value for the blue component.
     *
     * @return Value for the blue component.
     */
    uint8_t get_blue() const;

private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#endif
