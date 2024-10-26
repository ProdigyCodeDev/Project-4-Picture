/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character:
 *              1. clears drawer 
 *              2. prints "[Error in input file: " << character already read
 *                     "]" << endl;
 *              3. close file
 *              4. return
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cin, cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

// Writes the current drawing on the Graphics canvas to a BMP file.
void writeFile(const Graphics& drawer)
{
    string fileName;
    cin >> fileName;
    fileName += ".bmp";
    
    drawer.writeFile(fileName);
    cout << "[Wrote " << fileName << "]" << endl;
}

// Loads shapes from a file and draws them on the Graphics canvas.
void loadFile(Graphics& drawer)
{
    ifstream file;
    string fileName = openFile(file);
    char shapeType;
    
    drawer.clear();
    
    while (file >> shapeType) {
            if (shapeType == 'L') {
                Point pt1, pt2;
                Color color;
                file >> pt1 >> pt2 >> color;
                Line line(pt1, pt2, color);
                line.draw(drawer);
            }
            else if (shapeType == 'C') {
                Point center;
                int radius;
                Color color;
                file >> center >> radius >> color;
                Circle circle(center, radius, color);
                circle.draw(drawer);
            }
            else if (shapeType == 'T') {
                Point pt1, pt2, pt3;
                Color color1, color2, color3;
                file >> pt1 >> color1 >> pt2 >> color2 >> pt3 >> color3;
                Triangle triangle(pt1, color1, pt2, color2, pt3, color3);
                triangle.draw(drawer);
            }
            else if (shapeType == 'R') {
                Point p1, p2;
                Color cTopL, cTopR, cBottomL, cBottomR;
                file >> p1 >> p2 >> cTopL >> cTopR >> cBottomR >> cBottomL;
                Rectangle rectangle(p1, p2, cTopL, cTopR, cBottomR, cBottomL);
                rectangle.draw(drawer);
            }
            else {
                drawer.clear();
                cout << "[Error in input file: " << shapeType << "]" << endl;
                file.close();
                return;
            }
        }

        file.close();
        cout << "[Loaded " << fileName << "]" << endl;
    }

// Converts an input string to all lowercase characters.
string tolower(string str) {
    string newString = "";
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if ((str.at(i) >= 'A') && (str.at(i) <= 'Z')) {
            char currChar = str.at(i);
            newString += tolower(currChar);
        }
        else {
            newString += str.at(i);
        }
    }
    return newString;
}
// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
