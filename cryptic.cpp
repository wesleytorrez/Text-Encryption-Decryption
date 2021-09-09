/*
 * Author: Wesley Torrez
 * CS-320
 * Professor Healey
 * cryptic.cpp
*/

#include <iostream>

using namespace std;

char fruits[] = "grapes, watermelon, kiwi";
char movies[ ] = "Pulp Fiction, The Lion King, WALL-E";
string name = "char data[] = hi";
string thing = "character";
char letter = 'a';
char animals[   ] = "pig,   goat,  dog,  cat    ";

class randomClass {
    char arr[];

    randomClass() {}

    int randomIntFunc() {
        int x;
        char y;
        x = 2;
        y = 'k';
        return x;
    }

    char randCharFunc() {
        char maths[] = "add, subtract, multiply, divide";
        char food[] = "pizza, sandwich, salad";
        char w = 'w';
        return w;
    }

    string randStringFunc() {
        string progLang = "CS-320";
        return progLang;
    }
};