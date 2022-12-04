//
// Created by Matthew MacEachern on 12/3/22.
//

#ifndef ASSIGNMENT_4_SHAPESGOOD_H
#define ASSIGNMENT_4_SHAPESGOOD_H
#include <string>
using namespace std;

class Shape {
public:
    virtual ~Shape();       // Destructor
    Shape(int l, int w);    // Constructor
    virtual void draw();    // Drawing Statement
    int getLength();        // Length Accessor
    int getWidth();         // Width Accessor
private:
    int length;
    int width;
};

class Label {
public:
    Label(string lab);  // Constructor
    virtual ~Label();   // Destructor
    string getLabel();  // Label Accessor
private:
    string label;
};

class Fill {
public:
    Fill(string fillColour);    // Constructor
    virtual ~Fill();            // Destructor
    string getFillCol();        // Fill Colour Accessor
private:
    string fillColour;
};

class Square : public Shape {
public:
    virtual ~Square();                      // Destructor
    virtual void draw();                    // Drawing Statement
    Square(int l, int w, string outCol);    // Constructor
    string getOutCol();                     // Outline Colour Accessor
private:
    string outCol;
};

class FilledSquare : public Square, public Fill {
public:
    FilledSquare(int l, int w, string outCol, string fillCol);  // Constructor
    virtual ~FilledSquare();                                    // Destructor
    virtual void draw();                                        // Drawing Statement
};

class FilledTextSquare : public Square, public Fill, public Label {
public:
    FilledTextSquare(int l, int w, string outCol, string fillCol, string lab);  // Constructor
    virtual ~FilledTextSquare();                                                // Destructor
    virtual void draw();                                                        // Drawing Statement
};

class Circle : public Shape {
public:
    Circle(int l, int w, string outCol);    // Constructor
    virtual ~Circle();                      // Destructor
    virtual void draw();                    // Drawing Statement
    string getOutCol();                     // Outline Colour Accessor
private:
    string outCol;
};

class FilledCircle : public Circle, public Fill {
public:
    FilledCircle(int l, int w, string outCol, string fillCol);  // Constructor
    virtual void draw();                                        // Drawing Statement
    virtual ~FilledCircle();                                    // Destructor
};

class Arc : public Shape {
public:
    Arc(int l, int w, string outCol);   // Constructor
    virtual void draw();                // Drawing Statement
    string getOutCol();                 // Outline Colour Accessor
    virtual ~Arc();                     // Destructor
private:
    string outCol;
};

#endif //ASSIGNMENT_4_SHAPESGOOD_H
