#include <iostream>
#include <fstream>
#include <climits>
#include <string>

using namespace std;

int main(void)
{
    double *pdata = nullptr;
    size_t i, num_data;

    cout << "How many values do you have?  ";
    cin >> num_data;/*
    while (num_data < 0)     // could check fail..?
    {
        cout << "\n\aInvalid size!  Get real!\n\n"
             << "How many values do you have?  ";
        cin >> num_data;
    }*/

    if (num_data == 0)
    {
        cout << "Okay, then...have a nice day!" << endl;
    }
    else
    {
        pdata = new double [num_data+1];  // extra space for sum
        if (pdata != nullptr)
        {
            cout << "Enter values:  ";
            for (i = 0; i < num_data; ++i)
            {
                cin >> pdata[i];
            }

            cout << "Adding values...";
            for (i = 0, pdata[num_data] = 0.0; i < num_data; ++i)
            {
                pdata[num_data] += pdata[i];
            }

            cout << "Sum:  " << pdata[num_data] << endl
                 << "Avg:  " << pdata[num_data]/num_data
                 << endl;
        }
        else
        {
            cout << "\n\aUnable to allocate space for "
                 << num_data << " values!\n\n"
                 << "Please shut down other applications first..."
                 << endl;
        }
        delete [] pdata;
        pdata = nullptr;
    }

    cout << "\n*wave*  See you later!\n" << endl;

    return 0;
}

