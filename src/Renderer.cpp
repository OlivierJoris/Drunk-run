/*
 * Implementation of the renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Renderer.hpp"

Renderer::Renderer(){

}

double Renderer::from_cm_to_pixel(double value){
    return value * SCALE;
}

double Renderer::x_to_window_coordinate(double x, unsigned int window_width){
    return x + (window_width / 2);
}

double Renderer::y_to_window_coordinate(double y, unsigned int window_height){
    if(y > 0)
        return (window_height / 2) - y;
    
    return (window_height / 2) + y;
}

double Renderer::compute_perspective_x(double x, double z){
    return (x * from_cm_to_pixel(DISTANCE_EYE_SCREEN)) / (z + from_cm_to_pixel(DISTANCE_EYE_SCREEN));
}

double Renderer::compute_perspective_y(double y, double z){
    return from_cm_to_pixel(DISTANCE_EYE_GROUND) + (((y - from_cm_to_pixel(DISTANCE_EYE_GROUND)) * 
           from_cm_to_pixel(DISTANCE_EYE_SCREEN)) / (z + from_cm_to_pixel(DISTANCE_EYE_SCREEN)));
}
