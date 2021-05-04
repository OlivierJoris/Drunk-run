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
    return (((point.get_x() - eyePos.get_x()) * p->get_distance_eye_screen()) 
           / (point.get_z() + p->get_distance_eye_screen()));
}

double Renderer::compute_perspective_y(Coordinate3D& point, shared_ptr<Player> p){
    return (((point.get_y() - p->get_distance_eye_ground()) * p->get_distance_eye_screen()) 
           / (point.get_z() + p->get_distance_eye_screen()));
}

Coordinate3D Renderer::from_perspective_to_window(
    Coordinate3D persepctive,
    shared_ptr<Window> w, 
    shared_ptr<Player> p)
{
    Coordinate3D windowCoord;
    double ratio = static_cast<double>(w->get_width()) / 
                   static_cast<double>(tan((p->get_fov() / 2) * 
                   (M_PI / 180)) * 2 * (p->get_distance_eye_screen()));
    
    windowCoord.set_x(persepctive.get_x() * ratio + (static_cast<double>(w->get_width()) / 2.0));
    windowCoord.set_y((static_cast<double>(w->get_height()) / 2.0) - (persepctive.get_y() * ratio));
    windowCoord.set_z(0.0);

    return windowCoord;
}
