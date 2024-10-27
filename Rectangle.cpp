/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Chen Li, Christopher Purnawan
 * lichenlc, chrislp
 *
 * The implementations of Rectangle class.
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// Initialize the points to (0,0) and sets all corner colors to default.
Rectangle::Rectangle() {
    Point pt1(0, 0);
    Point pt2(0, 0);
    start = pt1;
    end = pt2;
    colorTopLeft = Color();
    colorTopRight = Color();
    colorBottomLeft = Color();
    colorBottomRight = Color();
}

// Initialize the start and end points, and the colors for all four corners.
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomLeft = cBottomLeft;
    colorBottomRight = cBottomRight;
}

// Set the starting point of the rectangle.
void Rectangle::setStart(Point pt) {
    start = pt;
}

// Return the starting point of the rectangle.
Point Rectangle::getStart() {
    return start;
}

// Set the ending point of the rectangle.
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// Return the ending point of the rectangle.
Point Rectangle::getEnd() {
    return end;
}

// Set all four corner colors to the specified color.
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// Set the color of the top-left corner of the rectangle.
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

// Return the color of the top-left corner of the rectangle.
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// Set the color of the top-right corner of the rectangle.
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

// Return the color of the top-right corner of the rectangle.
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// Set the color of the bottom-right corner of the rectangle.
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// Return the color of the bottom-right corner of the rectangle.
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Set the color of the bottom-left corner of the rectangle.
void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

// Return the color of the bottom-left corner of the rectangle.
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

// Read the start&end points and four corners's colos from the input stream.
void Rectangle::read(istream &ins) {
    ins >> start >> end >> colorTopLeft >> colorTopRight
    >> colorBottomRight >> colorBottomLeft;
}

// Write the start&end points and four corners's colos to the output stream.
void Rectangle::write(ostream &outs) {
    outs << start << " " << end << " " << colorTopLeft << " " << colorTopRight
    << " " << colorBottomRight << " " << colorBottomLeft;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
