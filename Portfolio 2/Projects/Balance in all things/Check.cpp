#include "Check.h"
#include "Money.h"
#include <iostream>

using namespace std;
//Function to input data into check
void Check::input(std::istream & ins)
{
	char choice;
	ins >> number;
	amount.input(ins);
	ins >> choice;
	//returns true or false depending on y/n
	if (choice == 'y')
	{
		cashed = true;
	}
	else
	{
		cashed = false;
	}

}
