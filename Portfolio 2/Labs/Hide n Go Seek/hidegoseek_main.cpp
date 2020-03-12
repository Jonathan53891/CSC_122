#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<cstdlib>
//#include<string.h>

using namespace std;

int c=0;

ifstream fin;

int strcmp_ncase(string s1,string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    if(s1==s2)
        return 1;
    else 
        return 0;
}

int main()
{
    cout<<" Welcome to the Name Searching Program\n";
    char fil[100];
    cout<<"Please enter the name your file: ";
    cin>>fil;
    fin.open(fil);
    while(fin.fail())
    {
        cout << "I'm sorry, I could not open '"<<fil<<"'. Please enter another name:" ;
        cin>>fil;
        fin.open(fil);
    }
    
    cout<<"File '"<<fil<<"' opened successfully\n";
    getchar();
    string search;
    cout << "what name would you like to find in the file? ";
    getline(cin,search);
    int flag =0;
    while(!fin.eof())
    {
        string temp;
        c++;
        getline(fin,temp);
        int x= strcmp_ncase(search,temp);
        if(x==1)
        {
            cout<<"'"<<temp<<"' is the "<<c<<"rd name in the file"<<endl;
            flag =1;
        }
    }
    
    if(flag==0)
        cout<<search<< " name not found in the file\n";
    fin.close();
    cout<<"Thank you for using the NSP!\n";
    return 0;
}




//for more space
