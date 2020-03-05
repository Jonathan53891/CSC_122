#include <iostream>
#include <string>
#include "input_prot.h"
#include <vector>

using namespace std;

int main() // Driver function
{
    // Initializing prompts
    const string error_prompt = "Invalid input.";

    const string menu =
            "Pick a choice: \n\n"
            "1: Long input Protection \n"
            "2: Double input Protection \n"
            "3: Char input Protection \n"
            "4: Long list input Protection \n"
            "5: Double list input Protection \n"
            "6: Char list input Protection \n"
            "7: Quit \n";

    const string sub_menu =
            "Pick a parameter: \n\n"
            "1: No extra parameter \n"
            "2: Minimum \n"
            "3: Maximum \n"
            "4: Minimum and Maximum \n";
    string divider = '\n' + string(60, '-') + '\n';

    // Initializing input variables
    double double_input;
    long long_input;
    char char_input;



    // Initializing choices
    vector<double> double_list;
    double_list.push_back(1.1);
    double_list.push_back(2.2);
    double_list.push_back(3.3);

    vector<long> long_list;
    long_list.push_back(1);
    long_list.push_back(2);
    long_list.push_back(3);

    vector<char> char_list;
    list_input_char ("ABC", char_list);


    // Menu
    cout << "Welcome to the Input Protection Driver \n";
    char choice;
    bool done = false;

    while (!done)
    {
        cout << divider << menu;
        cin >> choice;
        switch (choice)
        {
            case '1': // Long input Protection
            {
                cout << divider << "Your choice: Long input Protection\n";
                cout << sub_menu;
                bool valid = false;
                while (!valid)
                {
                    cin >> choice;
                    switch (choice)
                    {
                        case '1': // No extra parameter
                        {
                            string prompt = "Enter a long: ";
                            input_prot(long_input, prompt, error_prompt);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '2': //  Minimum
                        {
                            string prompt = "Enter a long >7: ";
                            input_prot(long_input, 7, prompt, error_prompt,
                                    false);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '3': // Maximum 
                        {
                            string prompt = "Enter a long <3: ";
                            input_prot(long_input, 3, prompt, error_prompt,
                                    true);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '4':// "4: Minimum and Maximum
                        {
                            string prompt = "Enter a long between 7 and 30: ";
                            input_prot(long_input, 7, 30, prompt, error_prompt);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        default:
                        {
                            cout << error_prompt << endl;
                        }

                    }
                }

            }
                break;
            case '2': //Double input Protection
            {
                cout << divider << "Your choice: Double input Protection\n";
                cout << sub_menu;
                bool valid = false;
                while (!valid)
                {
                    cin >> choice;
                    switch (choice)
                    {
                        case '1': // No extra parameter
                        {
                            string prompt = "Enter a double: ";
                            input_prot(double_input, prompt, error_prompt);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '2': //  Minimum
                        {
                            string prompt = "Enter a double >7.8: ";
                            input_prot(double_input, 7.8, prompt, error_prompt,
                                    false);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '3': // Maximum 
                        {
                            string prompt = "Enter a double <1.1: ";
                            input_prot(double_input, 1.1, prompt, error_prompt,
                                    true);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        case '4':// "4: Minimum and Maximum
                        {
                            string prompt = "Enter a double between "
                                    "-1.1 and 10.5: ";
                            input_prot(double_input, -1.1, 10.5, prompt,
                                    error_prompt);
                            cout << "Valid choice: " << long_input << endl;
                            valid = true;
                        }
                            break;
                        default:
                        {
                            cout << error_prompt << endl;
                        }

                    }
                }
            }
                break;
            case '3': // Char input Protection
            {
                cout << divider << "Your choice: Char input Protection\n";

                string prompt = "Enter a char: ";
                input_prot(char_input, prompt, error_prompt);
                cout << "Valid choice: " << char_input << endl;


            }
                break;
            case '4': //Long list input Protection
            {
                cout << divider << "Your choice: Long list input Protection\n";
                string prompt = "Pick 1, 2 or 3: ";
                list_input_prot(long_input, long_list, prompt, error_prompt);
                cout << "Valid choice: " << long_input << endl;

            }
                break;
            case '5': // Double list input Protection
            {
                cout << divider << "Your choice: Double list input "
                        "Protection\n";
                string prompt = "Pick 1.1, 2.2 or 3.3: ";
                list_input_prot(double_input, double_list, prompt,
                        error_prompt);
                cout << "Valid choice: " << double_input << endl;
            }
                break;
            case '6': // Char list input Protection
            {
                cout << divider << "Your choice: Char list input Protection\n";
                string prompt = "Pick A, B or C: ";
                list_input_prot(char_input, char_list, prompt, error_prompt);
                cout << "Valid choice: " << char_input << endl;
            }
                break;
            case '7':
            {
                done = true;
            }
	    	break;
            default:
            {
                if (!done)
                {
                    cout << error_prompt;
                }

            }

        }
    }


    return 0;

}

