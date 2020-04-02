#include "traits_crawl_experiment.h"

#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include <sstream>


using namespace std;

inline bool file_exist(const string& name)
{
	ifstream file;
	file.open(name.c_str());
	if (!file) { return false; }// File doesn't exist
	else { return true; } //File exists
	file.close();
	file.clear();
	return 0;
}

int main(void)
{
	const string divider = '\n' + string(60, '-') + '\n';

	ifstream input;
	ofstream output;
	string filename;


	cout << "What is the name of the input file?  ";
	getline(cin, filename);
	input.open(filename.c_str());
	while (!input)
	{
		input.close();
		input.clear();

		cout << divider << "File does not exist.\nEnter file name: ";
		getline(cin, filename);
		input.open(filename);
	}
	cout << "'" << filename << "' selected as input file." << endl;

	cout << divider << "Enter a new output file name:  " << endl;
	getline(cin, filename);
	while (file_exist(filename))
	{
		cout << divider << "Error: file '" << filename << "' already exists.\nEnter a new output file name: ";
		getline(cin, filename);
	}
	output.open(filename.c_str());
	cout << "'" << filename << "' selected as output file." << endl;
	
	Experiment experiment;
	
	input.peek();
	while (!input.eof())
	{
		experiment.read(input);
		experiment.write(output);
		input.clear();
		input.peek();
	}
	output.close();
	input.close();

	cout << "Press ENTER to exit." << endl;
	cin.ignore(INT_MAX, '\n');
	return 0;
}

