/*
 * Author: Wesley Torrez
 * CS-320
 * Professor Healey
 * Driver.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "MarbleString.h"

using namespace std;

vector<string> openFile(const string& path) {
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Cannot open file" << "\n";
        exit(1);
    }

    vector<string> words;
    string token;
    string insertionPoint;
    bool inserted = false;
    string preProcessor = "#include \"MarbleString.h\"";

    while (getline(file, token)) {
        if (token == insertionPoint && !inserted) {
            words.push_back(preProcessor);
            inserted = true;
        }
        words.push_back(token);
    }
    file.close();
    return words;
}

bool hasStatement(const string& data) {
    string statement = "=";
    return (data.find(statement) != string::npos);
}

bool hasChar(const string& data) {
    string charType = "char";
    string quotes = "\"char";
    return (data.find(charType) != string::npos &&
            !(data.find(quotes) != string::npos));
}

bool hasBracket(const string& data) {
    string bracket = "]";
    return (data.find(bracket) != string::npos);
}

void split(const string& s, char c,
           vector<string>& v) {
    size_t i = 0;
    size_t j = s.find(c);

    while (j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}

void findAndReplaceAll(string & data, string toSearch
        , string replaceStr)
{
    size_t pos = data.find(toSearch);

    while( pos != string::npos)
    {
        data.replace(pos, toSearch.size(), replaceStr);
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

string getStrBetweenTwoStr(const string &s,
                               const string &startDelim,
                               const string &stopDelim)
{
    unsigned firstDelimPos = s.find(startDelim);
    unsigned endPosOfFirstDelim = firstDelimPos +
            startDelim.length();
    unsigned lastDelimPos = s.find_first_of(stopDelim,
            endPosOfFirstDelim);

    return s.substr(endPosOfFirstDelim,
                    lastDelimPos - endPosOfFirstDelim);
}

string scramble(string data) {
    string scrambled = data;
    for (int i = 0; i < scrambled.size(); i++) {
        scrambled[i] = (unsigned) data[i] ^ scrambled.size();
    }
    return scrambled;
}

int main() {

    ofstream myFile;
    ofstream outFile;
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;

    vector<string> v = openFile(fileName);

    outFile.open("mbl-cryptic.cpp");

    for (int i = 0; i < v.size(); i++) {
        myFile.open("mbl-cryptic.cpp");
        if(hasStatement(v[i]) && hasChar(v[i]) &&
        hasBracket(v[i])) {
            findAndReplaceAll(v[i], "char", "MarbleString");
            findAndReplaceAll(v[i], "[", "");
            findAndReplaceAll(v[i], "]", "");
            string str = getStrBetweenTwoStr(v[i], "\"", "\"");
            findAndReplaceAll(v[i], str, scramble(str));
        }
        outFile << v[i] << endl;
    }
    return 0;
}
