#include "jumble.h"
#include <time.h>
#include <stdlib.h>
#include <string>

//Constructor
JumblePuzzle::JumblePuzzle(const string& userInput, const string& diff) {
    if (userInput.length() <= 2 || userInput.length() >= 11){
        throw BadJumbleException("Not a valid input. Word length not allowed.");
    }
    if (diff != "easy" && diff != "medium" && diff != "hard"){
        throw BadJumbleException("Not a valid game mode.");
    }
    this->diff = diff;
    this->userInput = userInput;
    this->puzzSize = makeSize();
    this->puzz = createPuzz();
}

//Making the Grid Size Based on Game Mode
const int& JumblePuzzle::makeSize() {
    if (diff == "easy"){
        return userInput.length() * 2;
    }
    else if (diff == "medium"){
        return userInput.length() * 3;
    }
    else if (diff == "hard"){
        return userInput.length() * 4;
    }
    return 0;
}

//Create the Puzzle
charArrayPtr *JumblePuzzle::createPuzz() {
    charArrayPtr* filledPuzz = randPuzz(puzzSize);
    int i = 0;
    int pos = 0;
    while (i == 0){
        direc = direcArr[rand() % 4];   //Choosing a random direction out of the 4 possible choices
        colP = rand() % puzzSize;   //Randomly choosing the column to insert to
        rowP = rand() % puzzSize;   //Randomly choosing the row to insert to
        if (direc == 'n'){
            while (rowP >= 0 && pos < userInput.length()){
                filledPuzz[rowP--][colP] = userInput[pos++];    //Insert the word letter by letter in the corresponding direction
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
        else if (direc == 'e'){
            while (colP < puzzSize && pos < userInput.length()){
                filledPuzz[rowP][colP++] = userInput[pos++];
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
        else if (direc == 's'){
            while (rowP < puzzSize && pos < userInput.length()){
                filledPuzz[rowP++][colP] = userInput[pos++];
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
        else if (direc == 'w'){
            while (colP >= 0 && pos < userInput.length()){
                filledPuzz[rowP][colP--] = userInput[pos++];
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
    }
    return filledPuzz;
}

//Initializing the random puzzle being generated and ensuring all letters are in the alphabet and lowercase
charArrayPtr *JumblePuzzle::randPuzz(const int& size) {
    charArrayPtr * randPuzz = new charArrayPtr[size];
    srand(time(NULL));
    int n;
    for (int i = 0; i < size; i++){
        randPuzz[i] = new char[size];
        for (int k = 0; k < size; k++){
            n = rand() % 26;
            randPuzz[i][k] = 'a' + n;
        }
    }
    return randPuzz;
}

//Prevent aliasing
charArrayPtr *JumblePuzzle::getJumble() const {
    charArrayPtr* tempPuzzle = new charArrayPtr[puzzSize];
    for (int i = 0; i < puzzSize; i++) {
        tempPuzzle[i] = new char[puzzSize];
        for (int j = 0; j < puzzSize; j++) {
            tempPuzzle[i][j] = puzz[i][j];
        }
    }
    return tempPuzzle;
}

//Destructor
JumblePuzzle::~JumblePuzzle() {
    for (int i = 0; i < this->puzzSize; i++) {
        delete[] puzz[i];
    }
    delete[] puzz;
    puzz = nullptr;
}

//Operator overloading
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& right) {
    if (this != &right) {
        for (int i = 0; i < puzzSize; i++) {
            delete[] puzz[i];
        }
        delete[] puzz;
        puzzSize = right.getSize();
        rowP = right.getRowPos();
        colP = right.getColPos();
        direc = right.getDirection();

        charArrayPtr* currPuzz = right.getJumble();
        puzz = new charArrayPtr[puzzSize];

        for (int i = 0; i < puzzSize; i++) {
            puzz[i] = new char[puzzSize];
            for (int k = 0; k < puzzSize; k++) {
                puzz[i][k] = currPuzz[i][k];
            }
        }
    }
    return *this;
}

//Exception
BadJumbleException::BadJumbleException(const string& m) : errorMessage(m) {}
string& BadJumbleException::what() { return errorMessage; }


//Copy-Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle &jumb) {
    rowP = jumb.getRowPos();
    colP = jumb.getColPos();
    direc = jumb.getDirection();
    puzzSize = jumb.getSize();

    charArrayPtr* currPuzz = jumb.getJumble();
    puzz = new charArrayPtr[this->puzzSize];

    for (int i = 0; i < puzzSize; i++) {
        puzz[i] = new char[puzzSize];
        for (int j = 0; j < puzzSize; j++) {
            puzz[i][j] = currPuzz[i][j];
        }
    }
}

//Row Position Getter
int JumblePuzzle::getRowPos() const{
    return this->rowP;
}

//Grid Size Getter
int JumblePuzzle::getSize() const{
    return this->puzzSize;
}

//Column Position Getter
int JumblePuzzle::getColPos() const{
    return this->colP;
}

//Direction Getter
char JumblePuzzle::getDirection() const{
    return this->direc;
}