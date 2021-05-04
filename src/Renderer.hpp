/*
 * Renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __RENDERER__
#define __RENDERER__

#include "Player.hpp"
#include "Coordinate3D.hpp"

#include <memory>

class Renderer{

public:

    /*
     * Computes the x perspective coordinate of the given point.
     *
     * @param point The point for which we want the persepctive.
     * @param p The player of the game.
     * 
     * @return The x perspective coordinate.
     */ 
    double static compute_perspective_x(Coordinate3D& point, std::shared_ptr<Player> p);

    /*
     * Computes the y perspective coordinate of the given point
     *
     * @param point The point for which we want the persepctive.
     * @param p The player of the game.
     * 
     * @return The y perspective coordinate.
     */ 
    double static compute_perspective_y(Coordinate3D& point, std::shared_ptr<Player> p);

    /*
     * Computes the window coordinates of the given point.
     *
     * @param point The point for which we want the window coordinate.
     * @param w The window of the game.
     * 
     * @return Window coordinates of the given point.
     */
    Coordinate3D static from_perspective_to_window(Coordinate3D point, std::shared_ptr<Window> w, std::shared_ptr<Player> p);
};

#endif
