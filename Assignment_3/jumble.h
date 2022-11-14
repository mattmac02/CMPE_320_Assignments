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
    string userInput;
    string diff;

    JumblePuzzle(const string& userI, const string& diffi);

//    JumblePuzzle(const JumblePuzzle& jp){
//        userInput = jp.userInput;
//        diff = jp.diff;
//    }

    charArrayPtr* getJumble() const;
    const int& makeSize();
    int getSize();
    int getRowPos();
    int getColPos();
    char getDirection();
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
