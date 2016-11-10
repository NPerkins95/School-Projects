/*
    Rectangle class derived from Shape class
    - Jesus Suarez, Oct. 26, 2015
*/

#include <iostream>
#include "Rectangle.h"

using namespace std;

void Rect::draw() {
    fl_color(linecolor);
    fl_rect(position.x, position.y, width, height);
}

void Rect::print_parameters() {
    cout << "Rectangle object.\n\t"
         << "Width: " << width << ", Height: " << height
         << ", Position: (" << position.x << ", " << position.y << "), Color: " << linecolor << ".\n";
}