/*
    Rectangle class derived from Shape class
    - Jesus Suarez, Oct. 26, 2015
*/

#pragma once
#include "Shape.h"

class Rect : public Shape {
private:
    unsigned int width, height;

public:
    Rect(unsigned int w = 0,
         unsigned int h = 0,
         Point p = Point(0, 0),
         Color c = black)
        : Shape(p, c), width(w), height(h) {}

    void set_width(unsigned int w) { width = w; }
    unsigned int get_width() const { return width; }
    void set_height(unsigned int h) { height = h; }
    unsigned int get_height() const { return height; }
    
    void draw();
    void print_parameters();
};
