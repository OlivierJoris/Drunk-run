/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Object.hpp"
#include "Renderer.hpp"

#include <memory>
#include <iostream>

Object::Object(){
    size = std::make_shared<Size3D>();
    topleft = std::make_shared<Coordinate3D>();
    color = std::make_shared<RGBColor>();
}

Object::Object(
    const unsigned int height,
    const unsigned int width,
    const unsigned int depth,
    const uint8_t r,
    const uint8_t g,
    const uint8_t b,
    const double x,
    const double y,
    const double z
){
    size = std::make_shared<Size3D>(height, width, depth);
    topleft = std::make_shared<Coordinate3D>(x, y, z);
    color = std::make_shared<RGBColor>(r, g, b);
}

void Object::set_coordinates(double x, double y, double z){
    topleft->set_x(x);
    topleft->set_y(y);
    topleft->set_z(z);
}

void Object::draw(std::shared_ptr<Window> w, std::shared_ptr<Player> p) const{
    Renderer r;

    double x1 = topleft->get_x();
    double y1 = topleft->get_y();
    double z1 = topleft->get_z();

    double x2 = x1 + size->get_width();
    double y2 = y1;
    double z2 = z1;

    double x3 = x2;
    double y3 = y1;
    double z3 = z1 + size->get_depth();

    double x4 = x1;
    double y4 = y1;
    double z4 = z3;

    double x5 = x1;
    double y5 = y1 - size->get_height();
    double z5 = z1;

    double x6 = x2;
    double y6 = y5;
    double z6 = z1;

    double x7 = x2;
    double y7 = y5;
    double z7 = z3;

    double x8 = x1;
    double y8 = y5;
    double z8 = z3;

    double xper1 = r.from_cm_to_pixel_x(r.compute_perspective_x(x1, z1, p), w, p);
    double yper1 = r.from_cm_to_pixel_y(r.compute_perspective_y(y1, z1, p), w, p);

    double xper2 = r.from_cm_to_pixel_x(r.compute_perspective_x(x2, z2, p), w, p);
    double yper2 = r.from_cm_to_pixel_y(r.compute_perspective_y(y2, z2, p), w, p);

    double xper3 = r.from_cm_to_pixel_x(r.compute_perspective_x(x3, z3, p), w, p);
    double yper3 = r.from_cm_to_pixel_y(r.compute_perspective_y(y3, z3, p), w, p);

    double xper4 = r.from_cm_to_pixel_x(r.compute_perspective_x(x4, z4, p), w, p);
    double yper4 = r.from_cm_to_pixel_y(r.compute_perspective_y(y4, z4, p), w, p);

    double xper5 = r.from_cm_to_pixel_x(r.compute_perspective_x(x5, z5, p), w, p);
    double yper5 = r.from_cm_to_pixel_y(r.compute_perspective_y(y5, z5, p), w, p);

    double xper6 = r.from_cm_to_pixel_x(r.compute_perspective_x(x6, z6, p), w, p);
    double yper6 = r.from_cm_to_pixel_y(r.compute_perspective_y(y6, z6, p), w, p);

    double xper7 = r.from_cm_to_pixel_x(r.compute_perspective_x(x7, z7, p), w, p);
    double yper7 = r.from_cm_to_pixel_y(r.compute_perspective_y(y7, z7, p), w, p);

    double xper8 = r.from_cm_to_pixel_x(r.compute_perspective_x(x8, z8, p), w, p);
    double yper8 = r.from_cm_to_pixel_y(r.compute_perspective_y(y8, z8, p), w, p);

    xper1 = r.x_to_window_coordinate(xper1, w->DEFAULT_WIDTH);
    yper1 = r.x_to_window_coordinate(yper1, w->DEFAULT_HEIGHT);

    xper2 = r.x_to_window_coordinate(xper2, w->DEFAULT_WIDTH);
    yper2 = r.x_to_window_coordinate(yper2, w->DEFAULT_HEIGHT);

    xper3 = r.x_to_window_coordinate(xper3, w->DEFAULT_WIDTH);
    yper3 = r.x_to_window_coordinate(yper3, w->DEFAULT_HEIGHT);

    xper4 = r.x_to_window_coordinate(xper4, w->DEFAULT_WIDTH);
    yper4 = r.x_to_window_coordinate(yper4, w->DEFAULT_HEIGHT);

    xper5 = r.x_to_window_coordinate(xper5, w->DEFAULT_WIDTH);
    yper5 = r.x_to_window_coordinate(yper5, w->DEFAULT_HEIGHT);

    xper6 = r.x_to_window_coordinate(xper6, w->DEFAULT_WIDTH);
    yper6 = r.x_to_window_coordinate(yper6, w->DEFAULT_HEIGHT);

    xper7 = r.x_to_window_coordinate(xper7, w->DEFAULT_WIDTH);
    yper7 = r.x_to_window_coordinate(yper7, w->DEFAULT_HEIGHT);

    xper8 = r.x_to_window_coordinate(xper8, w->DEFAULT_WIDTH);
    yper8 = r.x_to_window_coordinate(yper8, w->DEFAULT_HEIGHT);

    w->draw_line(xper1, yper1, xper2, yper2, *color);
    w->draw_line(xper1, yper1, xper4, yper4, *color);
    w->draw_line(xper1, yper1, xper5, yper5, *color);
    w->draw_line(xper2, yper2, xper3, yper3, *color);
    w->draw_line(xper2, yper2, xper6, yper6, *color);
    w->draw_line(xper3, yper3, xper4, yper4, *color);
    w->draw_line(xper3, yper3, xper7, yper7, *color);
    w->draw_line(xper4, yper4, xper8, yper8, *color);
    w->draw_line(xper5, yper5, xper8, yper8, *color);
    w->draw_line(xper5, yper5, xper6, yper6, *color);
    w->draw_line(xper6, yper6, xper7, yper7, *color);
    w->draw_line(xper7, yper7, xper8, yper8, *color);
}
