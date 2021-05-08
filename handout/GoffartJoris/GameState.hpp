/*
 * The game state of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __GAME__STATE__
#define __GAME__STATE__

// Represents the status of the game.
enum GameStateStatus {ongoing, ended};

// Represents the state of the game.
class GameState{

public:
    // Constructor.
    GameState();

    /*
     * Returns the distance travelled by Cymi.
     */
    double get_travelled_dist() const;
    /*
     * Sets the distance travelled by Cymi.
     *
     * @param newDist New distance travelled.
     */
    void set_travelled_dist(const double newDist);
    /*
     * Increases the distance travelled by Cymi.
     *
     * @param increase Distance to add to the travelled distance.
     */
    void increase_travelled_dist(const double increase);

    /*
     * Returns the status of the game.
     */
    GameStateStatus get_status() const;
    /*
     * Sets the status of the game.
     *
     * @param newStatus New status of the game.
     */
    void set_status(const GameStateStatus newStatus);

private:
    double travelledDist;
    GameStateStatus status;
};

#endif
