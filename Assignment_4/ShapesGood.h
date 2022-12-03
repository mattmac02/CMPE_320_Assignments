//
// Created by Matthew MacEachern on 12/3/22.
//

#ifndef ASSIGNMENT_4_SHAPESGOOD_H
#define ASSIGNMENT_4_SHAPESGOOD_H


class Shape {
public:
    virtual ~Shape();   // Destructor
    Shape(int l, int w);
    int getLength();
    int getWidth();
private:
    int length;
    int width;
};

class Square : public Shape {
public:
    virtual ~Square();  // Destructor
    void draw();        // Drawing Statement
    Square(int l, int w, string outCol);    // Constructor
    string getOutCol(); // Outline Colour Accessor
private:
    string outCol;
};

class FilledSquare : public Square {
    FilledSquare(int l, int w, string outCol, string fillCol);  // Constructor
    virtual ~FilledSquare();    // Destructor
    string getFillCol();        // Fill Colour Accessor
    void draw();                // Drawing Statement
private:
    string fillCol;
};

class FilledTextSquare : public Square {
public:
    FilledTextSquare(int l, int w, string outCol, string fillCol, string textMessage);
    virtual ~FilledTextSquare();
    void draw();
    void getTextMessage();
    void drawText(string);
private:
    string textMessage;
};


#endif //ASSIGNMENT_4_SHAPESGOOD_H
