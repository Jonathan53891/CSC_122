/******************************************************************************

3. Basics of C-strings

*******************************************************************************/
#include <iostream>
#include <string> // <--- string class

int main()
{    
    /* An example of a C-string can be found below: */
    
    char name[] = "Jonathan"; // c string == array of characters
    
    /* The C-style string uses the brackets like those above because the C-string
    is actually an array of characters. 
    
    This way of making strings works, but there are a lot of limitations that
    come by going about creating strings in this way. For instance, the string's
    size cannot be changed easily. When we assign a literal string, such as 
    "Jonathan" here, the size of the "name" is going to be 8, since there are 8
    characters within the string "Jonathan". The compiler will read the array as:
    
    "Jonathan\0", where '\0' is the null-terminating character.
    
    This means that the amount of memory that the C-string "name" has is limited
    to 8 characters, and we can't assign it another value that is any larger or 
    smaller than the 8 characters that the array is set to be at. 
    
    So if we try printing the following code below:
    */
    
    // name = "JonathanPilafas"
    // OR
    // name = "Jon"
    
    /* We will receive an error message from the compiler saying that "the array
    type 'char[8]' is not attainable", thus proving that we can't simply change 
    the value of a C-string.
    
    However, using the "string" class in C++, we can easily alter the amount of
    characters we want to put into our string using the 'getline()' function. 
    Read the next set of notes to learn more about that.
    */
}
