#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main ()
{
    fstream f1,f2;
    char ch;
    string fl1,fl2;
    cout<<"\nEnter name of the file from which the content will be copied : ";
    cin>>fl1;
    f1.open(fl1.c_str());
    cout<<"\nEnter name of the file where you want to copy : ";
    cin>>fl2;
    f2.open(fl2.c_str());
    
    while (!f1.eof())
    {
        f1.get(ch);
        cout<<ch;
        f2<<ch;
    }
    
    f1.close();
    f2.close();
    return 0;
}
