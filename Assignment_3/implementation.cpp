#include "jumble.h"

const charArrayPtr *JumblePuzzle::getJumble() const {

    arrSize = getSize();


    return nullptr;
}

const int& JumblePuzzle::makeSize() {
    if (diff == "easy"){
    return userInput.length() * 2;
    printf("heyo");
    }
    else if (diff == "medium"){
        return userInput.length() * 3;
    }
    else if (diff == "hard" || diff == "extreme"){
        return userInput.length() * 4;
    }
    return 0;
}

int JumblePuzzle::getRowPos() {
    return 0;
}

int JumblePuzzle::getColPos() {
    return 0;
}

char JumblePuzzle::getDirection() {
    return 0;
}

JumblePuzzle::JumblePuzzle(const string& userIn, const string& diffi) {
    if (userIn.length() <= 2 && userIn >= 11){
        printf("Not a valid input");
        exit();
    }
    if (diffi != "easy" || diffi != "medium" || diffi != "hard" || diffi != "extreme" ||){
        printf("Not a valid game mode");
        exit();
    }
    this->userIn = userIn;
    this->diffi = diffi;
    this->size = getSize();
    this->puzzCreate = getJumble();
}
