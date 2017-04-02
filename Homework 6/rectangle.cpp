/*****************************************************************
 Anmol Jain
 Feb 28, 2016.
 An implementation of the rectangle class defined in the header
 file 'rectangle.h'.
 *****************************************************************/
#include "rectangle.h"

/*
 Default constructor:
 A unit square with main corner (0,0) rotated 0 degeres.
 */
Rectangle::Rectangle(){
    corner1 = Point(0, 0);
    corner2 = Point(1, 0);
    corner3 = Point(1, -1);
    corner4 = Point(0, -1);
    angle = 0.0;
}


/*
 Constructor:
 A rectangle with main corner 'c', width 'w', height 'h' and rotated 0 degrees.
 */
Rectangle::Rectangle(Point c, double w, double h){
    corner1 = c;
    c.move(w, 0);
    corner2 = c;
    c.move(0, -h);
    corner3 = c;
    c.move(-w, 0);
    corner4 = c;
    angle = 0.0;
}


/*
 Constructor:
 A rectangle with main corner 'c', width 'w', height 'h' and rotated 'a' degrees.
 */
Rectangle::Rectangle(Point c, double w, double h, double a){
    corner1 = c;
    c.move(w, 0);
    corner2 = c;
    c.move(0, -h);
    corner3 = c;
    c.move(-w, 0);
    corner4 = c;
    angle = a;
    rotate(a);//rotate function needs to be implemented in order to rotate the retangle by 'a' degrees before it is drawn
}


/*
 Accessor:
 draw
    Draws lines from corner to corner to generate a rectangle.
 */
void Rectangle::draw() const {    
    cwin << Line(corner1, corner2)
    << Line(corner2, corner3)
    << Line(corner3, corner4)
    << Line(corner4, corner1);
    return;
}


/*
 Mutator:
 move
    Moves all corners dx units horizontally and dy units vertically
 parameters:
    dx, dy
    units to be shifted horizontally and vertically
 */
void Rectangle::move(double dx, double dy){
    corner1.move(dx, dy);
    corner2.move(dx, dy);
    corner3.move(dx, dy);
    corner4.move(dx, dy);
    return;
}


/*
 Mutator:
 resize
    Resizes the rectangle by a factor 'r' around its center.
    E.g:
    Rectangle r1;
    r1.resize(2);
    doubles the lenght and width of r1 while keeping the center
    of the rectangle unchanged.
 parameter:
    r
    resizing factor
 */
void Rectangle::resize(double r){
    Point center = get_center();
    double center_x = center.get_x(), center_y = center.get_y();
    move(-center_x, -center_y);
    
    corner1.move(corner1.get_x()*2, corner1.get_y()*2);
    corner2.move(corner2.get_x()*2, corner2.get_y()*2);
    corner3.move(corner3.get_x()*2, corner3.get_y()*2);
    corner4.move(corner4.get_x()*2, corner4.get_y()*2);
    
    move(center_x, center_y);
    return;
}


/*
 Mutator:
 rotate
    Rotates the rectangle 'a' degrees around its center.
    E.g:
    Rectangle r1 = Rectangle( Point( -1.0 , 0.5 ) , 2 , 1 );
    r1.rotate(90);
    results in a rectangle with width = 1 and height = 2
    centered at the origin.
 parameter:
    a
    angle in degrees
 */
void Rectangle::rotate(double a){
    Point center = get_center();
    double center_x = center.get_x(), center_y = center.get_y();
    move(-center_x, -center_y);
    
    rotatePoint(corner1, a);
    rotatePoint(corner2, a);
    rotatePoint(corner3, a);
    rotatePoint(corner4, a);
    
    move(center_x, center_y);
    angle = a;
    return;
}


/*
 Accessor:
 get_corner
 return:
    Returns the 'main' corner of the rectangle.
 */
Point Rectangle::get_corner() const {
    return corner1;
}


/*
 Accessor:
 get_width
 return:
    Returns the width of a rectangle. 
 For our purposes the width is the distance from corner 
 'main' of the rectangle to corner 'next' of the Rectangle. 
 We assume that to get to corner 'next' we move clockwise.
 */
double Rectangle::get_width() const {
    return distanceBetween(corner1, corner2);

}


/*
 Accessor:
 get_height
 return:
    Returns the height of a rectangle.
 For our purposes the height is the distance from corner 
 'main' of the rectangle to corner 'previous' of the Rectangle.
 We assume that to get to the corner 'previous' we move
 counterclockwise.
 */
double Rectangle::get_height() const {
    return distanceBetween(corner1, corner4);
}


/*
 Accessor:
 get_angle
 return:
    Returns the angle that the line segment from corner
    'main' to corner 'next' makes with a horizontal line.
 */
double Rectangle::get_angle() const {
    return angle;
}


/*
 Operators:
 Comparison of Rectangles based on their areas (operator overloading).
 */
bool Rectangle::operator < (Rectangle b) const {
    if (get_area() < b.get_area())
        return true;
    else
        return false;
}

bool Rectangle::operator > (Rectangle b) const {
    if (get_area() > b.get_area())
        return true;
    else
        return false;
}

bool Rectangle::operator <= (Rectangle b) const {
    if (get_area() <= b.get_area())
        return true;
    else
        return false;
}

bool Rectangle::operator >= (Rectangle b) const {
    if (get_area() >= b.get_area())
        return true;
    else
        return false;
}



/*
 Private member functions:
 These functions are only available to members of the class
 Rectangle. Explicit objects are not needed in order to call
 them.
 */

/* 
 rotatePoint
    Rotates a point 'a' degrees counterclockwise around the origin
 parameters:
    p, a
    Calls variable Point p by reference, rotates point p by a degrees
 */
void Rectangle::rotatePoint(Point& p, double a){
    double angle_radians = (a/180)*PI;
    double x = p.get_x(), y = p.get_y();
    
    double xr = (x*cos(angle_radians)) - (y*sin(angle_radians));
    double yr = (x*sin(angle_radians)) + (y*cos(angle_radians));
    
    p = Point(xr, yr);
    return;
}

/*
 distanceBetween
    Calculates distance between two points
 parameters:
    a, b
    The two points between which distance has to be calculated
 returns:
    Returns the distance between two points
 */
double Rectangle::distanceBetween(Point a, Point b) const {
    double x1 = a.get_x(), x2 = b.get_x(), y1 = a.get_y(), y2 = b.get_y();
    
    double distance = pow((pow(x1 - x2, 2))+(pow(y1 - y2, 2)),0.5);
   
    return distance;
}

/*
 get_area
    Calculates area of the rectangle
 returns:
    Returns the area of a rectangle
 */
double Rectangle::get_area() const {
    double w = get_width();
    double h = get_height();
   
    double area = w*h;
   
    return area;
}

/*
 get_center
    Calculates te center of the rectangle
 returns:
    Returns the center of a rectangle
 */
Point Rectangle::get_center() const {
    double x1 = corner1.get_x(), x2 = corner2.get_x(), x3 = corner3.get_x(), x4 = corner4.get_x();
    double y1 = corner1.get_y(), y2 = corner2.get_y(), y3 = corner3.get_y(), y4 = corner4.get_y();
    
    double center_x = (x1+x2+x3+x4)/4;
    double center_y = (y1+y2+y3+y4)/4;
    
    return Point(center_x, center_y);
}