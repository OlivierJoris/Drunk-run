/*
 * The application of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __APP__
#define __APP__

#include "Window.hpp"
#include "Game.hpp"
#include "Event.hpp"

#include <memory>

// Represents the app of drunk run.
class App{

public:
    // Constructor.
    App();

    /*
     * Starts the application of drunk run.
     *
     * @return 0 no error. Else, error while running.
     */
    int run();

    /*
     * Quits the application.
     */
    void quit();

    /*
     * Reacts to the given drunk run event.
     *
     * @param event The DrunkRunEvent.
     */
    void handle_event(DrunkRunEvent& event) const;

    /*
     * Returns the window of the app.
     *
     * @return Pointer to the window of the app.
     */
    std::shared_ptr<Window> get_window() const;

    /*
     * Returns the game of the app.
     *
     * @return Pointer to the game of the app.
     */
    std::shared_ptr<Game> get_game() const;

private:
    // Window of the app
    std::shared_ptr<Window> window;

    // Game of the app
    std::shared_ptr<Game> game;

};

#endif
