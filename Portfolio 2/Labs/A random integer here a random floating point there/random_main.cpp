#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int random(int limit)
{
    //generates random integer within limit and returns it.
    int temp;
    while(true)
    {
        temp = rand(); //generating random integer.
        if(temp <= limit)
            return temp;
    }
}

void whole()
{
    int i, limit, nos;
    char fname[30];
    ofstream out;
    cout<<"\nHow many values you want to generate: ";
    cin>>nos;
    cout<<"\nWhat will be the largest no. generated: ";
    cin>>limit;
    cin.ignore();//To clear buffer to read strings properly.
    cout<<"\nEnter file name to write nos.: ";
    cin>>fname;
    cin.ignore();
    out.open(fname);
    for(i = 1; i <= nos; i++)
        out<<random(limit)<<endl;//Writing random integers into file.
    out.close();
    cout<<"\nFile created.\n";
}

void decimal()
{
    int i, nos;
    float limit;
    char fname[30];
    ofstream out;
    cout<<"\nHow many values you want to generate: ";
    cin>>nos;
    cout<<"\nWhat will be the largest no. generated: ";
    cin>>limit;
    cin.ignore();
    cout<<"\nEnter file name to write nos.: ";
    cin>>fname;
    cin.ignore();
    out.open(fname);
    for(i = 0; i <= nos; i++)
    {
        out<<(float)random(limit * 50) / 50.0<<endl; //writing float decimals into file.
    }
    out.close();
    cout<<"\nFile created.\n";
}

void character()
{
    int i, nos, limit = 127;//127 is the highest ascii value
    char fname[30];
    ofstream out;
    cout<<"\nHow many values you want to generate: ";
    cin>>nos;
    cin.ignore();
    cout<<"\nEnter file name to write characters: ";
    cin>>fname;
    cin.ignore();
    out.open(fname);
    for(i = 0; i <= nos; i++)
    {
        out<<(char)(random(limit))<<endl;//Generating integers and converting them to characters to write into file.
    }
    out.close();
    cout<<"\nFile created.\n";
}

void names()
{
    int nos, i, n, j, k, nnos;
    char gname[30], fname[30], output[30];
    string name;
    string gnames[1000], fnames[1000], mnames[1000];
    cout<<"\nName of given names file: ";
    cin>>gname;
    cin.ignore();
    cout<<"\nName of family names file: ";
    cin>>fname;
    cin.ignore();
    cout<<"\nName of output file: ";
    cin>>output;
    cin.ignore();
    cout<<"\nHow many names to create: ";
    cin>>nos;
    ifstream gin, fin;
    ofstream out;
    gin.open(gname);
    fin.open(fname);
    i = 0;
    while(getline(gin, name))//Reading line by line from file
    {
        gnames[i] = mnames[i] = name;//mnames stores both gnames and fnames
        i++;
    }
    k = i;
    j = 0;
    while(getline(fin, name))
    {
        fnames[j++] = mnames[i++] = name;
    }
    gin.close();
    fin.close();
    out.open(output);
    while(true){
    cout<<"\nHow many names each person should have (1/2/3): ";
    cin>>nnos;
    //creating names according to users choice
    if(nnos == 1)
    {
        for(n = 1; n <= nos; n++)
            //gnames indices are selected by random function within gnames limit
            out<<gnames[random(k - 1)]<<endl;
        break;
    }
    else if(nnos == 2)
    {
        for(n = 1; n <= nos; n++)
            out<<gnames[random(k - 1)]<<" "<<fnames[random(j -1)]<<endl;
        break;
    }
    else if(nnos == 3)
    {
        for(n = 1; n <= nos; n++)
            out<<gnames[random(k - 1)]<<" "<<mnames[random(i - 1)]<<" "<<fnames[random(j -1)]<<endl;
        break;
    }
    else
        cout<<"\nInvalid choice. Try again.\n";
    }
    out.close();
    cout<<"\nFile created.\n";
}

int main()
{
    time_t ti;
    //Initializing random no. generator
    srand((unsigned)time(&ti));
    char ch; //To read user choice
    while(true)
    {
        cout<<"\n1. create random Whole number data file.\n";
        cout<<"2. create random Decimal number data file.\n";
        cout<<"3. create random Character data file.\n";
        cout<<"4. create a random name data file.\n";
        cout<<"5. Quit program.\n";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cin.ignore();
        if(ch == '1' || ch == 'W' || ch == 'w')
        {
            whole();
        }
        else if(ch == '2' || ch == 'D' || ch == 'd')
        {
            decimal();
        }
        else if(ch == '3' || ch == 'C' || ch == 'c')
        {
            character();
        }
        else if(ch == '4')
        {
            names();
        }
        else if(ch == '5' || ch == 'Q' || ch == 'q')
        {
            cout<<"\nThank you for using.\n";
            return 0;
        }
        else
            cout<<"\nInvalid choice. Try again.\n";
    }
}
