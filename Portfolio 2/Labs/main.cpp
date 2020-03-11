

#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;

// checks if file exists
inline bool file_exist(const string& name)
{
    ifstream file;
    file.open(name.c_str());
    if (!file) { return false; }// File doesn't exist
    else { return true; } //File exists
    file.close();
    file.clear();
}



int main(void)
{
    const string divider = '\n' + string(60, '-') + '\n';

    ifstream original;
    ofstream copy;
    string filename;


    cout << "What is the name of the file to copy?  ";
    getline(cin, filename);
    original.open(filename.c_str());
    //loop that will keep asking for the name of the file if it cant find it
    while (!original)
    {
        original.close();
        original.clear();
        cout << divider << "File does not exist.\nEnter file name: ";
        getline(cin, filename);
        original.open(filename.c_str());
    }
    cout << "'" << filename << "' selected as file to copy." << endl;

    cout << divider << "Enter a new output file name:  ";
    getline(cin, filename);
    while (file_exist(filename))
    {
        cout << divider << "Error: file '" << filename << "' already exists."
            "\nEnter a new output file name: ";
        getline(cin, filename);
    }
    copy.open(filename.c_str());
    cout << "'" << filename << "' selected as output file." << endl;
    Student person;
    //peeks at first part of file, esp. important for checking to see if
    //file is blank, then will return eof
    original.peek();
    while (!original.eof()) // until end of file
    {
        person.read(original); //read in
        person.write(copy); //write
        original.peek();
    }
    //close streams when done.
    copy.close();
    original.close();

    cout << "Press ENTER to exit." << endl;
    cin.ignore(INT_MAX, '\n');
    return 0;
}

