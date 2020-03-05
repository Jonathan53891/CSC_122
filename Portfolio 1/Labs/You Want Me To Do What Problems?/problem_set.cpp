#include "problem_set.h"
#include <vector>
#include <iostream>

using namespace std;

void Problem_Set::Output() const // Outputs problems to do
{

    cout << "Do problem";
    short OUTPUT_MAX_LENGTH = 70;
    // "count" keeps track of the character width of the output
    short count = 11; // "Do problem" takes up 13 characters
    if (list.size() == 1) // one item in list
    {
        cout << " "<< list[0]  <<" of " << name << "." << endl;
    }
    else // more than one item in list
    {
        cout << "s ";
        count = count + 2;
        for (vector<short>::size_type pos = 0; pos < list.size() - 2; pos++)
        {
            if (count > OUTPUT_MAX_LENGTH) // too big, wraps
            {
                cout << endl;
                count = 0;
            }
            cout << list[pos] << ", ";
            count = count + Num_Length(list[pos]) + 2; // adds to total
        }
        count = count + Num_Length(list.size() - 2); // adds to total
        if (count > OUTPUT_MAX_LENGTH) // too big, wraps
        {
            cout << endl;
            count = 0;
        }
        cout << list[list.size() - 2];
        // counts what is left to print, sees if needs to wrap
        count = count + 10 + Num_Length(list.size() - 1) + name.length();
        if (count > OUTPUT_MAX_LENGTH) // too big, wraps
        {
            cout << endl;
            count = 0;
        }
        cout << " and " << list[list.size() - 1] << " of " << name << "." << 
                endl;
    }


}

void Problem_Set::Input_List(std::string const& prompt)
{
    cout << prompt;
    bool get_first = false;
    char first;

    while (!get_first) // ignores all garbage input until we reach ", ', or 
        // a letter
    {
        cin >> first;
        if (first == '"' || first == '\'' || isalpha(first))
        {
            get_first = true;
        }
    }


    string tmp_name;
    //Procedure for inputting name;

    if (first == '\'') // reads input until ending '
    {
        getline(cin, tmp_name, '\'');
        name = tmp_name;
    }
    else if (first == '\"') // reads input until ending "
    {
        getline(cin, tmp_name, '\"');
        name = tmp_name;
    }
    else // input was a character
    {
        char tmp_letter;
        name = first; // adds first letter to beginning of name;
        while (isalpha(cin.peek())) // while next input in buffer is a letter
        {
            // input the letter and add it to the end of the name
            cin >> tmp_letter;
            name = name + tmp_letter;
        }
    }
    //Procedure for inputting numbers
    char tmp_symbol;
    short tmp_number;
    short tmp_number2;
    cin >> tmp_number;
    list.push_back(tmp_number);
    while (cin.peek() != '\n') // checks until endline
    {
        cin >> tmp_symbol;
        if (tmp_symbol == ',')
        {
            cin >> tmp_number;
            Insert_Sort(tmp_number);
        }
        else if (tmp_symbol == '-')
        {
            cin >> tmp_number2;
            while (tmp_number < (tmp_number2))
            {
                tmp_number++;
                Insert_Sort(tmp_number);

            }

        }
    }


}

void Problem_Set::Insert_Sort(const short& input)
{
    vector<short>::size_type pos = 0;
    bool done = false;
    // if nothing in list, just insert, no need to do any sorting
    if (list.size() == 0)
    {
        list.push_back(input);
        done = true;
    }
    // finds position
    if (!done) // something in list
    {
        bool match = false; // indicates found a match
        while (pos < list.size() && !done)
        {
            if (list[pos] == input)
            {
                done = true;
                match = true;
            }
            else if (list[pos] > input)
            {
                done = true;
            }
            if (!done) // input > list[pos]
            {
                pos++;
            }
        }
        if (!match) // no match
        {
            list.push_back(0); // increases list size by one
            short index = (list.size() - 1);
            // shifts everything from the "found" position to the right to
            // make room
            while (index > pos)
            {

                list[index] = list[index - 1];
                index--;
            }
            list[pos] = input; // puts input in correct position
            done = true;
        }
    }

}

