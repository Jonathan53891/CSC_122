#include <fstream>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

int main(void)
{
	ifstream data_file;
	string fname;
	string line;
	double num;
	char ch;

	cout << "What is the name of the file?  ";
	getline(cin, fname);
	data_file.open(fname.c_str());

	/*
	* char-wise input with get()
	*/
	cout << "Plain while (get):\n";
	data_file.get(ch);
	while (!data_file.eof())
	{
		cout << "char read '" << ch << "'\n";
		data_file.get(ch);
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked while (get):\n";
	data_file.peek();
	while (!data_file.eof())
	{
		data_file.get(ch);
		cout << "char read '" << ch << "'\n";
		data_file.peek();
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Plain do (get):\n";
	do
	{
		data_file.get(ch);
		cout << "char read '" << ch << "'\n";
	} while (!data_file.eof());

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked do (get):\n";
	data_file.peek();
	do
	{
		data_file.get(ch);
		cout << "char read '" << ch << "'\n";
		data_file.peek();
	} while (!data_file.eof());

	cout << "Done with get(char) testing...\n\nPress <Enter> to continue...\n";
	cin.ignore(INT_MAX, '\n');

	/*
	* numeric input with >>
	*/
	data_file.clear();
	data_file.seekg(0);
	cout << "Plain while (>>):\n";
	data_file >> num;
	while (!data_file.eof())
	{
		cout << "number read '" << num << "'\n";
		data_file >> num;
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked while (>>):\n";
	data_file >> ws;
	while (!data_file.eof())
	{
		data_file >> num >> ws;
		cout << "number read '" << num << "'\n";
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Plain do (>>):\n";
	do
	{
		data_file >> num;
		if (!data_file.eof())
		{
			cout << "number read '" << num << "'\n";
		}
	} while (!data_file.eof());

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked do (>>):\n";
	do
	{
		data_file >> num >> ws;
		cout << "number read '" << num << "'\n";
	} while (!data_file.eof());

	cout << "Done with >> testing...\n\nPress <Enter> to continue...\n";
	cin.ignore(INT_MAX, '\n');

	/*
	* whole-line input with getline()
	*/
	data_file.clear();
	data_file.seekg(0);
	cout << "Plain while (getline):\n";
	getline(data_file, line);
	while (!data_file.eof())
	{
		cout << "line read '" << line << "'\n";
		getline(data_file, line);
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked while (getline):\n";
	data_file.peek();
	while (!data_file.eof())
	{
		getline(data_file, line);
		cout << "line read '" << line << "'\n";
		data_file.peek();
	}

	data_file.clear();
	data_file.seekg(0);
	cout << "Plain do (getline):\n";
	do
	{
		getline(data_file, line);
		if (!data_file.eof())
		{
			cout << "line read '" << line << "'\n";
		}
	} while (!data_file.eof());

	data_file.clear();
	data_file.seekg(0);
	cout << "Hacked do (getline):\n";
	do
	{
		getline(data_file, line);
		cout << "line read '" << line << "'\n";
		data_file.peek();
	} while (!data_file.eof());

	data_file.close();
	data_file.clear();

	return 0;
}

