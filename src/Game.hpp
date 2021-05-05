/*
 * The game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __GAME__
#define __GAME__

#include "GameState.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Path.hpp"
#include "Kerb.hpp"

#include <memory>
#include <list>
#include <vector>
#include <random>

// Represents the game of drunk run.
class Game{

public:
    // Default frame rate for the game.
    static const unsigned int DEFAULT_FRAME_RATE = 30;
    // Default dangerous obstacles rate (base 10).
    static const unsigned int DEFAULT_DANGEROUS_RATE = 3;
    // Default clearing distance before first obstacle.
    constexpr static const double DEFAULT_CLEARANCE = 600.0;

    /*
     * Constructor.
     *
     * @param frameRate Frame rate of the game.
     * @param clearingDistance Clearing distance before first obstacle.
     * @param dangerousRate Dangerous obstacles rate.
     */
    Game(
        unsigned int frameRate = DEFAULT_FRAME_RATE,
        double clearingDistance = DEFAULT_CLEARANCE,
        double dangerousRate = DEFAULT_DANGEROUS_RATE
    );

    /*
     * Draws the game on the given window.
     *
     * @param w The window on which to draw the game.
     * 
     * @return 0 no error. Else, error while drawing the game.
     */
    int draw(std::shared_ptr<Window> w);

    /*
     * Tests if the player tripped on something or not.
     * 
     * @return 1 The player tripped.
     *         0 The player did not tripped.
     *         -1 Error.
     */
    int test_hit() const;

    /*
     * Returns the state of the game.
     *
     * @return State of the game.
     */
    std::shared_ptr<GameState> get_game_state() const;

    /*
     * Returns the status of the game.
     *
     * @return The status of the game.
     */
    GameStateStatus get_game_status() const;

    /*
     *  Sets the status (running or end) of the game.
     *
     * @param status The new status of the game.
     */
    void set_game_status(GameStateStatus status);

    /*
     * Returns the player of the game.
     *
     * @return Player of the game.
     */
    std::shared_ptr<Player> get_player() const;

    /*
     * Returns the path of the game.
     *
     * @return Path of the game.
     */
    std::shared_ptr<Path> get_path() const;

    /*
     * Returns the vector of kerbs of the game.
     *
     * @return Vector of kerbs.
     */
    const std::vector<Kerb>& get_kerbs() const;

    /*
     * Returns the list of obstacles of the game.
     *
     * @return List of obstacles as objects.
     */
    const std::list<std::shared_ptr<Object>>& get_obstacles() const;

    // Adds the first obstacles.
    void add_init_obstacles();

    /*
     * Adds a new randomly generated obstacle.
     */
    void add_random_obstacle();

    // Moves the obstacles forward by a given distance.
    void move_obstacles_forward(double decrease);

    /*
     * Returns the fixed frame rate of the game.
     *
     * @return Fixed frame rate.
     */
    unsigned int get_frame_rate() const;

    /*
     * Returns the clearing distance of the game.
     *
     * @return Clearing distance.
     */
    double get_clearance_dist() const;

    /*
     * Returns the rate of dangerous obstacle.
     *
     * @return Rate of dangerous obstacle.
     */
    double get_distribution_dangerous() const;

    /*
     * Increments the score by a given amount.
     *
     * @param Increment for the score.
     */
    void increment_score(const double increment) const;

    /*
     * Returns a random number in [0, upperLimit[.
     *
     * @return Random number in [0, upperlimit[.
     */
    unsigned int get_random(unsigned int upperLimit);

    /*
     * Generates a random movement of the player (Cymi).
     */
    void player_random_movement();


private:
    // State of the game.
    std::shared_ptr<GameState> state;

    // Player of the game.
    std::shared_ptr<Player> player;

    // Path/road of the game.
    std::shared_ptr<Path> path;

    // Left & right kerb of the path/road.
    std::vector<Kerb> kerbs;

    // Obstacles on the path/road.
    std::list<std::shared_ptr<Object>> obstacles;

    // Random number generator.
    std::minstd_rand randomGenerator;

    // Frame rate of the game.
    unsigned int frameRate;
    // Waiting distance before generating the first object.
    double clearance;
    // Rate of dangerous obstacles.
    double dangerousObstacleRate;

};

#endif
