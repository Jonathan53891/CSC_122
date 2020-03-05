#include <vector>
#include <iostream>
#include <limits>

using namespace std;

inline void swap(double & a, double & b)
{
    double c = a;
    a = b;
    b = c;
    return;
}

vector<double>::size_type
largest(const vector<double> & vec, vector<double>::size_type from = 0);

void good_select(vector<double> & vec);

int main(void)
{
    vector <double> data;
    double x;

    cout << "Enter your numbers:  ";
    cin >> x;
    while (!cin.fail())
    {
        data.push_back(x);
        cin >> x;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nYou entered:  { ";
    for (vector<double>::size_type c = 0; c != data.size()-1; c++)
    {
        cout << data[c] << ", ";
    }
    cout << data[data.size()-1] << " }\n";

    good_select(data);

    cout << "\nNow sorted it is:  { ";
    for (vector<double>::size_type c = 0; c != data.size()-1; c++)
    {
        cout << data[c] << ", ";
    }
    cout << data[data.size()-1] << " }\n";

    return 0;
}

vector<double>::size_type largest(const vector<double> & vec,
                                  vector<double>::size_type from)
{
    vector<double>::size_type max = from;
    for (vector<double>::size_type at = from+1;
         at < vec.size(); ++at)
    {
        if ( vec[at] > vec[max] )
        {
            max = at;
        }
    }
    return max;
}

void good_select(vector<double> & vec)
{
    vector<double>::size_type max = largest(vec);
    for (vector<double>::size_type cur = 0; cur+1 != vec.size(); ++cur)
    {
        if ( max != cur )
        {
            swap( vec[cur], vec[max] );
        }
        max = largest(vec, cur+1);
    }
    return;
}
