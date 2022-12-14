/*
 * A window of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#ifndef __WINDOW__
#define __WINDOW__

#include "RGBColor.hpp"

#include <string>
#include <SDL2/SDL.h>

// Represents a window of the game drunk run.
class Window{

public:
    // Default width of the window in pixels.
    static const unsigned int DEFAULT_WIDTH = 640;
    // Default height of the window in pixels.
    static const unsigned int DEFAULT_HEIGHT = 480;

    /*
     * Constructor.
     *
     * @param width Width of the window in pixels.
     * @param height Height of the window in pixels.
     *
     * @return Window with the given size.
     */
    Window(
        const unsigned int width = DEFAULT_WIDTH,
        const unsigned int height = DEFAULT_HEIGHT
    );

    /*
     * Returns the height of the window in pixels.
     */
    unsigned int get_height() const;

    /*
     * Returns the width of the window in pixels.
     */
    unsigned int get_width() const;

    /*
     * Returns the SDL window of this window.
     */
    SDL_Window* get_sdl_window() const;

    /*
     * Returns the SDL renderer of this window.
     */
    SDL_Renderer* get_sdl_renderer() const;

    /*
     * Draws an unfilled rectangle on the window.
     *
     * @param height Height of the rectangle (in pixels).
     * @param width Width of the rectangle (in pixels).
     * @param xTopLeft X coordinate of the top left corner (sdl window coordinate).
     * @param yTopLeft Y coordinate of the top left corner (sdl window coordinate).
     * @param color Color of the border of the rectangle.
     * 
     * @return 0 no error. Else, error while drawing.
     */
    int draw_rect(
        const unsigned int height,
        const unsigned int width,
        const unsigned int xTopLeft,
        const unsigned int yTopLeft,
        const RGBColor& color
    );

    /*
     * Draws a line on the window.
     *
     * @param xStart X coordinate of the start of the line (sdl window coordinate).
     * @param yStart Y coordinate of the start of the line (sdl window coordinate).
     * @param xEnd X coordinate of the end of the line (sdl window coordinate).
     * @param yEnd Y coordinate of the end of the line (sdl window coordinate).
     * @param color Color of the line.
     * 
     * @return 0 no error. Else, error while drawing.
     */
    int draw_line(
        const unsigned int xStart,
        const unsigned int yStart,
        const unsigned int xEnd,
        const unsigned int yEnd,
        const RGBColor& color
    );

    /*
     * Draws a text on the window.
     *
     * @param text Text to display.
     * @param fontSize Size of the font.
     * @param textColor Color of the text.
     * @param height Height of the text (in pixels).
     * @param width Width of the text (in pixels).
     * @param xTopLeft X coordinate of the top left corner (sdl window coordinate).
     * @param yTopLeft Y coordinate of the top left corner (sdl window coordinate).
     *
     * @return 0 no error. -1 SDL error. -2 TTF error.
     */
    int draw_text(
        const std::string& text,
        const unsigned int fontSize,
        const RGBColor& textColor,
        const unsigned int height,
        const unsigned int width,
        const unsigned int xTopLeft,
        const unsigned int yTopLeft
    );

private:
    /*
     * Builds the SDL_window.
     */
    void build_window();

    /*
     * Checks if a given x coordinate fit in the window.
     *
     * @return true if it fits. false if it does not.
     */
    bool check_x_coordinate(const unsigned int x) const;
    /*
     * Checks if a given y coordinate fit in the window.
     *
     * @return true if it fits. false if it does not.
     */
    bool check_y_coordinate(const unsigned int y) const;

    unsigned int height;
    unsigned int width;

    // SDL window of the Window.
    SDL_Window* window;
    // Renderer of the Window.
    SDL_Renderer* renderer;
};

#endif
