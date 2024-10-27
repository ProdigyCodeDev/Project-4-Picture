/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Chen Li, Christopher Purnawan
 * lichenlc, chrislp
 *
 * The implementations of Color class.
 */

#include "Color.h"

// Initializing color values to 0.
Color::Color() {
    int red = 0;
    int green = 0;
    int blue = 0;
}

// Initializing color with specified values.
Color::Color(int redVal, int greenVal, int blueVal) {
    Color::setRed(redVal);
    Color::setGreen(greenVal);
    Color::setBlue(blueVal);
}

// Sets the red component after checking it is within 0-255.
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// Returns the red component of the color.
int Color::getRed() {
    return red;
}

// Sets the green component after checking it is within 0-255.
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

// Returns the green component of the color.
int Color::getGreen() {
    return green;
}

// Sets the blue component after checking it is within 0-255.
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// Returns the blue component of the color.
int Color::getBlue() {
    return blue;
}

// Reads color values from an input stream and ensures they are within 0-255.
void Color::read(istream& ins) {
    ins >> red >> green >> blue;
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
}

// Writes color values to an output stream.
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue << endl;
}

// Ensures a color component value is within 0-255.
// If out of range, make it to the nearest valid value (0 or 255)
int Color::checkRange(int val) {
    if (val >= 0 && val <= 255) {
        return val;
    }
    else{
        if (val < 0) {
            return 0;
        }
        else if (val > 255) {
            return 255;
        }
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
