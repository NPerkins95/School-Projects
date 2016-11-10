#pragma once
//#include <Windows.h>
#include <FL/fl_draw.H>

enum Color {
    red = FL_RED,
    blue = FL_BLUE,
    green = FL_GREEN,
    yellow = FL_YELLOW,
    white = FL_WHITE,
    black = FL_BLACK,
    magenta = FL_MAGENTA,
    cyan = FL_CYAN,
};

struct Point {
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) { }
};

class Shape : public Fl_Widget {
protected:
    Shape(Point p = Point(0,0), Color c = black) 
        : Fl_Widget(p.x, p.y, 0, 0), position(p), linecolor(c) {}
   
    Point position;
    Color linecolor;

public:
    void set_color(Color c) { linecolor = c; }
    Color get_color() const { return linecolor; }
    void set_position(Point p) { position = p; }
    Point get_position() const { return position; }

    virtual void draw() = 0;
    virtual void print_parameters() = 0;
};
