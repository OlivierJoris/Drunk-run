/*
 * Implementation of a window of drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Window.hpp"
#include "RGBColor.hpp"

#include <iostream>
#include <string>
#include <SDL2/SDL_ttf.h>

using namespace std;

Window::Window(const unsigned int width, const unsigned int height)
: height{height}, width{width} {
    build_window();
}

void Window::build_window(){
    window = SDL_CreateWindow(
        "Drunk run",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if(!window){
        cerr << "Error while creating window %s" << SDL_GetError() << endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        cerr << "Error while creating the renderer %s" << SDL_GetError() << endl;
        return;
    }
}

unsigned int Window::get_height() const{
    return height;
}

unsigned int Window::get_width() const{
    return width;
}

SDL_Window* Window::get_sdl_window() const {
    return window;
}

SDL_Renderer* Window::get_sdl_renderer() const{
    return renderer;
}

int Window::draw_rect(
    const unsigned int height,
    const unsigned int width,
    const unsigned int xTopLeft,
    const unsigned int yTopLeft,
    const RGBColor& color
){
    if(!(check_x_coordinate(xTopLeft + width) &&
            check_y_coordinate(yTopLeft + height)))
        return -1;

    // Builds rect
    SDL_Rect rect;
    rect.x = xTopLeft; rect.y = yTopLeft;
    rect.h = height; rect.w = width;

    int setColor;
    // Sets color
    setColor = SDL_SetRenderDrawColor(
        renderer,
        color.get_red(), color.get_green(), color.get_blue(), 255
    );
    if(setColor < 0){
        cerr << "Error while drawing color in draw_rect " << SDL_GetError() << endl;
        return -1;
    }

    // Draws rect
    if(SDL_RenderDrawRect(renderer, &rect) < 0){
        cerr << "Error while drawing rect in draw_rect " << SDL_GetError() << endl;
        return -1;
    }

    SDL_RenderFillRect(renderer, &rect);

    return 0;
}

int Window::draw_line(
    const unsigned int xStart,
    const unsigned int yStart,
    const unsigned int xEnd,
    const unsigned int yEnd,
    const RGBColor& color
){
    if(!(check_x_coordinate(xStart) && check_y_coordinate(yStart) &&
            check_x_coordinate(xEnd) && check_y_coordinate(yEnd)))
        return -1;

    int setColor;
    // Sets color
    setColor = SDL_SetRenderDrawColor(
        renderer,
        color.get_red(), color.get_green(), color.get_blue(), 255
    );
    if(setColor < 0){
        cerr << "Error while drawing color in draw_line " << SDL_GetError() << endl;
        return -1;
    }

    // Draws line
    if(SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd) < 0){
        cerr << "Error while drawing line in draw_line " << SDL_GetError() << endl;
        return -1;
    }

    return 0;
}

int Window::draw_text(
    const string& text,
    const unsigned int fontSize,
    const RGBColor& textColor,
    const unsigned int height,
    const unsigned int width,
    const unsigned int xTopLeft,
    const unsigned int yTopLeft
){
    if(!(check_x_coordinate(xTopLeft + width) &&
            check_y_coordinate(yTopLeft + height)))
        return -1;

    // Based on https://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2

    TTF_Font* font = TTF_OpenFont("OpenSans.ttf", fontSize);
    if(!font){
        cerr << "Unable to find font: " << TTF_GetError() << endl;
        return -2;
    }

    SDL_Color color;
    color.r = textColor.get_red();
    color.g = textColor.get_green();
    color.b = textColor.get_blue();
    color.a = 255;

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if(!surface){
        cerr << "Unable to build surface for text: " << SDL_GetError() << endl;
        return -1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture){
        cerr << "Unable to generate texture for text: " << SDL_GetError() << endl;
        TTF_CloseFont(font);
        SDL_FreeSurface(surface);
        return -1;
    }

    SDL_Rect textRectangle;
    textRectangle.x = xTopLeft; textRectangle.y = yTopLeft;
    textRectangle.h = height; textRectangle.w = width;

    if(SDL_RenderCopy(renderer, texture, NULL, &textRectangle) < 0){
        cerr << "Error while copying texture: " << SDL_GetError() << endl;
        TTF_CloseFont(font);
        SDL_FreeSurface(surface);
        return -1;
    }

    if(font)
        TTF_CloseFont(font);
    if(surface)
        SDL_FreeSurface(surface);
    if(texture)
        SDL_DestroyTexture(texture);

    return 0;
}

bool Window::check_x_coordinate(const unsigned int x) const{
    if(x > width)
        return false;
    else
        return true;    
}

bool Window::check_y_coordinate(const unsigned int y) const{
    if(y > height)
        return false;
    else
        return true;
}
