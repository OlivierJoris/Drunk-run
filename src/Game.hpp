/*
 * The game of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __GAME__
#define __GAME__

#include "GameState.hpp"

#include <memory>

// Represents the game of drunk run.
class Game{

public:
    // Constructor.
    Game();

    /*
     * Returns the state of the game.
     *
     * @return State of the game.
     */
    std::shared_ptr<GameState> get_game_state() const;

private:
    // State of the game.
    std::shared_ptr<GameState> state;

};

#endif
