//
// Created by Matthew MacEachern on 12/3/22.
//

#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

// Shape Functions
// Destructor
Shape::~Shape() {}

// Constructor
Shape::Shape(int l, int w) {
    this->length = l;
    this->width = w;
}

// Drawing Statement
void Shape::draw() {
    cout << "\nDrawing the default class where no shape will be drawn\n";
}

// Length Accessor
int Shape::getLength() {
    return this->length;
}

// Width Accessor
int Shape::getWidth() {
    return this->width;
}

// Label Functions
// Constructor
Label::Label(string lab) {
    label = lab;
}

// Accessor
string Label::getLabel() {
    return this->label;
}

// Destructor
Label::~Label() {}

//Fill Functions
// Destructor
Fill::~Fill() {}

// Fill Colour Accessor
string Fill::getFillCol() {
    return this->fillColour;
}

// Constructor
Fill::Fill(string fillCol) {
    fillColour = fillCol;
}

// Square Functions
// Destructor
Square::~Square() {}

// Constructor
Square::Square(int l, int w, std::string outlineCol) : Shape(l, w){
    outCol = outlineCol;
}

// Outside Colour Accessor
std::string Square::getOutCol() {
    return this->outCol;
}

// Drawing Statement
void Square::draw() {
    cout << "\nDrawing a " + getOutCol() + " square\n";
}

// Filled Square Functions
// Constructor
FilledSquare::FilledSquare(int l, int w, std::string outCol, std::string fillColour) : Square(l, w, outCol), Fill(fillColour) {}

// Destructor
FilledSquare::~FilledSquare() {}

// Drawing Statement
void FilledSquare::draw() {
    cout << "\nDrawing a square with a " + getOutCol()  + " border and a " + getFillCol() + " fill\n";
}

// Filled Text Square Functions
// Destructor
FilledTextSquare::~FilledTextSquare() {}

// Constructor
FilledTextSquare::FilledTextSquare(int l, int w, std::string outCol, std::string fillCol, std::string label) : Square(l, w, outCol), Fill(fillCol),Label(label) {}

// Drawing Statement
void FilledTextSquare::draw() {
    cout << "\nDrawing a square with a " + getOutCol()  + " border and a " + getFillCol() + " fill containing the text \"" + getLabel() + "\"\n";
}

// Circle Functions
// Constructor
Circle::Circle(int l, int w, std::string outlineCol) : Shape(l, w) {
    outCol = outlineCol;
}

// Outline Colour Accessor
std::string Circle::getOutCol() {
    return this->outCol;
}

// Destructor
Circle::~Circle() {}

// Drawing Statement
void Circle::draw() {
    cout << "\nDrawing a circle with a " + getOutCol() + " outline\n";
}

// Filled Circle Functions
// Constructor
FilledCircle::FilledCircle(int l, int w, std::string outCol, std::string fillColour) : Circle(l, w, outCol), Fill(fillColour) {}

// Drawing Statement
void FilledCircle::draw() {
    cout << "\nDrawing a circle with a " + getOutCol() + " outline and a " + getFillCol() + " fill\n";
}

// Destructor
FilledCircle::~FilledCircle() {}

// Arc Functions
// Accessor
std::string Arc::getOutCol() {
    return this->outCol;
}

// Constructor
Arc::Arc(int l, int w, std::string outlineCol) : Shape(l, w) {
    outCol = outlineCol;
}

// Destructor
Arc::~Arc() {}

// Drawing Statement
void Arc::draw() {
    cout << "\nDrawing an arc with a " + getOutCol() + " outline\n";
}