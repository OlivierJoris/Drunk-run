/*
 * Implementation of the object of the game drunk run.
 *
 * @author Maxime Goffart (180521) & Olivier Joris (182113)
 */

#include "Object.hpp"
#include "Renderer.hpp"
#include "Coordinate3D.hpp"
#include "Size3D.hpp"
#include "RGBColor.hpp"

#include <memory>
#include <iostream>

using namespace std;

Object::Object(){
    size = std::make_shared<Size3D>();
    topLeft = std::make_shared<Coordinate3D>();
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
    topLeft = std::make_shared<Coordinate3D>(x, y, z);
    color = std::make_shared<RGBColor>(r, g, b);
}

void Object::set_coordinates(const double x, const double y, const double z){
    topLeft->set_x(x);
    topLeft->set_y(y);
    topLeft->set_z(z);
}

shared_ptr<Coordinate3D> Object::get_coordinates() const{
    return topLeft;
}

shared_ptr<Size3D> Object::get_size() const{
    return size;
}

shared_ptr<RGBColor> Object::get_color() const{
    return color;
}

void Object::draw(shared_ptr<Window> w, shared_ptr<Player> p) const{

    // Coordinates of the different points of the cuboid
    Coordinate3D point1 = *topLeft;
    Coordinate3D point2(point1.get_x() + size->get_width(), point1.get_y(), point1.get_z());
    Coordinate3D point3(point2.get_x(), point1.get_y(), point2.get_z() + size->get_depth());
    Coordinate3D point4(point1.get_x(), point1.get_y(), point3.get_z());
    Coordinate3D point5(point1.get_x(), point1.get_y() - size->get_height(), point1.get_z());
    Coordinate3D point6(point2.get_x(), point5.get_y(), point1.get_z());
    Coordinate3D point7(point2.get_x(), point5.get_y(), point3.get_z());
    Coordinate3D point8(point1.get_x(), point5.get_y(), point3.get_z());

    // Coordinates of the different points of the cuboid with perspective
    Coordinate3D point1p = Renderer::compute_perspective(point1, p);
    Coordinate3D point2p = Renderer::compute_perspective(point2, p);
    Coordinate3D point3p = Renderer::compute_perspective(point3, p);
    Coordinate3D point4p = Renderer::compute_perspective(point4, p);
    Coordinate3D point5p = Renderer::compute_perspective(point5, p);
    Coordinate3D point6p = Renderer::compute_perspective(point6, p);
    Coordinate3D point7p = Renderer::compute_perspective(point7, p);
    Coordinate3D point8p = Renderer::compute_perspective(point8, p);

    /* Coordinates of the different points of the cuboid in the
        window coordinate system */
    Coordinate3D point1Window = Renderer::from_perspective_to_window(point1p, w, p);
    Coordinate3D point2Window = Renderer::from_perspective_to_window(point2p, w, p);
    Coordinate3D point3Window = Renderer::from_perspective_to_window(point3p, w, p);
    Coordinate3D point4Window = Renderer::from_perspective_to_window(point4p, w, p);
    Coordinate3D point5Window = Renderer::from_perspective_to_window(point5p, w, p);
    Coordinate3D point6Window = Renderer::from_perspective_to_window(point6p, w, p);
    Coordinate3D point7Window = Renderer::from_perspective_to_window(point7p, w, p);
    Coordinate3D point8Window = Renderer::from_perspective_to_window(point8p, w, p); 

    RGBColor colorFace = RGBColor(color->get_red() / 2, color->get_green() / 2,
                                  color->get_blue() / 2);
    Coordinate3D firstPoint, secondPoint, firstPointP, secondPointP, firstPointW, secondPointW;

    // Back face 
    w->draw_rect(abs(point4Window.get_y() - point8Window.get_y()), abs(point4Window.get_x() -
                     point3Window.get_x()), point4Window.get_x(), point4Window.get_y(), colorFace);

    w->draw_line(point3Window.get_x(), point3Window.get_y(), point4Window.get_x(), point4Window.get_y(), *color);
    w->draw_line(point4Window.get_x(), point4Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
    w->draw_line(point7Window.get_x(), point7Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
    w->draw_line(point3Window.get_x(), point3Window.get_y(), point7Window.get_x(), point7Window.get_y(), *color);  

    // Side faces drawn by increasing z
    for(int z = point4.get_z(); z > point1.get_z(); --z)
    {
        // Left face
        firstPoint = Coordinate3D(point1.get_x(), point1.get_y(), z);
        firstPointP = Renderer::compute_perspective(firstPoint, p);
        firstPointW = Renderer::from_perspective_to_window(firstPointP, w, p);
        secondPoint = Coordinate3D(point1.get_x(), point5.get_y(), z);
        secondPointP = Renderer::compute_perspective(secondPoint, p);
        secondPointW = Renderer::from_perspective_to_window(secondPointP, w, p);
        w->draw_line(firstPointW.get_x(), firstPointW.get_y(), secondPointW.get_x(), 
                     secondPointW.get_y(), colorFace);

        // Up face
        firstPoint = Coordinate3D(point1.get_x(), point1.get_y(), z);
        firstPointP = Renderer::compute_perspective(firstPoint, p);
        firstPointW = Renderer::from_perspective_to_window(firstPointP, w, p);
        secondPoint = Coordinate3D(point2.get_x(), point1.get_y(), z);
        secondPointP = Renderer::compute_perspective(secondPoint, p);
        secondPointW = Renderer::from_perspective_to_window(secondPointP, w, p);
        w->draw_line(firstPointW.get_x(), firstPointW.get_y(), secondPointW.get_x(), 
                     secondPointW.get_y(), colorFace);

        // Right face
        firstPoint = Coordinate3D(point2.get_x(), point1.get_y(), z);
        firstPointP = Renderer::compute_perspective(firstPoint, p);
        firstPointW = Renderer::from_perspective_to_window(firstPointP, w, p);
        secondPoint = Coordinate3D(point2.get_x(), point5.get_y(), z);
        secondPointP = Renderer::compute_perspective(secondPoint, p);
        secondPointW = Renderer::from_perspective_to_window(secondPointP, w, p);
        w->draw_line(firstPointW.get_x(), firstPointW.get_y(), secondPointW.get_x(), 
                     secondPointW.get_y(), colorFace);
    }

    w->draw_line(point1Window.get_x(), point1Window.get_y(), point4Window.get_x(), point4Window.get_y(), *color);
    w->draw_line(point2Window.get_x(), point2Window.get_y(), point3Window.get_x(), point3Window.get_y(), *color);
    w->draw_line(point5Window.get_x(), point5Window.get_y(), point8Window.get_x(), point8Window.get_y(), *color);
    w->draw_line(point6Window.get_x(), point6Window.get_y(), point7Window.get_x(), point7Window.get_y(), *color);
    
    // Front face
    w->draw_rect(abs(point1Window.get_y() - point5Window.get_y()), abs(point1Window.get_x() - 
                     point2Window.get_x()), point1Window.get_x(), point1Window.get_y(), colorFace);

    w->draw_line(point1Window.get_x(), point1Window.get_y(), point2Window.get_x(), point2Window.get_y(), *color);
    w->draw_line(point1Window.get_x(), point1Window.get_y(), point5Window.get_x(), point5Window.get_y(), *color);
    w->draw_line(point5Window.get_x(), point5Window.get_y(), point6Window.get_x(), point6Window.get_y(), *color);
    w->draw_line(point2Window.get_x(), point2Window.get_y(), point6Window.get_x(), point6Window.get_y(), *color);
}
