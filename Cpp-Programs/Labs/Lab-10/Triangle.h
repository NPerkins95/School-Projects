//#ifndef Fl_Triangle_h
//#define Fl_Triangle_h
#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
    Point p1, p2, p3;
    
public:
    Triangle(Point p1 = Point(0, 0),
         	 Point p2 = Point(0, 0),
        	 Point p3 = Point(0, 0),
       	     Color c = black)
    : Shape(p1, c), p1(p1), p2(p2), p3(p3) {}
    
    //void set_p1(Point p1) { this->p1 = p1; }
    Point get_p1() const { return p1; }
    //void set_p2(Point p2) { this->p2 = p2; }
    Point get_p2() const { return p2; }
    //void set_p3(Point p3) { this->p3 = p3; }
    Point get_p3() const { return p3; }
    
    void draw();
    void print_parameters();
};

//#endif /* Fl_Triangle_h */
