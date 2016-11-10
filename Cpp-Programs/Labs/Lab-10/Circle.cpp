/*
    Circle class derived from Shape class
    - Jesus Suarez, Oct. 26, 2015
*/

#include <iostream>
#include "Circle.h"

using namespace std;

void Circle::draw() {
    fl_color(linecolor);
    fl_arc(position.x, position.y, 2 * radius, 2 * radius, 0, 360);
}

void Circle::print_parameters() {
    cout << "Circle object.\n\t"
         << "Radius: " << radius
         << ", Position: (" << position.x << ", " << position.y << "), Color: " << linecolor << ".\n";
}