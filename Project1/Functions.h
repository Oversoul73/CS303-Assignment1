#pragma once

#include<utility>

using namespace std;

char MainMenu();
// pre:   loads menu and give option to give an input
// post:  returns input to main

void ReadDataFile(ifstream& fin, ofstream& fout, int main[], int& size);
// pre:   files are open in main & accessible
// post:  reads the data from txt file and loads the objects into an array

int CheckForValue(int list[], int s);
// pre:   user has selected to check the array for a specific value
// post:  returns position of value if found and -1 if not

pair<int, int> Modify(int list[], int s);
// pre:   user has selected to modify the value at a specific index
// post:  returns the pair consisting of the new value and old value

void Add(int list[], int& s);
// pre:   user has selected to add a value at the end of array
// post:  the value is added and the end of the array

void Remove(int list[], int s, int index);
// pre:   user has selected to remove a value in the array
// post:  the value is replaced with zero