/******************************************************************************

3. Passing File Streams to Functions

*******************************************************************************/

/*

There is one rule that we have to live by when it comes to passing file streams
to functions. 

    *** When you pass a stream, pass it by reference ***

*/

// Pre: template parameter T must be either ifstream or ofstream type.

template <typename T>

void fileopen (T & filestr, const string promptpart)
{
    const int MAX_TRIES = 5;
    int count = 0;
    string filename;
    cout << "Enter the name of " << promptpart << " file:     ";
    cin >> filename;
    filestr.open(filename.c_str());
    
    while (!filestr)
    {
        filestr.clear(); //may be necessary depending on the platform
        cout << "ERROR: file not connected. Try again..." << endl;
        cout << "Enter the name of " << promptpart << " file:     ";
        cin >> filename;
        filestr.open(filename.c_str());
        count++;
        
        if(count > MAX_TRIES)
        {
            cout << "NOT CONNECTING AFTER " << MAX_TRIES 
                 << " ATTEMPTS...BAILING OUT" << "..." << endl;
            exit(1);
        }
        
    }
    return;
}

/* OPERATOR OVERLOADING:

ostream& operator << (ostream & out, const point & p)
{
    out << "(" << p.m_X << ", " << p.m_Y << ")";
    return out;
}

//example 1
point p1, p2;

cout << p1;
cout << p1 << " " << p2;

//example 2
ofstream fout;

fout << p1;
fout << p1 << " " << p2;

*/













//for more space
