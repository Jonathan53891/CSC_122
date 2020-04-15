#include <iostream>
#include <string>
#include <climits>
#include "frame.h"
#include <fstream>
using namespace std;

const string divider = string(60, '-') + '\n';

const string menu = // Menu
"Enter (separated by space or newline):\n"
"* Framing character\n"
"* Style (choices below)\n"
"    0) Use character\n"
"    1) Single line frame\n"
"    2) Single line frame (shaded)\n"
"    3) Double line frame\n"
"    4) Double line frame (shaded)\n"
"* (R)ight, (L)eft or (C)enter justified\n";

bool true_or_false(const string inputs);

int main()
{
    bool done = false;
    bool loaded = false;
    string config = "config.txt";
    cout << "Attempting to load config.txt." << endl;
    ifstream conf_in;
    conf_in.open(config.c_str());
    if (conf_in)
    {
        cout << "Loaded config file" << endl;
    }
    else
    {
        cout << "No config file found" << endl;
    }
    ifstream input;
    ofstream output;
    string filename;
    while (!done)
    {
        cout << divider;
        Frame f;
        // User chose to read from file
        if (true_or_false("Read phrase from file? Y/N: "))
        {
            
            cout  << "What is the name of the input file?  ";
            getline(cin, filename);
            input.open(filename.c_str());
            while (!input) // open failed
            {
                input.close();
                input.clear();
                cout << divider << "File does not exist.\nEnter file name: ";
                getline(cin, filename);
                input.open(filename.c_str());
            }
            cout << "'" << filename << "' selected as input file." << endl;
            input >> f;
            if (conf_in)
            {
                if (true_or_false("Use initial config file? (Y/N): "))
                {
                    f.input_config(conf_in);
                }
                else
                {
                    cout << menu;
                    f.input_config(cin);
                    if (true_or_false("Save config file? (Y/N): "))
                    {
                        if (conf_in)
                        {
                            conf_in.close();
                            ofstream conf_out;
                            conf_out.open(config.c_str());
                            f.output_config(conf_out);
                            conf_out.close();
                            conf_in.open(config.c_str());
                        }
                        else
                        {
                            ofstream conf_out;
                            conf_out.open(config.c_str());
                            f.output_config(conf_out);
                            conf_out.close();
                        }
                    }
                }
            }
            else
            {
                cout << menu;
                f.input_config(cin);
                if (true_or_false("Save config file? (Y/N): "))
                {
                    if (conf_in)
                    {
                        conf_in.close();
                        ofstream conf_out;
                        conf_out.open(config.c_str());
                        f.output_config(conf_out);
                        conf_out.close();
                        conf_in.open(config.c_str());
                    }
                    else
                    {
                        ofstream conf_out;
                        conf_out.open(config.c_str());
                        f.output_config(conf_out);
                        conf_out.close();
                    }
                }
            }

            if (true_or_false("Output frame to file (Y/N): "))
            {
                cout << divider << "Enter a new output file name:  ";
                getline(cin, filename);
                output.open(filename.c_str());
                cout << "'" << filename << "' selected as output file." << endl;
                output << f;
                output.close();
            }
            else
            {
                cout << f << endl;
            }   
            input.close();
        }
        // User chose to read from keyboard
        else 
        {
            cout << "Input phrase in quotes (\"\"): ";
            cin >> f; // input
            if (conf_in)
            {
                if (true_or_false("Use initial config file? (Y/N): "))
                {
                    f.input_config(conf_in);
                }
                else
                {
                    cout << menu;
                    f.input_config(cin);
                    if (true_or_false("Save config file? (Y/N): "))
                    {
                        if (conf_in)
                        {
                            conf_in.close();
                            ofstream conf_out;
                            conf_out.open(config.c_str());
                            f.output_config(conf_out);
                            conf_out.close();
                            conf_in.open(config.c_str());
                        }
                        else
                        {
                            ofstream conf_out;
                            conf_out.open(config.c_str());
                            f.output_config(conf_out);
                            conf_out.close();
                        }
                    }
                }
            }
            if (true_or_false("Output frame to file (Y/N): "))
            {
                cout << divider << "Enter a new output file name:  ";
                getline(cin, filename);
                output.open(filename.c_str());
                cout << "'" << filename << "' selected as output file." << endl;
                output << f;
                output.close();
            }
            else
            {
                cout << f << endl;
            }

        }
        done = true_or_false("Exit? Y/N: "); // Asks to exit
    }
    conf_in.close();
    return 0;
}

//returns true when user enters 'Y' or 'y', false for 'N' or 'n'
bool true_or_false(const string prompt)
{
    bool valid_input = false;
    char input;
    bool choice;
    while (!valid_input)
    {
        cout << prompt;
        cin >> input;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        switch (input)
        {
        case 'Y': case 'y':
        {
            choice = true;
            valid_input = true;
        }
        break;
        case 'N': case 'n':
        {
            choice = false;
            valid_input = true;
        }
        break;
        default:
        {
            cout << "Invalid input.\n";
        }
        }
    }
    return choice;
}
