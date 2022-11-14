//
// Created by Matthew MacEachern on 11/11/22.
//

#ifndef ASSIGNMENT_3_JUMBLE_H
#define ASSIGNMENT_3_JUMBLE_H
#include <string>
#include <exception>

using namespace std;
typedef char* charArrayPtr;

class JumblePuzzle {
public:
    //Variable Declaration
    string userInput;
    string diff;
    int size;
    int puzzSize;
    int rowP;
    int colP;
    char direcArr[4] = {'n', 'e', 's', 'w'};    //Direction array
    char direc;

    JumblePuzzle& operator=(const JumblePuzzle&); //Assignment Operator

    JumblePuzzle(const string& toHide, const string& difficulty);   //Constructor

    JumblePuzzle(const JumblePuzzle&);  //Copy-Constructor

    ~JumblePuzzle();    //Destructor

    charArrayPtr* puzz = nullptr;
    charArrayPtr* createPuzz(); //Puzzle creation
    charArrayPtr* randPuzz(const int& size);    //Random letter creation and insertion
    charArrayPtr* getJumble() const;    //Aliasing prevention

    const int& makeSize();  //Making the size of the grid
    int getSize() const;    //Getting the size of the grid
    int getRowPos() const;  //Getting the row position
    int getColPos() const;  //Getting the column position
    char getDirection() const;  //Getting the direction
};

//Exception Class
class BadJumbleException : public exception {
public:
    BadJumbleException(const string& errorMessage);
    string& what();
private:
    string errorMessage;
};

#endif //ASSIGNMENT_3_JUMBLE_H
