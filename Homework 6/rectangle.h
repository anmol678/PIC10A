#include <cmath>
#include "ccc_win.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

const double PI = 3.14159265358979323846;

// Please see the file 'rectangle.cpp' for comments
class Rectangle {
public:
    Rectangle();
    Rectangle(Point c, double w, double h);
    Rectangle(Point c, double w, double h, double a);
    
    void draw() const;
    void move(double dx, double dy);
    void resize(double r);
    void rotate(double a);
    
    Point get_corner() const;
    double get_width() const;
    double get_height() const;
    double get_angle() const;
    
    bool operator < (Rectangle b) const;
    bool operator > (Rectangle b) const;
    bool operator <= (Rectangle b) const;
    bool operator >= (Rectangle b) const;
    
private:
    void rotatePoint(Point& p, double a);
    double distanceBetween(Point a, Point b) const;
    double get_area() const;
    Point get_center() const;
    
    Point corner1;
    Point corner2;
    Point corner3;
    Point corner4;
    double angle;
};

#endif