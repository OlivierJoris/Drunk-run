/*
 * A three dimensional coordinate.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __COORDINATE_3D__
#define __COORDINATE_3D__

// Represents a coordinate in three dimensions.
class Coordinate3D{

public:
    // Constructor.
    Coordinate3D();

    /* Constructor.
     *
     * @param x X 3D coordinate.
     * @param y Y 3D coordinate.
     * @param z Z 3D coordinate.
     */
    Coordinate3D(const double x, const double y, const double z);

    // Setter of the x field.
    void set_x(const double x);

    // Getter of the x field.
    double get_x() const;

    // Setter of the y field.
    void set_y(const double y);

    // Getter of the y field.
    double get_y() const;

    // Setter of the z field.
    void set_z(const double z);

    // Getter of the z field.
    double get_z() const;

private:
    double x;
    double y;
    double z;
};

#endif
