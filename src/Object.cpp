/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Object.hpp"
#include "Renderer.hpp"
#include "Coordinate3D.hpp"

#include <memory>
#include <iostream>

using namespace std;

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
    /*
    Coordinate3D posEye = p->get_position_eye();

    cout << "eye pos " << posEye << endl;
    */

    // Coordinates of the different points of the cuboid
    Coordinate3D point1 = *topleft;
    Coordinate3D point2(point1.get_x() + size->get_width(), point1.get_y(), point1.get_z());
    Coordinate3D point3(point2.get_x(), point1.get_y(), point2.get_z() + size->get_depth());
    Coordinate3D point4(point1.get_x(), point1.get_y(), point3.get_z());
    Coordinate3D point5(point1.get_x(), point1.get_y() - size->get_height(), point1.get_z());
    Coordinate3D point6(point2.get_x(), point5.get_y(), point1.get_z());
    Coordinate3D point7(point2.get_x(), point5.get_y(), point3.get_z());
    Coordinate3D point8(point1.get_x(), point5.get_y(), point3.get_z());

    /*
    cout << "point 1" << point1 << endl;
    cout << "point 2" << point2 << endl;
    cout << "point 3" << point3 << endl;
    cout << "point 4" << point4 << endl;
    cout << "point 5" << point5 << endl;
    cout << "point 6" << point6 << endl;
    cout << "point 7" << point7 << endl;
    cout << "point 8" << point8 << endl;
    */

    // Coordinates of the different points of the cuboid with perspective
    double xp1 = Renderer::compute_perspective_x(point1, p);
    double yp1 = Renderer::compute_perspective_y(point1, p);

    double xp2 = Renderer::compute_perspective_x(point2, p);
    double yp2 = Renderer::compute_perspective_y(point2, p);

    double xp3 = Renderer::compute_perspective_x(point3, p);
    double yp3 = Renderer::compute_perspective_y(point3, p);

    double xp4 = Renderer::compute_perspective_x(point4, p);
    double yp4 = Renderer::compute_perspective_y(point4, p);

    double xp5 = Renderer::compute_perspective_x(point5, p);
    double yp5 = Renderer::compute_perspective_y(point5, p);

    double xp6 = Renderer::compute_perspective_x(point6, p);
    double yp6 = Renderer::compute_perspective_y(point6, p);

    double xp7 = Renderer::compute_perspective_x(point7, p);
    double yp7 = Renderer::compute_perspective_y(point7, p);

    double xp8 = Renderer::compute_perspective_x(point8, p);
    double yp8 = Renderer::compute_perspective_y(point8, p);

    /*
    cout << "xp1 " << xp1 << " yp1 " << yp1 << endl;
    cout << "xp2 " << xp2 << " yp2 " << yp2 << endl;
    cout << "xp3 " << xp3 << " yp3 " << yp3 << endl;
    cout << "xp4 " << xp4 << " yp4 " << yp4 << endl;
    cout << "xp5 " << xp5 << " yp5 " << yp5 << endl;
    cout << "xp6 " << xp6 << " yp6 " << yp6 << endl;
    cout << "xp7 " << xp7 << " yp7 " << yp7 << endl;
    cout << "xp8 " << xp8 << " yp8 " << yp8 << endl;
    cout << endl;
    */

    /* Coordinates of the different points of the cuboid in the
        window coordinate system */
    Coordinate3D point1Window = Renderer::from_perspective_to_window(Coordinate3D(xp1, yp1, 0.0), w, p);
    Coordinate3D point2Window = Renderer::from_perspective_to_window(Coordinate3D(xp2, yp2, 0.0), w, p);
    Coordinate3D point3Window = Renderer::from_perspective_to_window(Coordinate3D(xp3, yp3, 0.0), w, p);
    Coordinate3D point4Window = Renderer::from_perspective_to_window(Coordinate3D(xp4, yp4, 0.0), w, p);
    Coordinate3D point5Window = Renderer::from_perspective_to_window(Coordinate3D(xp5, yp5, 0.0), w, p);
    Coordinate3D point6Window = Renderer::from_perspective_to_window(Coordinate3D(xp6, yp6, 0.0), w, p);
    Coordinate3D point7Window = Renderer::from_perspective_to_window(Coordinate3D(xp7, yp7, 0.0), w, p);
    Coordinate3D point8Window = Renderer::from_perspective_to_window(Coordinate3D(xp8, yp8, 0.0), w, p);


    if(point1Window.get_x() > w->get_width())
        point1Window.set_x(w->get_width());
    if(point1Window.get_x() < 0)
        point1Window.set_x(0);

    if(point2Window.get_x() > w->get_width())
        point2Window.set_x(w->get_width());
    if(point2Window.get_x() < 0)
        point2Window.set_x(0);

    if(point3Window.get_x() > w->get_width())
        point3Window.set_x(w->get_width());
    if(point3Window.get_x() < 0)
        point3Window.set_x(0);

    if(point4Window.get_x() > w->get_width())
        point4Window.set_x(w->get_width());
    if(point4Window.get_x() < 0)
        point4Window.set_x(0);
    
    if(point5Window.get_x() > w->get_width())
        point5Window.set_x(w->get_width());
    if(point5Window.get_x() < 0)
        point1Window.set_x(0);
    
    if(point6Window.get_x() > w->get_width())
        point6Window.set_x(w->get_width());
    if(point6Window.get_x() < 0)
        point6Window.set_x(0);

    if(point7Window.get_x() > w->get_width())
        point7Window.set_x(w->get_width());
    if(point7Window.get_x() < 0)
        point7Window.set_x(0);

    if(point8Window.get_x() > w->get_width())
        point8Window.set_x(w->get_width());
    if(point8Window.get_x() < 0)
        point8Window.set_x(0);

    
    if(point1Window.get_y() > w->get_height())
        point1Window.set_y(w->get_height());
    if(point1Window.get_y() < 0)
        point1Window.set_y(0);

    if(point2Window.get_y() > w->get_height())
        point2Window.set_y(w->get_height());
    if(point2Window.get_y() < 0)
        point2Window.set_y(0);

    if(point3Window.get_y() > w->get_height())
        point3Window.set_y(w->get_height());
    if(point3Window.get_y() < 0)
        point3Window.set_y(0);

    if(point4Window.get_y() > w->get_height())
        point4Window.set_y(w->get_height());
    if(point4Window.get_y() < 0)
        point4Window.set_y(0);

    if(point5Window.get_y() > w->get_height())
        point5Window.set_y(w->get_height());
    if(point5Window.get_y() < 0)
        point5Window.set_y(0);

    if(point6Window.get_y() > w->get_height())
        point6Window.set_y(w->get_height());
    if(point6Window.get_y() < 0)
        point6Window.set_y(0);

    if(point7Window.get_y() > w->get_height())
        point7Window.set_y(w->get_height());
    if(point7Window.get_y() < 0)
        point7Window.set_y(0);

    if(point8Window.get_y() > w->get_height())
        point8Window.set_y(w->get_height());
    if(point8Window.get_y() < 0)
        point8Window.set_y(0);


    /*
    cout << "p1w " << point1Window << endl;
    cout << "p2w " << point2Window << endl;
    cout << "p3w " << point3Window << endl;
    cout << "p4w " << point4Window << endl;
    cout << "p5w " << point5Window << endl;
    cout << "p6w " << point6Window << endl;
    cout << "p7w " << point7Window << endl;
    cout << "p8w " << point8Window << endl;
    */

    // Draws each lines of the cuboid
    w->draw_line(point1Window.get_x(), point1Window.get_y(), point2Window.get_x(), point2Window.get_y(), *color);
    w->draw_line(point1Window.get_x(), point1Window.get_y(), point4Window.get_x(), point4Window.get_y(), *color);
    w->draw_line(point1Window.get_x(), point1Window.get_y(), point5Window.get_x(), point5Window.get_y(), *color);
    w->draw_line(point2Window.get_x(), point2Window.get_y(), point3Window.get_x(), point3Window.get_y(), *color);
    w->draw_line(point2Window.get_x(), point2Window.get_y(), point6Window.get_x(), point6Window.get_y(), *color);
    w->draw_line(point3Window.get_x(), point3Window.get_y(), point4Window.get_x(), point4Window.get_y(), *color);
    w->draw_line(point3Window.get_x(), point3Window.get_y(), point7Window.get_x(), point7Window.get_y(), *color);
    w->draw_line(point4Window.get_x(), point4Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
    w->draw_line(point5Window.get_x(), point5Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
    w->draw_line(point5Window.get_x(), point5Window.get_y(), point6Window.get_x(), point6Window.get_y(), *color);
    w->draw_line(point6Window.get_x(), point6Window.get_y(), point7Window.get_x(), point7Window.get_y(), *color);
    w->draw_line(point7Window.get_x(), point7Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
}
