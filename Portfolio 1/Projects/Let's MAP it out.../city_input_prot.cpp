#include <string>
#include <iostream>
#include "city_input_prot.h"
#include <vector>
#include <cmath>
#include <climits>


using namespace std;

//******************************************
// Checks to see if input is a valid long

void input_prot(long& input, const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (done == false) // until valid input is given
    {

        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else // valid
        {
            done = true;
        }

    }
}

// min or max

void input_prot(long& input, const long& bound, const string& prompt,
        const string& error_prompt, const bool& bound_is_max)
{
    bool done = false;
    while (done == false) // until valid input is given
    {
        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else if (!bound_is_max) // bound value is minimum
        {
            if (input < bound)
            {
                cerr << error_prompt << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                done = false;
            }
            else
            {
                done = true;
            }
        }
        else // bound value is max
        {
            if (input > bound)
            {
                cerr << error_prompt << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                done = false;
            }
            else
            {
                done = true;
            }
        }
    }
}

// min and max

void input_prot(long& input, const long& min,
        const long& max, const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (done == false) // until valid input is given
    {
        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else if (input < min || input > max)
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else // valid
        {
            done = true;
        }
    }
}
//******************************************
// Checks to see if input is in list of long

void list_input_prot(long& input, const vector<long>& list,
        const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (!done) // until valid input is given
    {
        input_prot(input, prompt, error_prompt);
        for (vector<long>::size_type pos = 0; pos < list.size(); pos++)
        {
            if (input == list[pos]) // if found in list, search is done
            {
                done = true;
            }
        }
        if (!done) // not found in list
        {
            cerr << error_prompt << endl;
        }

    }
}
// Checks to see if input is a valid double

void input_prot(double& input, const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (done == false) // until valid input is given
    {

        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else // valid
        {
            done = true;
        }

    }
}

//min or max

void input_prot(double& input, const double& bound,
        const string& prompt, const string& error_prompt,
        const bool& bound_is_max)
{
    bool done = false;
    while (done == false) // until valid input is given
    {
        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else if (!bound_is_max) // bound value is minimum
        {
            if (input < bound)
            {
                cerr << error_prompt << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                done = false;
            }
            else
            {
                done = true;
            }
        }
        else // bound value is max
        {
            if (input > bound)
            {
                cerr << error_prompt << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                done = false;
            }
            else
            {
                done = true;
            }
        }
    }//end of while ()
}// end of void input_prot()

//min and max

void input_prot(double& input, const double& min, const double max,
        const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (done == false) // until valid input is given
    {
        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else if (cin.fail()) // cin fails
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;

        }
        else if (input < min || input > max)
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }
        else // valid
        {
            done = true;
        }
    }//end of while()
}//end of void input_prot()
//******************************************
// Checks to see if input is in list of double

void list_input_prot(double& input, const vector<double>& list,
        const string& prompt, const string& error_prompt)
{
    bool done = false;
    while (done == false) // until valid input is given
    {

        input_prot(input, prompt, error_prompt);
        for (vector<double>::size_type pos = 0; pos < list.size(); pos++)
        {
            if (fabs((input - list[pos])) < 1e-6) // if found in list, search is done
            {
                done = true;
            }
        }
        if (!done) // not found in list
        {
            cerr << error_prompt << endl;
        }


    }
}

//******************************************
// Checks to see if input is a valid char

void input_prot(char& input, const string& prompt,
        const string& error_prompt)
{
    bool done = false;
    while (!done) // until valid input is given
    {
        cout << prompt;
        cin >> input;
        if (cin.peek() != '\n') // any extra character ahead of input
        {
            cerr << error_prompt << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            done = false;
        }

        else
        {
            done = true;
        }

    }
}

//******************************************
// Checks to see if input is in list of chars

void list_input_prot(char& input, const vector<char>& list,
        const string& prompt, const string& error_prompt
        )
{
    bool done = false;
    while (done == false) // until valid input is given
    {
        input_prot(input, prompt, error_prompt);
        for (vector<char>::size_type pos = 0; pos < list.size(); pos++)
        {
            if (input == list[pos]) // if found in list, search is done
            {
                done = true;
            }
        }
        if (!done) // not found in list
        {
            cerr << error_prompt << endl;
        }


    }
}

//******************************************
// Inputs string to vector

void list_input_char(const string& input, vector<char>& list)
{
    for (string::size_type pos = 0; pos < input.length(); pos++)
    {
        list.push_back(input[pos]);
    }
}
