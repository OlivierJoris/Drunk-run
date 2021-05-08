/*
 * A three dimensional size.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __SIZE_3D__
#define __SIZE_3D__

// Represents a three dimensional size.
class Size3D{ 

public:

    /* Constructor.
     *
     * @param height Height of the 3D size.
     * @param width Width of the 3D size.
     * @param depth Depth of the 3D size.
     */
    Size3D(
        const unsigned int height = 0.0,
        const unsigned int width = 0.0,
        const unsigned int depth = 0.0
    );

    // Setter of the height field.
    void set_height(const unsigned int height);

    // Getter of the height field.
    unsigned int get_height() const;

    // Setter of the width field.
    void set_width(const unsigned int width);

    // Getter of the width field.
    unsigned int get_width() const;

    // Setter of the depth field.
    void set_depth(const unsigned int depth);

    // Getter of the depth field.
    unsigned int get_depth() const;

private:
    unsigned int height;
    unsigned int width;
    unsigned int depth;
};

#endif
