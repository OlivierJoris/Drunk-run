/*
 * Renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __RENDERER__
#define __RENDERER__

#include "Player.hpp"

class Renderer{

public:
    // Constuctor.
    Renderer();

    /* Converts a value from cm to pixel.
     *
     * @param value : The value to convert.
     * 
     * @return The value in pixel.
     */ 
    double static from_cm_to_pixel_x(double x, std::shared_ptr<Player> p);

    /* Converts a x coord (in pixel) from the centered coordinate system to 
     * the window coordinate system.
     *
     * @param x : The x value to convert.
     * @param window_width : The window width.
     * 
     * @return The converted x value (in pixel).
     */ 
    double static x_to_window_coordinate(double x, unsigned int window_width);

    /* Converts a y coord (in pixel) from the centered coordinate system to 
     * the window coordinate system.
     *
     * @param y : The y value to convert.
     * @param window_height : The window height.
     * 
     * @return The converted y value (in pixel).
     */ 
    double static y_to_window_coordinate(double y, unsigned int window_height);

    /* Computes the x perspective coordinate given the x and z 3D coordinates.
     *
     * @param x : the given x 3D coordinate.
     * @param z : the given z 3D coordinate.
     * @param p : pointer to player.
     * 
     * @return The x perspective coordinate.
     */ 
    double static compute_perspective_x(double x, double z, std::shared_ptr<Player> p);

    /* Computes the y perspective coordinate given the y and z 3D coordinates.
     *
     * @param y : the given y 3D coordinate.
     * @param z : the given z 3D coordinate.
     * 
     * @return The y perspective coordinate.
     */ 
    double static compute_perspective_y(double y, double z);

    double getScreenWidth(std::shared_ptr<Player> p);

    double getScreenHeight(std::shared_ptr<Player> p);

    double from_cm_to_pixel_x(double x, std::shared_ptr<Window> w, std::shared_ptr<Player> p);

    double from_cm_to_pixel_y(double y, std::shared_ptr<Window> w, std::shared_ptr<Player> p);

private:
    // in cm                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    constexpr static double DISTANCE_EYE_GROUND = 170.0;
    // in cm
    constexpr static double DISTANCE_EYE_SCREEN = 20.0;
    // Ratio between width and height of the screen
    constexpr static double ASPECT_RATIO = 1.33333333333333333333;
};

#endif
