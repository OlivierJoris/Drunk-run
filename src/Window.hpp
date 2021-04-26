/*
 * A window of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __WINDOW__
#define __WINDOW__

#include <SDL2/SDL.h>

// Represents a window of the game drunk run.
class Window{

public:

    static const unsigned int DEFAULT_WIDTH = 640;
    static const unsigned int DEFAULT_HEIGHT = 480;

    /*
     * Constructs a Window with a default size.
     */
    Window();

    /*
     * Constructor.
     *
     * @param width Width of the window in pixels.
     * @param height Height of the window in pixels.
     *
     * @return Window with the given size.
     */
    Window(unsigned int width, unsigned int height);

    /*
     * Returns the height of the window.
     *
     * @return The height of the window in pixels.
     */
    unsigned int get_height() const;

    /*
     * Returns the width of the window.
     *
     * @return The width of the window in pixels.
     */
    unsigned int get_width() const;

    /*
     * Returns the SDL window.
     *
     * @return The SDL window of this window.
     */
    SDL_Window* get_sdl() const;

private:
    /*
     * Builds the SDL_window.
     */
    void build_window();

    unsigned int height;
    unsigned int width;

    // SDL window of the Window.
    SDL_Window* window;

};

#endif
