/******************************************************************************

2. Opening File Streams

*******************************************************************************/

/*

Input Files:

To begin, we must acknowledge that 'ios::nocreate' is no longer part of the C++ 
standard library. By doing this, C++ is NOT able to create empty files whenever 
a requested input file does not exist.

Output Files:

Now, we must recall that 'ios::noreplace' is no longer part of the C++ standard
library. Despite this, overwriting is still the default behavior when dealing 
with output files. However, to avoid this, you must open the file for input to
check its existence. Then, as you close the input connection, open the file as
either 'ios_base::out' (this occurs by default) OR 'ios_base::app' (for 
appending). Either of these methods work, depending on the user's preference.

Either Input or Output:

When dealing with either input files or output files, DO NOT forget to close the
input connection, even if the program failed to open a file properly. Not 
closing the input connection will result in using up the system's resources, 
which is obviously not an ideal situation.

In addition, when working with very strict compilers, you must clear all of the
error flags (after you close the input connection) to ensure everything is set
up properly.

Here is some pseudocode when working with input and output files:


Input File:

    prompt and read name
    open (no mode required -- if your library is compliant)
    while (!file)
    {
        close the file
        clear the flags
        print error message
        prompt and read name
        open (no mode required -- if your library is compliant)
    }

Output File:

    do
    {
        open_tried <-- false
        prompt and read name
        open for input (compliance determines if you need a mode flag)
        if (!infile)
        {
            no problems -- open for output (no mode flags needed at all)
            open_tried <-- true
        }
        else
        {
            ask user for overwrite or append (or choose different name?)
            if (overwrite)
            {
                open for output (no mode flags needed at all)
                open_tried <-- true
            }
            else if (append)
            {
                open for append (no other mode flags needed)
                open_tried <-- true
            }
            if ((!new_name) && (!file))
            {
                close file
                clear file
            }
        }
        close infile connection
        clear infile's flags
    } while (!open_tried || !file);

*/

/*

STREAM OPERATORS:
    - Insertion Operator '<<'(As seen with cout << var)
    - Extraction Operator '>>' (As seen with cin >> var)

*/

//STREAM DECLARATIONS:

//#include <fstream>

//using namespace std;

//int main()
//{
    //ifstream fin;  // streams data FROM a file
    //ofstream fout; // streams data TO a file
    
    /* 
    
    'ifstream' is short for 'input file stream' 
    'ofstream' is short for 'output file stream'
    
    */
    
    //ifstream fin("input.dat"); //streams data FROM a file
    
    /* 
    
    This line of code above connects this stream to an existing data file in the
    same directory. 
    
    */
    
    //ofstream fout("output.dat"); //streams data TO a file
    
    /* 
    
    This line of code above creates a text file in the same directory. 
    
    Now, this isn't the best way to do things. Another way to do this is to use
    the "open" function.
    
    */
//}

//OPENING A FILE W/ C-STRINGS:

//#include <iostream>
//#include <fstream>

//using namespace std;

//int main()
//{
    //ifstream fin;
    //ofstream fout;
    
    //fin.open("input.dat");     // !may not connect!
    //fout.open("output.dat");
    
    /*
    
    This is a member function of the class of objects to which "fin" and "fout"
    belong (ifstream, ofstream). So, 'open' is a member function of those types.
    What you're asking C++ to do is to connect this stream, "fin", to the 
    existing file "input.dat". 
    
    The problem here, thought, is that it might not connect. The reason for why
    they might not connect can be plenty of things. The file might not exist, 
    you might have misspelled something, it could be the wrong directory, and 
    more potential possibilities. So, a better way to do this is to do the 
    following: 
    
    */
    
    //char file[20];
    //ifstream fin;
    
    //do
    //{
        //fin.clear(); // clears the fail bit - allows retry
        //cout << "Enter the name of the file to connect to";
        //cin.getline(file, 20);
        //file.open(file);
    //} while(!fin);
    
    /*
    
    As seen from the above sample of code, you could create a character array 
    called "file" to jump into a loop.
    
    This loop begins by clearing the 'fail' bit and allowing the user a retry.
    Then, the rest of the loop, of course, allows you to input the file name, 
    and the program continues to run as expected. 
    
    Now, if we refer back to line 143, we used double quotes around 'input.dat'.
    This was expressed as:
    
    "input.dat"
    
    This implies that the parameter for the 'open' function is a C-string OR a 
    NULL terminated character.
    
    If the input does not equal 'fin', the 'while' loop catches this and sends
    the user back to the beginning of the 'do'. And if the the input actually
    equals 'fin', the program exists that loop, and the program continues to 
    run as expected. 
    
    */
//}

//OPENING A FILE W/ STD::STRINGS:

//#include <iostream>
//#include <fstream>
//#include <strings>

//using namespace std;

//int main()
//{
    //string file;
    //ifstream fin;
    
    //do
    //{
        //fin.clear();
        //cout << "Enter the name of the file to connect to";
        //cin >> file;
        //file.open(file.c_str());
        
    //} while(!fin);
//}

//READING A FILE

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string file;
    ifstream fin;
    
    do
    {
        fin.clear();
        cout << "Enter the name of the file to connect to";
        cin >> file;
        file.open(file.c_str());
        
    } while(!fin);
    
    fin >> num;
    fin >> num;
    fin >> num;
    fin >> num;
    
}
*/

//CLOSING A FILE: 

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string file;
    ifstream fin;
    
    do
    {
        fin.clear();
        cout << "Enter the name of the file to connect to";
        cin >> file;
        file.open(file.c_str());
        
    } while(!fin);
    
    fin >> num;
    fin >> num;
    fin >> num;
    fin >> num;
    
    fin.close();
    
}
*/














//for more space
