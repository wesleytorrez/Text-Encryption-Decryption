/*
 * Author: Wesley Torrez
 * CS-320
 * Professor Healey
 * MarbleString.h
*/

#ifndef LAB2_MARBLESTRING_H
#define LAB2_MARBLESTRING_H
#include <iostream>

using namespace std;

class MarbleString {
private:
    int currentSize;
    string unscrambled;

public:
    MarbleString(char data[]);

private:
     static string scramble(string data);

public:
    int size();

private:
    friend ostream& operator << (ostream& os, MarbleString& obj);
};

#endif //LAB2_MARBLESTRING_H
