#include "Money.h"
#include "Check.h"
#include <string>
#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

// Function to swap two checks
inline void Swap(Check &x, Check &y)
{
	Check tmp = x;
	x = y;
	y = tmp;
}

const string divider = string(60, '-') + '\n';

int main()
{

	cout << "Welcome to the Checkbook Balancing Program\n";
	cout << "Cash amounts are entered in the form [$ddd.cc]\n";

	cout << divider << "Enter last month's balance: ";
	bool has_space = true; // indicator if enough space was made for array
	Money last_balance;
	last_balance.input(cin);
	cout << divider << "Enter the balance reported by bank: ";
	Money bank_balance;
	bank_balance.input(cin);
	Check *pcheck = NULL; // creates pointer for check array
	long i, num_checks;
	cout << divider << "How many checks will you enter? ";
	cin >> num_checks;
	while (num_checks < 1)
	{
		cout << "Invalid number.\nHow many checks will you enter? ";
		cin >> num_checks;
	}
	pcheck = new Check[num_checks]; //allocates memore for check array
	Money check_total;
	if (pcheck != NULL) //could allocate space
	{
		char choice;
		cout << divider << "Input from file? y/n: ";
		cin >> choice;
		while (choice != 'y'  && choice != 'n')
		{
			cout << "Invalid option.\nInput from file? y/n : ";
			cin >> choice;
		}

		//***** Inputting from File *****//
		if (choice == 'y')
		{
			//File Stream
			ifstream input;
			string filename;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter file name: ";

			//Entering filename, checking if it exists
			getline(cin, filename);
			input.open(filename.c_str());
			while (!input)
			{
				input.close();
				input.clear();

				cout << "File does not exist.\nEnter file name: ";
				getline(cin, filename);
				input.open(filename.c_str());
			}
			cout << "'" << filename << "' selected as input file." << endl;
			// inputs checks into array
			for (i = 0; i < num_checks; i++)
			{
				pcheck[i].input(input);
			}
			// sums total for cashed checks
			for (i = 0; i < num_checks; i++)
			{
				if (pcheck[i].get_cashed())
				{
					check_total = (pcheck[i].get_amount()).add(check_total);
				}
			}
			cout << divider << "Total from cashed checks:  ";
			check_total.output(cout);
			cout << endl;
			input.close();
		}
		else
			//***** Inputting from Keyboard *****//
		{
			cout << "Enter data in the format (without braces):\n"
				"[Check Number] [Check Amount] [Cashed? y/n]\n";
			//input checks into array
			for (i = 0; i < num_checks; i++)
			{
				pcheck[i].input(cin);
			}
			//sums up cashed checks
			for (i = 0; i < num_checks; i++)
			{
				if (pcheck[i].get_cashed())
				{
					check_total = (pcheck[i].get_amount()).add(check_total);
				}
			}
			cout << divider << "Total from cashed checks:  ";
			check_total.output(cout);
			cout << endl;
		}
	}
	else // failed to allocate space
	{
		cout << "Unable to allocate space." << endl;
		cout << "Please shut down other applications first before running"
			"program.\n";
		has_space = false;
	}
	if (has_space)
	{
		long num_deposits;
		cout << divider << "How many deposits will you enter? ";
		cin >> num_deposits;
		while (num_deposits < 0)
		{
			cout << "Invalid number.\nHow many deposits will you enter? ";
			cin >> num_deposits;
		}
		Money our_balance;
		Money deposit_total;
		if (num_deposits == 0) // user wants to make no deposits
		{
			//Balance = Last balance - cashed checks
			our_balance = last_balance.subtract(check_total);
			cout << divider << "Calculated balance: ";
			our_balance.output(cout);
			cout << endl;
			cout << divider << "Difference between calculated and reported"
				"balance: ";
			our_balance.subtract(bank_balance).output(cout);
			cout << endl;

		}

		else
		{
			Money *pdeposit = NULL;
			// allocates space for array of deposits
			pdeposit = new Money[num_deposits];
			if (pdeposit != NULL) //successfully allocated space
			{
				cout << divider << "Enter deposit amounts separated by spaces"
					"or ENTER key.\n";
				//inputs deposits
				for (i = 0; i < num_deposits; i++)
				{
					pdeposit[i].input(cin);
				}
				//sums deposits
				for (i = 0; i < num_deposits; i++)
				{
					deposit_total = (pdeposit[i]).add(deposit_total);
				}
				cout << divider << "Total from deposits:  ";
				deposit_total.output(cout);
				cout << endl;
				//Balance = Last balance +deposits - cashed checks
				our_balance = deposit_total.add
				(last_balance.subtract(check_total));
				cout << divider << "Calculated balance: ";
				our_balance.output(cout);
				cout << endl;
				cout << divider << "Difference between calculated and"
					"reported balance: ";
				our_balance.subtract(bank_balance).output(cout);
				cout << endl;
				//frees up used space
				delete[] pdeposit;
				pdeposit = NULL;
			}
			else // couldnt make space
			{
				cout << "Unable to allocate space." << endl;
				cout << "Please shut down other applications first before"
					"running program.\n";
				has_space = false;
			}

		}
		if (has_space)
		{
			//Bubble sort checks by increasing order of check#
			for (long j = 0; j < num_checks; j++)
			{
				for (long k = 0; k < num_checks - 1; k++)
					if (pcheck[k].get_number() > pcheck[k + 1].get_number())
					{
						Swap(pcheck[k], pcheck[k + 1]);
					}
			}
			//Outputs cashed checks in order
			cout << divider << "Cashed checks from lowest to highest"
				"check number:\n";
			for (i = 0; i < num_checks; i++)
			{
				if (pcheck[i].get_cashed())
				{
					cout << "Check #" << pcheck[i].get_number() << ": ";
					pcheck[i].get_amount().output(cout);
					cout << endl;
				}
			}
			//Outputs uncashed checks in order
			cout << divider << "Uncashed checks from lowest to highest"
				"check number:\n";
			for (i = 0; i < num_checks; i++)
			{
				if (!(pcheck[i].get_cashed()))
				{
					cout << "Check #" << pcheck[i].get_number() << ": ";
					pcheck[i].get_amount().output(cout);
					cout << endl;
				}
			}
		}

	}
	//frees up used space
	delete[] pcheck;
	pcheck = NULL;

	cout << "\nPress q to quit." << endl;
	cin.ignore(INT_MAX, 'q');
	return 0;

}
