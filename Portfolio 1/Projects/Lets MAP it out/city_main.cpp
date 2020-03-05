#include "point.h"
#include "city.h"
#include "city_list.h"
#include "city_input_prot.h"
#include <iostream>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Strings
const string divider = '\n' + string(60, '-') + '\n';
const string prompt = "Select an option: ";
const string error_prompt = "Invalid input.";
const string menu =
        "Pick a choice: \n\n"
        "1: Enter city information \n"
        "2: Calculate distance between two cities \n"
        "3: Print all cities \n"
	"4: Quit \n";

const string valid_choices =
        "1Ee"  // Enter city
        "2Cc"  // Calculate distance
        "3Pp"  // Print cities
        "4Qq"; // Quit program

int main()
{
    cout << "Welcome to the City List Program \n";
    char choice;
    bool done = false;
    vector<char> valid_input_list;
    vector<char> yes_no;
    list_input_char("YyNn", yes_no);
    list_input_char(valid_choices, valid_input_list);
    City_list city_list;

    while (!done)
    {
        cout << divider << menu << endl;
        list_input_prot(choice, valid_input_list, prompt, error_prompt);
        switch (choice)
        {
            case '1': case 'E': case 'e': // User wants to enter a city
            {
                Point location;
                string name;

                cout << divider << "Enter city name: ";
                cin.clear();
                cin.ignore();
                getline(cin, name);
                cout << "Enter coordinates by typing ([x-coordinate],[y-coordinate]): ";
                location.Input();

                City a(location, name);
                bool added = city_list.add_city(a);
                if (added)
                {
                    cout << "'" << name << "' added.";
                }
                else
                {
                    cout << "List is full.\n";
                    list_input_prot(choice, yes_no, "Overwrite a city? Y/N: ",
                            error_prompt);
                    if (choice == 'n' || choice == 'N')
                    {
                        cout << "Canceled - returning to main menu.\n";
                    }
                    else
                    {
                        city_list.list_cities("");
                        long position;
                        input_prot(position, 1, city_list.get_list_length(),
                                "Choose a city to overwrite: ", error_prompt);
                        position--;
                        cout << city_list.get_city(position).get_name()
                                << " overwritten.";
                        city_list.set_city(position, a);
                    }
                }
            }//end of case '1':
                break;
            case '2': case 'C': case 'c': // User wants to calculate distance
            {
                cout << divider;
                if ((city_list.get_list_length()) < 2)
                {
                    cout << "You need at least two cities to calculate"
                            " a distance.\n";
                }
                else if ((city_list.get_list_length()) == 2)
                {
                    cout << "Distance between the two cities in list: ";
                    cout << city_list.get_city(0)
                            .get_distance(city_list.get_city(1));
                }
                else
                {
                    city_list.list_cities("");
                    long pos_1;
                    input_prot(pos_1, 1, city_list.get_list_length(),
                            "Enter the POSITION (not coordinates) of the 1st city ON THE LIST ABOVE that you would like use to find its distance: ", error_prompt);
                    //bool done = false;
                    long pos_2;
                    while (!done)
                    {
                        input_prot(pos_2, 1, city_list.get_list_length()
                                , "Enter the POSITION (not coordinates) of the 2nd city ON THE LIST ABOVE that you would like use to find its distance: ", error_prompt);
                        if (pos_2 == pos_1)
                        {
                            cout << "You cannot select the same position.\n";

                        }
                        else
                        {
                            done = true;
                        }
                    }
                    cout << "Distance: ";
                    cout << (city_list.get_city(pos_1 - 1))
                            .get_distance(city_list.get_city(pos_2 - 1)); // << endl;
                }

            }//end of case '2':
                break;
            case '3': case 'P': case 'p': // User wants to print cities
            {
                cout << divider;
                city_list.list_cities("No cities in list.");
            }//end of case '3':
                break;
	    case '4': case 'Q': case 'q':
            {
                cout << "Goodbye.\n";
                done = true;
            }//end of case '4':
                break;
            default:
            {
                cout << error_prompt;
            }//end of default:
                break;

        }//end of switch (choice)
    }//end of while (!done)
    
    return 0;
    
}//end of int main()
