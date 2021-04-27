/*
 * Implementation of the Coordinate3D class.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Coordinate3D.hpp"

Coordinate3D::Coordinate3D(double x, double y, double z):x{x}, y{y}, z{z}{
}

void Coordinate3D::set_x(double x){
    Coordinate3D::x = x;
}

double Coordinate3D::get_x() const{
    return Coordinate3D::x;
}

void Coordinate3D::set_y(double y){
    Coordinate3D::y = y;
}

double Coordinate3D::get_y() const{
    return Coordinate3D::y;
}

void Coordinate3D::set_z(double z){
    Coordinate3D::z = z;
}

double Coordinate3D::get_z() const{
    return Coordinate3D::z;
}
