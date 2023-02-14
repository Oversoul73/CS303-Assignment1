
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<utility>
#include"Functions.h"

using namespace std;

char MainMenu() {

    char menuInput;

    // printing the menu header and options
    cout << "     MENU CHOICES" << endl;
    cout << "C - Check if a certain integer exists in the array" << endl;
    cout << "M - Modify the value at specific index" << endl;
    cout << "A - Add value to the end" << endl;
    cout << "R - Remove the value at specific index" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter your choice: ";

    // getting user input for menu
    cin >> menuInput;
    menuInput = toupper(menuInput);

    // returning the upper case of inputed letter to main
    switch (menuInput) {
    case 'C':
        return 'C';
        break;
    case 'M':
        return 'M';
        break;
    case 'A':
        return 'A';
        break;
    case 'R':
        return 'R';
        break;
    case 'Q':
        return 'Q';
        break;
    default:
        return 'E';
        break;
    }

}

void ReadDataFile(ifstream& fin, ofstream& fout, int main[], int& size) {

    string line, word;
    vector<string> tempVec;

    while (!(fin.eof())) {

        // clearing temporary variables for re-use
        tempVec.clear();

        // read an entire row and store it in a string variable 'line'
        getline(fin, line);

        // condition to check whether there is an empty line in the end
        if (line == "" || line.at(0) == 'Q') { break; }

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and store it in a string variable, 'word'
        while (getline(s, word, ',')) {

            // add all the column data of a row to a vector
            if (word != "") {
                tempVec.push_back(word);
            }

        }

        for (int i = 0; i < tempVec.size(); ++i) {
            main[size] = stoi(tempVec.at(i));
            ++size;
        }

    }

}

int CheckForValue(int list[], int s) {

    int n;

    cout << "Enter the number you are looking for: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < s; ++i) {
        if (n == list[i]) {
            return i;
        }
    }

    return -1;

}

pair<int, int> Modify(int list[], int s) {

    int n;

    while (1) {

        try {
            cout << "Enter the index you wish to modify: ";
            cin >> n;
            cout << endl;
            if (cin.fail()) {
                cout << "Wrong type input! the input must be integer." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                throw "Wrong type input! the input must be integer.";
            }
            else if (n >= s || n < 0) {
                cout << "Out of range! index does not exist." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                throw "Out of range! index does not exist.";
            }
        }
        catch (...) {
            cout << "Try Again!" << endl;
            continue;
        }

        break;

    }

    int temp;

    while (1) {

        try {
            cout << "Enter the value you wish to be at index " << n << ": ";
            cin >> temp;
            cout << endl;
            if (cin.fail()) {
                cout << "Wrong type input! the input must be integer." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                throw "Wrong type input! the input must be integer.";
            }
        }
        catch (...) {
            cout << "Try Again!" << endl;
            continue;
        }

        break;

    }

    pair<int, int> result;

    result.first = list[n];
    result.second = temp;
    list[n] = temp;

    return result;

}

void Add(int list[], int& s) {

    int temp;

    while (1) {

        try {
            cout << "Enter the value you wish to be at the end: ";
            cin >> temp;
            cout << endl;
            if (cin.fail()) {
                cout << "Wrong type input! the input must be integer." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                throw "Wrong type input! the input must be integer.";
            }
        }
        catch (...) {
            cout << "Try Again!" << endl;
            continue;
        }

        break;

    }

    list[s] = temp;
    ++s;

    return;

}

void Remove(int list[], int s, int index) {

    list[index] = 0;

    return;

}