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

#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}
