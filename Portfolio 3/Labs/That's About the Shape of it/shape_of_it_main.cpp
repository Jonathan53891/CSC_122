#include <iostream>
#include <vector>
#include "shape_of_it_line.h"
#include "shape_of_it_curve.h"
#include "shape_of_it_circle.h"
#include "shape_of_it_rect.h"
#include "shape_of_it_cone.h"
#include "shape_of_it_cube.h"
#include "shape_of_it_sphere.h"
using namespace std;

const string divider = string(60, '-') + '\n';
const string menu =
"Pick a choice:\n"
"1: Create a 1D Shape \n"
"2: Create a 2D Shape \n"
"3: Create a 3D Shape \n"
"4: List all shape names \n"
"5: List all shape names w/ information \n"
"6: Remove shape \n"
"7: Quit \n";

const string shape_choices =
"1: Create a Cube \n"
"2: List all shape names \n"
"3: List all shape names w/ information \n"
"4: Quit \n";

bool true_or_false(const string inputs);

int main()
{
    //Default points for list


    vector<Shape*> shape_list;
    typedef vector<Shape*>::size_type vshsize; // list of shapes

    bool done = false;
    char choice;
    while (!done) // in menu
    {
        cout << divider << menu;
        cin >> choice;
        switch (choice)
        {
        case '1':// add a 1D shape
        {
            bool valid = false;
            while (!valid)
            {
                cout << "What shape would you like to add? " << endl;
                cout << "Line (1) or Curve (2): ";
                char pick_shape;
                cin >> pick_shape;
                cin.ignore();
                cin.clear();

                switch (pick_shape)
                {
                case '1': //add a line
                {
                    //data input
                    string name;
                    Point p1;
                    Point p2;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Point 2?: ";
                    p2.Input();
                    //creates shape and pushes it back
                    Shape * new_Line = new Line(name, p1, p2);
                    shape_list.push_back(new_Line);
                    valid = true;
                }
                break;
                case '2': //add a curve
                {   //data input
                    string name;
                    Point p1;
                    Point p2;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Point 2?: ";
                    p2.Input();
                    vector<Point> point_list;
                    while (true_or_false("Add more points? (Y/N): "))
                    {
                        Point new_point;
                        cout << "Insert point: ";
                        new_point.Input();
                        point_list.push_back(new_point);
                    }
                    //creates shape and pushes it back
                    Shape * new_Curve = new Curve(name, p1, p2, point_list);
                    shape_list.push_back(new_Curve);
                    valid = true;
                }
                break;
                default:
                {
                    cout << "Invalid input." << endl;
                }
                break;
                }
            }
        }
        break;
        case '2':// add a 2D shape
        {
            bool valid = false;
            while (!valid)
            {
                cout << "What shape would you like to add? " << endl;
                cout << "Circle (1) or Rectangle (2): ";
                char pick_shape;
                cin >> pick_shape;
                cin.ignore();
                cin.clear();
                switch (pick_shape)
                {
                case '1': //add a circle
                {
                    // data input
                    string name;
                    Point p1;
                    double radius;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Radius?: ";
                    cin >> radius;
                    //creates shape and pushes it back
                    Shape * new_Circle = new Circle(name, p1, radius);
                    shape_list.push_back(new_Circle);
                    valid = true;
                }
                break;
                case '2': //add a rectangle
                {
                    //data input
                    string name;
                    Point p1;
                    double length;
                    double width;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Length?: ";
                    cin >> length;
                    cout << "Width?: ";
                    cin >> width;
                    //creates shape and pushes it back
                    Shape * new_Rect = new Rect(name, p1, length, width);
                    shape_list.push_back(new_Rect);
                    valid = true;
                }
                break;
                default:
                {
                    cout << "Invalid input." << endl;
                }
                break;
                }
            }
        }
        break;
        case '3':// add a 3D shape
        {

            bool valid = false;
            while (!valid)
            {   //data input
                cout << "What shape would you like to add? " << endl;
                cout << "Sphere(1), Cube(2) or Cone(3): ";
                char pick_shape;
                cin >> pick_shape;
                cin.ignore();
                cin.clear();
                switch (pick_shape)
                {
                case '1': //add a Sphere
                {
                    //data input
                    string name;
                    Point p1;
                    double radius;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Radius?: ";
                    cin >> radius;
                    //creates shape and pushes it back
                    Shape * new_Sphere = new Sphere(name, p1, radius);
                    shape_list.push_back(new_Sphere);
                    valid = true;
                }
                break;
                case '2': //add a Cube
                {   //data input
                    string name;
                    Point p1;
                    double width;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Width?: ";
                    cin >> width;
                    //creates shape and pushes it back
                    Shape * new_Cube = new Cube(name, p1, width);
                    shape_list.push_back(new_Cube);
                    valid = true;
                }
                break;
                case '3': //add a Cone
                {   //data input
                    string name;
                    Point p1;
                    double height;
                    double radius;
                    cout << "Name?: ";
                    getline(cin, name);
                    cout << "Point 1?: ";
                    p1.Input();
                    cout << "Height?: ";
                    cin >> height;
                    cout << "Radius?: ";
                    cin >> radius;
                    Shape * new_Cone = new Cone(name, p1, height, radius);
                    shape_list.push_back(new_Cone);
                    valid = true;
                }
                break;
                default:
                {
                    cout << "Invalid input." << endl;
                }
                break;
                }
            }
        }
        break;
        case '4':  //  list shape names
        {
            if (shape_list.size() == 0) // empty
            {
                cout << "No shapes in list." << endl;
            }
            else
            {
                cout << endl;
                // loop to list shapes
                for (vshsize pos = 0; pos < shape_list.size(); pos++)
                {
                    cout << pos + 1 << ") " << shape_list[pos]->get_name()
                        << endl;
                }
            }

        }
        break;
        case '5': // list shapes w/ info
        {
            if (shape_list.size() == 0) //empty
            {
                cout << "No shapes in list." << endl;
            }
            else
            {
                // loop to list shapes
                for (vshsize pos = 0; pos < shape_list.size(); pos++)
                {
                    shape_list[pos]->print(cout);
                    cout << endl;
                }
            }

        }
        break;
        case '6': //Delete shape
        {

            if (shape_list.size() == 0) // empty
            {
                cout << "No shapes in list." << endl;
            }
            else
            {
                bool valid = false;
                int choice;
                while (!valid)
                {
                    // show choices
                    cout << "Chose shape or option: " << endl
                        << "0: Return to menu" << endl;
                    for (vshsize pos = 0; pos < shape_list.size(); pos++)
                    {
                        cout << pos + 1 << ": " << shape_list[pos]->get_name()
                            << endl;
                    }
                    cin >> (choice);
                    if ((choice < shape_list.size() + 1) && (choice > -1))
                    {
                        if (choice == 0) // go back to menu
                        {
                            valid = true;
                        }
                        else
                        {
                            //delete memory of item and remove from vector
                            cout << shape_list[choice - 1]->get_name()
                                << " deleted." << endl;
                            delete shape_list[(choice - 1)];
                            shape_list.erase(shape_list.begin() + choice - 1);
                            valid = true;


                        }
                    }
                    else
                    {
                        cout << "Invalid choice." << endl;
                    }
                }
            }
        }
        break;
        case '7': // User wants to quit
        {
            done = true;
            //free up memoty
            for (vshsize pos = 0; pos < shape_list.size(); pos++)
            {
                delete shape_list[pos];
            }
        }
        break;
        default:
        {
            cout << "Invalid input." << endl;
        }
        break;

        }
    }

}

//returns true or false based on user input
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
