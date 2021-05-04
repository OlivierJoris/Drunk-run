/*
 * Implementation of the renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Renderer.hpp"
#include "Coordinate3D.hpp"

#include <math.h>
#include <memory>

using namespace std;

double Renderer::compute_perspective_x(Coordinate3D& point, shared_ptr<Player> p){
    Coordinate3D eyePos = p->get_position_eye();
    return eyePos.get_x() + (((point.get_x() - eyePos.get_x()) * eyePos.get_z()) 
           / (point.get_z() + eyePos.get_z()));
}

double Renderer::compute_perspective_y(Coordinate3D& point, shared_ptr<Player> p){
    Coordinate3D eyePos = p->get_position_eye();
    return eyePos.get_y() + (((point.get_y() - eyePos.get_y()) * eyePos.get_z()) / (point.get_z() + eyePos.get_z()));
}

Coordinate3D Renderer::from_perspective_to_window(
    Coordinate3D persepctive,
    shared_ptr<Window> w)
{
    Coordinate3D windowCoord;
    double widthRatio = static_cast<double>(w->get_width()) / static_cast<double>(540);
    double heightRatio = static_cast<double>(w->get_height()) / static_cast<double>(405);

    windowCoord.set_x(persepctive.get_x() * widthRatio + (static_cast<double>(w->get_width()) / 2.0));
    windowCoord.set_y((static_cast<double>(w->get_height()) / 2.0) - (persepctive.get_y() * heightRatio));
    windowCoord.set_z(0.0);

    return windowCoord;
}
