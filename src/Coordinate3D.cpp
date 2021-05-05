/*
 * Implementation of the Coordinate3D class.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Coordinate3D.hpp"

#include <iostream>

using namespace std;

Coordinate3D::Coordinate3D(
    const double x,
    const double y,
    const double z
):x{x}, y{y}, z{z} {}

void Coordinate3D::set_x(const double x){
    Coordinate3D::x = x;
}

double Coordinate3D::get_x() const{
    return x;
}

void Coordinate3D::set_y(const double y){
    Coordinate3D::y = y;
}

double Coordinate3D::get_y() const{
    return y;
}

void Coordinate3D::set_z(const double z){
    Coordinate3D::z = z;
}

double Coordinate3D::get_z() const{
    return z;
}
