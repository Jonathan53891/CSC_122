#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getNumChars(int val)
{
    int total = 0;
    if(val <= 0)
    {
        ++total;
    }
    while(val != 0)
    {
        val /= 10;
        ++total;
    }
    return total;
}

int getValue(int i, int j, char op)
{
    switch(op)
    {
        case '+':
            return i+j;
        case '-':
            return i-j;
        case '*':
            return i*j;
        case '/':
            return i/j;
        case '%':
            return i%j;
        default:
            return 0;
    }
}

int getMaxSize(int n, char ch)
{
    int max = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int n = getNumChars(getValue(i, j, ch));
            if(n > max)
            {
                max = n;
            }
        }
    }
    return max + 1;
}

void displayTable(int n, char op)
{
    int max = getMaxSize(n, op);
    cout << setw(max) << op << "|";
    for(int i = 1; i <= n; ++i)
    {
        cout << setw(max) << i;
    }
    cout << endl;
    for(int i = 0; i < max; ++i)
    {
        cout << "-";
    }
    cout << "+";
    for(int i = 0; i < n * max; ++i)
    {
        cout << "-";
    }
    cout << endl;
    for(int i = 1; i <= n; ++i)
    {
        cout << setw(max) << i << "|";
        for(int j = 1; j <= n; ++j)
        {
            cout << setw(max) << getValue(i, j, op);
        }
        cout << endl;
    }
    cout << endl;
}

char getUserChoice()
{
    cout << "Table Menu" << endl << endl;
    cout << "1) Addition table" << endl;
    cout << "2) Multiplication table" << endl;
    cout << "3) Subtraction table" << endl;
    cout << "4) Division table" << endl;
    cout << "5) Remainder table" << endl;
    cout << "6) Quit" << endl << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    return choice;
}


int getTableSize(string type)
{
    int size;
    while(true)
    {
        cout << "What size should the " << type << " table be? ";
        
	cin >> size;
        if(size <= 0)
        {
            cout << "I'm sorry, " << size << " would be stupid..." << endl;
        }
        else if(size >= 20)
        {
            cout << "I'm sorry, " << size 
	    << " is too large of a table to print on the screen..." << endl;
        }
        else
        {
            cout << endl << "Thank you...calculating..." << endl << endl;
            return size;
        }
    }
}


int main()
{
    cout << "\t\tWelcome to the Math Table Program!!!" << endl;
    char choice;
    int size;
    while(true)
    {
        choice = getUserChoice();
        switch(choice)
        {
            case 'a':
            case 'A':
            case '1':
                size = getTableSize("addition");
                displayTable(size, '+');
                break;
            case 'm':
            case 'M':
            case '2':
                size = getTableSize("multiplication");
                displayTable(size, '*');
                break;
            case 's':
            case 'S':
            case '3':
                size = getTableSize("subtraction");
                displayTable(size, '-');
                break;
            case 'd':
            case 'D':
            case '4':
                size = getTableSize("division");
                displayTable(size, '/');
                break;
            case 'r':
            case 'R':
            case '5':
                size = getTableSize("remainder");
                displayTable(size, '%');
                break;
            case 'q':
            case 'Q':
            case '6':
                cout << "Thank you for using the MTP!!" << endl;
                cout << "Endeavor to have a auspicious day!" << endl;
                return 0;
        }
    }
    return 0;
}
