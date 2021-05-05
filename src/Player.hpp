/*
 * The player (Cymi) of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __PLAYER__
#define __PLAYER__

#include "Object.hpp"

#include <memory>

class Player: public Object{

public:

    // Default height of the player in cm.
    static const unsigned int DEFAULT_HEIGHT = 180;
    // Default width of the player in cm.
    static const unsigned int DEFAULT_WIDTH = 40;
    // Default depth of the player in cm.
    static const unsigned int DEFAULT_DEPTH = 40;
    // Default distance eye ground in cm.
    static const unsigned int DEFAULT_DISTANCE_EYE_GROUND = 170;
    // Default distance eye screen in cm.
    static const unsigned int DEFAULT_DISTANCE_EYE_SCREEN = 20;
    // Default Fov in degrees.
    static const unsigned int DEFAULT_FOV = 60;
    // Default DoV in cm.
    static const unsigned int DEFAULT_DOV = 15000;
    // Default number of secs between 2 drunk movs.
    static const unsigned int DEFAULT_DRUNK_MOV_RATE = 2;

    /*
     * Constructor.
     *
     * @param fov Field of view of the player in degrees.
     * @param dov Depth of view of the player in degrees.
     * @param drunkMovRate Drunk movement rate.
     */
    Player(
        const unsigned int fov = DEFAULT_FOV,
        const unsigned int dov = DEFAULT_DOV,
        const unsigned int drunkMovRate = DEFAULT_DRUNK_MOV_RATE,
        const unsigned int distanceEyeGround = DEFAULT_DISTANCE_EYE_GROUND,
        const unsigned int distanceEyeScree = DEFAULT_DISTANCE_EYE_SCREEN
    );

    // Draws the player.
    virtual void draw(std::shared_ptr<Window>, std::shared_ptr<Player>) const {};

    virtual int test_hit(std::shared_ptr<Player>) const {return 0;};

    /*
     * Increases/Decreases the position of the player on the x axis.
     */
    void increase_x_position(const double increase);

    /*
     * Player goes forward with a movement of size increase.
     */
    void player_goes_forward(const double increase);

    /*
     * Player does one movement to the left.
     */
    void player_goes_left();

    /*
     * Player does one movement to the right.
     */
    void player_goes_right();

    /*
     * Returns the minimum size of a movement of the player.
     */
    unsigned int get_min_movement_range() const;

    /*
     * Returns the maximum size of a movement of the player.
     */
    unsigned int get_max_movement_range() const;

    /*
     * Returns the rate of random movement.
     */
    unsigned int get_movement_rate() const;

    /*
     * Returns the size of a movement.
     */
    unsigned int get_movement_size() const;

    /*
     * Returns the height of the eye from the ground.
     */
    unsigned int get_distance_eye_ground() const;

    /*
     * Returns the distance between the eye and the screen.
     */
    unsigned int get_distance_eye_screen() const;

    /*
     * Returns the position of the eye.
     */
    Coordinate3D get_position_eye() const;

    /*
     * Returns the fov of the player.
     */
    unsigned get_fov() const;

    /*
     * Returns the dov of the player.
     */
    unsigned int get_dov() const;

private:
    // FOV in degrees.
    unsigned int fov;
    // DOV in cm.
    unsigned int dov;
    // Number of seconds between 2 drunk movs.
    unsigned int drunkMovRate;
    // Height between eye and ground in cm.
    unsigned int distanceEyeGround;
    // Distance between eye and screen in cm.
    unsigned int distanceEyeScreen;

    // cm per second.
    const unsigned int SPEED = 100;
    // Min range for drunk movement.
    const unsigned int MIN_RANGE_MOVEMENT = 1;
    // Max range for drunk movement.
    const unsigned int MAX_RANGE_MOVEMENT = 6;
    // Size of a movement in cm.
    const double LATERAL_MOVEMENT_SIZE = 5;
};

#endif
