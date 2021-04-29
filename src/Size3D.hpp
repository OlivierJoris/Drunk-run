/*
 * A three dimensionnal size.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __SIZE_3D__
#define __SIZE_3D__

// Represents a three dimensionnal size.
class Size3D{ 

public:
    // Constructors
    Size3D();

   /* Constructor.
    *
    * @param height : height of the 3D size.
    * @param width : width of the 3D size.
    * @param depth : depth of the 3D size.
    */
    Size3D(const unsigned int height, const unsigned int width, 
           const unsigned int depth);

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
