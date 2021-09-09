/*
 * Author: Wesley Torrez
 * CS-320
 * Professor Healey
 * MarbleString.cpp
*/

#include "MarbleString.h"


MarbleString::MarbleString(char data[]) {
    unscrambled = scramble(data);
    currentSize = unscrambled.size();
    char marbleString[currentSize];
    strcpy(marbleString, unscrambled.c_str());
}

string MarbleString::scramble(string data) {
    string scrambled = data;
    for (int i = 0; i < scrambled.size(); i++) {
        scrambled[i] = (unsigned) data[i] ^ scrambled.size();
    }
    return scrambled;
}

int MarbleString::size() { return currentSize; }

ostream& operator << (ostream& os, MarbleString& obj) {
    os << MarbleString::scramble(obj.unscrambled);
    return os;
}
