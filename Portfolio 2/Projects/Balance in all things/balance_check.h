#ifndef BALANCE_CHECK_H
#define BALANCE_CHECK_H
//Check Implementation File
#include <iostream>
#include "balance_money.h"

class Check
{
	//member variables
	long number;
	Money amount;
	bool cashed;

public:
	// Constructor
	Check() : number(), amount(), cashed() {}
	//Accessors
	long get_number() { return number; }
	Money get_amount() { return amount; }
	bool get_cashed() { return cashed; }
	//Mutator
	void input(std::istream & ins);	
};

#endif

