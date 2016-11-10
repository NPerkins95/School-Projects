#include <iostream>
#include "Triangle.h"
using namespace std;

void Triangle::draw()
{
	fl_color(linecolor);
	fl_polygon(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

void Triangle::print_parameters()
{
    cout << "Triangle object.\n\t"
         << "Point 1: (" << p1.x << ", " << p1.y
         << "), Point 2: (" << p2.x << ", " << p2.y
         << "), Point 3: (" << p3.x << ", " << p3.y
         << "), Color: " << linecolor << ".\n";
}
