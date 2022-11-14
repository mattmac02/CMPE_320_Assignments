#include "jumble.h"
#include <time.h>
#include <stdlib.h>
#include <string>

//Constructor
JumblePuzzle::JumblePuzzle(const string& userInput, const string& diff) {
    if (diff != "easy" && diff != "medium" && diff != "hard"){  //Invalid game difficulty input
        throw BadJumbleException("Not a valid game mode.");
    }
    if (userInput.length() <= 2 || userInput.length() >= 11){   //Length is not between 3 and 10
        throw BadJumbleException("Not a valid input. Word length not allowed.");
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
    int c;
    int r;
    while (i == 0){
        int pos = 0;
        direc = direcArr[rand() % 4];   //Choosing a random direction out of the 4 possible choices
        colP = rand() % puzzSize;   //Randomly choosing the column to insert to
        rowP = rand() % puzzSize;   //Randomly choosing the row to insert to
        c = this->colP;
        r = this->rowP;
        if (direc == 'n'){
            while (r >= 0 && pos < userInput.length()){
                filledPuzz[r--][c] = userInput[pos++];    //Insert the word letter by letter in the corresponding direction
            }
            if (rowP == puzzSize && pos != userInput.length()){ //Entire word has not been inserted so stay in the while loop but with a new random direction
                direc = direcArr[rand() % 4];
            }
            if (pos == userInput.length()){ //If the word has been entirely inserted exit the while loop by setting i = 1
                i = 1;
            }
        }
        else if (direc == 's'){
            while (r < puzzSize && pos < userInput.length()){
                filledPuzz[r++][c] = userInput[pos++];
            }
            if (rowP == puzzSize && pos != userInput.length()){
                direc = direcArr[rand() % 4];
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
        else if (direc == 'e'){
            while (c < puzzSize && pos < userInput.length()){
                filledPuzz[r][c++] = userInput[pos++];
            }
            if (rowP == puzzSize && pos != userInput.length()){
                direc = direcArr[rand() % 4];
            }
            if (pos == userInput.length()){
                i = 1;
            }
        }
        else if (direc == 'w'){
            while (c >= 0 && pos < userInput.length()){
                filledPuzz[r][c--] = userInput[pos++];
            }
            if (rowP == puzzSize && pos != userInput.length()){
                direc = direcArr[rand() % 4];
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
            randPuzz[i][k] = 'a' + n;   //Ensuring the character is a lowercase letter in the alphabet
        }
    }
    return randPuzz;
}

//Prevent aliasing by creating tempPuzz to differentiate the puzzle objects
charArrayPtr *JumblePuzzle::getJumble() const {
    charArrayPtr* tempPuzz = new charArrayPtr[puzzSize];
    for (int i = 0; i < puzzSize; i++) {
        tempPuzz[i] = new char[puzzSize];
        for (int j = 0; j < puzzSize; j++) {
            tempPuzz[i][j] = puzz[i][j];
        }
    }
    return tempPuzz;
}

//Destructor for deleting a 2D array from the heap
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
