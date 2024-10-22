/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Chen Li
 * lichenlc
 *
 * The implementations of Point class.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// Initializes the point to the origin (0, 0).
Point::Point() {
    x = checkRange(0);
    y = checkRange(0);
}

// Initializes the point with the given x and y values.
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// Sets the x coordinate of the point.
void Point::setX(int xVal) {
    x = checkRange(xVal);
}

// Returns the current x coordinate of the point.
int Point::getX() {
    return x;
}

// Sets the y coordinate of the point.
void Point::setY(int yVal) {
    y = checkRange(yVal);
}

// Returns the current y coordinate of the point.
int Point::getY() {
    return y;
}

// Reads a point from the input stream and calls checkRange().
void Point::read(istream &ins) {
    char character;
    ins >> character >> x >> character >> y >> character;
    x = checkRange(x);
    y = checkRange(y);
}

// Writes the point to the output stream in the format (x, y).
void Point::write(ostream &outs) {
    outs << "(" << x << "," << y << ")";
}

// If the value is less than 0, returns 0.
// If the value is greater than or equal to DIMENSION, returns DIMENSION - 1.
// Otherwise, returns the original value.
int Point::checkRange(int val) {
    if (val < 0) {
        return 0;
    }
    else if (val >= DIMENSION) {
        return DIMENSION - 1;
    }
    else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
