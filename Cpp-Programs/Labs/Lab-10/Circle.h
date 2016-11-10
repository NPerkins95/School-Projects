/*
    Circle class derived from Shape class
    - Jesus Suarez, Oct. 26, 2015
*/

#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    unsigned int radius;

public:
    Circle(unsigned int r = 0,
                  Point p = Point(0,0),
                  Color c = black)
        : Shape(p, c), radius(r) {}

    void set_radius(unsigned int r) { radius = r; }
    unsigned int get_radius() const { return radius; }
    
    void draw();
    void print_parameters();
};