/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();

//mine
void test_Color();

//mine
void test_Line();

void test_Point();

void test_Rectangle();
//mine
void test_Triangle();







void startTests() {
    test_Circle();
    test_Rectangle();
    test_Color();
    test_Line();
    test_Triangle();
    test_Point();

    return;
}

void test_Circle() {
    Circle c1;
    Circle(Point(3, 3), 5, Color(100, 100, 100));
    Circle c2;
    c2.setCenter(Point(3, 3));
    c2.getCenter();
    c2.setRadius(3);
    c2.getRadius();
    c2.setColor(Color(50, 50, 50));
    c2.getColor();

}



void test_Rectangle() {
    Rectangle r1;
    Rectangle r2(Point(0, 10), Point(10, 10), Color(0, 0, 0), Color(100, 100, 100), Color(50, 50, 50), Color(100, 100, 100));
    Rectangle r3;
    r3.setStart(Point(50, 50));
    r3.setEnd(Point(100, 100));
    r3.getStart();
    r3.getEnd();
    r3.setColor(Color(100, 100, 100));
    r3.setColorTopRight(Color(50, 50, 50));
    r3.setColorTopLeft(Color(50, 50, 50));
    
    r3.setColorBottomRight(Color(50, 50, 50));
    r3.setColorBottomLeft(Color(50, 50, 50));

    r3.getColorBottomRight();
    r3.getColorBottomLeft();
    r3.getColorTopRight();
    r3.getColorTopLeft();

}

void test_Color() {
    Color c1;
    Color c2(255, 0, 0);
    Color c3(-100, 300, 150);
    c1.setRed(130);
    c1.setGreen(-50);
    c1.setBlue(300);
    c1.getBlue();
    c1.getGreen();
    c1.getRed();
}

void test_Line() {
    Line l1;
    Line l2;
    l2.setStart(Point (10, 10));
    l2.getStart();
    l2.setEnd(Point(5,5));
    l2.getEnd();
    l2.setColor(Color(255,155,0));
    l2.getColor();
    Line l3(Point(0, 5), Point(4, 3), Color(0, 100, 100));
}

void test_Triangle() {
    Triangle t1;
    Triangle t2;
    t2.setColor(Color (100,0,100));
    t2.setVertexOne(Point(0, 100));
    t2.setVertexTwo(Point(10, 50));
    t2.setVertexThree(Point(50, 50));
    t2.getVertexOne();
    t2.getVertexTwo();
    t2.getVertexThree();
    t2.setVertexTwoColor(Color(100, 200, 200));
    t2.setVertexOneColor(Color(100, 200, 200));
    t2.setVertexThreeColor(Color(100, 200, 200));
    t2.getVertexOneColor();
    t2.getVertexTwoColor();
    t2.getVertexThreeColor();
    

    Triangle t3(Point(10, 50), Color(0, 0, 0), Point(20, 30), Color(100, 100, 100), Point(30, 50), Color(50, 50, 50));
}



void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;

    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
        << ", " << p1.getY()
        << " )" << endl;

    return;
}



