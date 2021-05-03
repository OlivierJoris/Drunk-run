/*
 * Implementation of the renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Renderer.hpp"

#include <iostream>
#include <math.h>

Renderer::Renderer(){}

double Renderer::get_screen_width(std::shared_ptr<Player> p){
    return 2.0 * tan((p->get_fov() / 2.0) * (M_PI / 180.0)) * DISTANCE_EYE_SCREEN;
}

double Renderer::get_screen_height(std::shared_ptr<Player> p){
    return get_screen_width(p) * ASPECT_RATIO;
}

double Renderer::from_cm_to_pixel_x(double x, std::shared_ptr<Window> w, 
                                    std::shared_ptr<Player> p){
    return w->DEFAULT_WIDTH * (x / get_screen_width(p));
}

double Renderer::from_cm_to_pixel_y(double y, std::shared_ptr<Window> w, 
                                    std::shared_ptr<Player> p){
    return w->DEFAULT_HEIGHT * (y / get_screen_height(p));
}

double Renderer::x_to_window_coordinate(double x, unsigned int window_width){
    return x + (window_width / 2.0);
}

double Renderer::y_to_window_coordinate(double y, unsigned int window_height){
    return (window_height / 2.0) - y;
}

double Renderer::compute_perspective_x(double x, double z, std::shared_ptr<Player> p){
    return p->get_x() + (((x - p->get_x()) * DISTANCE_EYE_SCREEN) 
           / (z + DISTANCE_EYE_SCREEN));
}

double Renderer::compute_perspective_y(double y, double z, std::shared_ptr<Player> p){
    double screen_height = get_screen_height(p);

    return (DISTANCE_EYE_GROUND - (screen_height / 2)) + (((y - (DISTANCE_EYE_GROUND 
           - (screen_height / 2))) * DISTANCE_EYE_SCREEN) / (z + DISTANCE_EYE_SCREEN));
}
