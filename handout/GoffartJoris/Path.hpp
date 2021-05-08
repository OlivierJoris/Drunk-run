/*
 * A path of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PATH__
#define __PATH__

#include "Object.hpp"

class Path: public Object{

public:
    // Default width in cm.
    static const unsigned int DEFAULT_WIDTH = 400;

    // Constructor.
    Path(const unsigned int width = DEFAULT_WIDTH);

    /* Draws the path.
     *
     * @param w Pointer to window in which the object will be drawn.
     * @param p Pointer to player which is viewing the object.
     */
    virtual void draw(std::shared_ptr<Window>, std::shared_ptr<Player>) const {};

    /*
     * Tests if the player is going to trip on the obstacle.
     *
     * @param player The player.
     * 
     * @return 1 The player is going to trip.
     *         0 The player is not going to trip.
     *         -1 Error.
     */
    virtual int test_hit(std::shared_ptr<Player>) const {return 0;};

    // Returns the width of the path.
    double get_width() const;
};

#endif
