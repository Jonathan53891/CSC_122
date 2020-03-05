/******************************************************************************

3. Basics of C-strings

*******************************************************************************/
#include <iostream>
#include <string> // <--- string class

//using std::string; //can use this to eliminate the need for constantly 
                     // typing "std::"

int main()
{
    string greeting = "hello";
    
    //cout << greeting[0] << endl; //line we could use if we have "using std::string;"
    std::cout << greeting[0] << std::endl;
}

