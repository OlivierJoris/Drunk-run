/*
 * Renderer of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __RENDERER__
#define __RENDERER__

#include "Player.hpp"
#include "Window.hpp"
#include "Coordinate3D.hpp"

#include <memory>

class Renderer{

public:
    /*
     * Computes the perspective coordinates of the given point.
     *
     * @param point The point for which we want the persepctive.
     * @param p The player of the game.
     * 
     * @return The perspective coordinats.
     */ 
    static Coordinate3D compute_perspective(
        const Coordinate3D& point,
        std::shared_ptr<Player> p
    );

    /*
     * Computes the window coordinates of the given point.
     *
     * @param point The point for which we want the window coordinates.
     * @param w The window of the game.
     * @param p The player of the game.
     * 
     * @return Window coordinates of the given point.
     */
    static Coordinate3D from_perspective_to_window(
        const Coordinate3D& point,
        std::shared_ptr<Window> w,
        std::shared_ptr<Player> p
    );
};

#endif
