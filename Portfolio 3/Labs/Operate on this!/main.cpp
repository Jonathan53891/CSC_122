#include <iostream>
#include "point.h"
using namespace std;

int main()
{
    cout << "Enter point p: ";
    Point p;
    cin >> p;
    cout << "You entered " << p << endl;
    cout << "Enter point q: ";
    Point q;
    cin >> q;
    cout << "You entered " << q << endl;
    cout << "p=q? (0 false, 1 true): " << (p == q) << endl;
    cout << "p!=q? (0 false, 1 true): " << (p != q) << endl;
    cout << "Distance between p and q: " << (p - q) << endl;
    cout << "Midpoint between p and q: " << (p / q) << endl;
    cout << "Press q to quit: ";
    cin.ignore(999, 'q');
    return 0;
}
