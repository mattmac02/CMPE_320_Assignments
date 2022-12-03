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

// Length Accessor
int Shape::getLength() {
    return this->length;
}

// Width Accessor
int Shape::getWidth() {
    return this->width;
}

// Square Functions
// Destructor
Square::~Square() {}

// Constructor
Square::Square(int l, int w, std::string outCol) {
    outlineCol = outCol;
}

// Outside Colour Accessor
std::string Square::getOutCol() {
    return this->outlineCol;
}

// Drawing Statement
void Square::draw() {
    cout << "Drawing a " + getOutCol() + " square\n";
}

// Filled Square Functions
// Constructor
FilledSquare::FilledSquare(int l, int w, std::string outCol, std::string fillCol) {
    fillColour = fillCol;
}

// Destructor
FilledSquare::~FilledSquare() {}

// Fill Colour Accessor
std::string FilledSquare::getFillCol() {
    return this->fillColour;
}

// Drawing Statement
void FilledSquare::draw() {
    cout << "Drawing a square with a " + getOutCol()  + "border and a " + getFillCol() + "fill";
}

// Filled Text Square Functions
// Destructor
FilledTextSquare::~FilledTextSquare() {}

// Constructor
FilledTextSquare::FilledTextSquare(int l, int w, std::string outCol, std::string fillCol, std::string textMessage) {
    textMess = textMessage;
}

// Accessor
void FilledTextSquare::getTextMessage() {
    return this->textMess;
}

// Drawing Statement
void FilledTextSquare::draw() {
    cout << "Drawing a square with a " + getOutCol()  + "border and a " + getFillCol() + "fill containing the text " + getTextMessage();
}

