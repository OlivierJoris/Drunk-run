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
    Window(const unsigned int width, const unsigned int height);

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
    SDL_Window* get_sdl_window() const;

    /*
     * Returns the SDL renderer.
     *
     * @return The SDL renderer of the window.
     */
    SDL_Renderer* get_sdl_renderer() const;

    /*
     * Draws an unfilled rectangle on the window.
     *
     * @param height Height of the rectangle (in pixels).
     * @param width Width of the rectangle (in pixels).
     * @param xTopLeft X coordinate of the top left corner.
     * @param yTopLeft Y coordinate of the top left corner.
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
     * @param xStart X coordinate of the start of the line.
     * @param yStart Y coordinate of the start of the line.
     * @param xEnd X coordinate of the end of the line.
     * @param yEnd Y coordinate of the end of the line.
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
     * @param height Height of the text.
     * @param width Width of the text.
     * @param xTopLeft X coordinate of the top left corner.
     * @param yTopLeft Y coordinate of the top left corner.
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

    unsigned int height;
    unsigned int width;

    // SDL window of the Window.
    SDL_Window* window;
    // Renderer of the Window.
    SDL_Renderer* renderer;
};

#endif
