
// Mohammadreza Akbari Lor

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<utility>
#include"Functions.h"

using namespace std;

int s = 0;

int main() {

	// defining input and output streams
	ifstream fin;
	ofstream fout;

	// opening file and checking to see if it's properly opened.
	try {
		fin.open("input.txt", ios::in);

		if (!fin.is_open()) {
			throw runtime_error("Cannot open file!");
		}
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return -1;
	}

	// the main variable that all of our media is saved in
	int list[200];

	// reading data file and saving information in a vector
	ReadDataFile(fin, fout, list, s);

	// closing input and output files
	fin.close();
	fout.close();

	char menuInput;

	// first call of the menu
	menuInput = MainMenu();

	// loop for remaining in menu until Q is selected and executing other commands
	while (menuInput != 'Q') {

		// selecting commad based on user input
		switch (menuInput)
		{
		case 'C':
		{
			int c = CheckForValue(list, s);
			if (c == -1) {
				cout << "the value dosn't exist in the array!" << endl;
				cout << endl;
			}
			else {
				cout << "the value is at position " << c << "!" << endl;
				cout << endl;
			}
		}
			break;
		case 'M':
		{
			pair<int, int> m;
			m = Modify(list, s);
			cout << "<Old value, New value> = <" << m.first << ", " << m.second << ">" << endl;
			cout << endl;
		}
			break;
		case 'A':
		{
			Add(list, s);
		}
			break;
		case 'R':
		{
			int index;
			cout << "Enter the index you wish to be removed: ";
			cin >> index;
			cout << endl;
			Remove(list, s, index);
		}
			break;
		default:
		{
			cout << endl;
			cout << "Error: Wrong input! Try again!" << endl;
			cout << endl;
			cout << endl;
		}
			break;
		}

		// succesive calls to menu
		menuInput = MainMenu();

	}
	
	return 0;

}