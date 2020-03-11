/******************************************************************************

8. Argument for the 'main' function

*******************************************************************************/

/*

The Main Function:

Version 1 - int main()

Version 2 - int main(int argc, char* argv[])

Microsoft Version - void main()

*/

//Our Original "Hello World" Program
/*
#include <iostream>

using namespace std;

int main() //main function takes no arguments and returns an 'int'
{
    
    cout << "Hello World" << endl;

    return 0; //returns zero to indicate that the program executed successfully
}
*/

/*
Until this point, this is the only version of 'int main()' that we've worked
with -- Version 1.

Now, we will begin working with Version 2.
*/

//int main(int argc, char* argv[]) //takes two arguments and returns an 'int'

/*
The second argument -- argv[] -- is an array of 'char' pointers that point to a 
'char' array of strings.

The first argument -- argc -- is an integer that tells us how many strings were
passed in the array. 'argv[]'.

We should also take a look at another variant of the 'main' function that takes
no arguments and returns nothing. This being:
*/

//void main() //takes no arguments and returns nothing

/*

The version of the 'main' function is supported by Microsoft's compiler. It is 
not in the C++ standard library.

In the program below, we introduce the second variant of the 'main' function. 
This program simply consists of a loop that runs over each of the strings in
the array, and it outputs it to the console window. This program doesn't do
much, but it serves to illustrate how parameters are passed into the 'main'
function. 

*/

/*

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    for(int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
    cin.get();
    return 0;
}

*/

/*

Our last version of the 'main' function can be found below:

*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    using namespace std;
    
    if(argc != 2)
    {
        cout << "Incorrect number of arguments" << endl;
        cin.get();
        return 1;
    }
    
    //Get the filename and open the file
    ifstream qInFile(argv[1]);
    
    if(!qInFile.good())
    {
        cout << "Could not open " << argv[1] << endl;
        cin.get();
        return 1;
    }
    
    //Read the file line by line and output it
    while (!qInFile.eof())
    {
        string qLine;
        getline(qInFile,qLine);
        cout << qLine << endl;
    }
    cout << endl;
    
    qInFile.close();
    cin.get();
    return 0;
}

/*

Generally speaking, we return a non-zero value to indicate an error in execution
and 0 to indicate success.

*/








//for more space
