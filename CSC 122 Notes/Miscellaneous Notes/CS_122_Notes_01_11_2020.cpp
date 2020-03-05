/******************************************************************************
Inline functions
    - 10 or fewer statements
    - 5 or fewer statements
    - for loop head counts as 3 statements
    
---------- Ex. inline code ----------
inline double sqr(double x)
{
    return x*x
}

A library in C++ consists of two files:
    1. interface file
    2. implementation file
-------------------------------------

Interface files
- Typically contain the prototypes of all functions available in the library.
- Consisting mostly of function heads, the interface file's name is typically ended with '.h' (because of "heads").
- It can also contain constant definitions and typedefinitions.

Implementation files 
- Just begin with #include. We can use the following:
    #include "interfacefile.h"
- It defines the functions protoyped in the interface
- File name is ended with '.cpp'

Interface files are #include'd so many times, people tend to put them in multiple times
- potential warnings/errors about duplicate symbols/definitions could occur
- to fix the previously mentioned issue we use #if pre-processor codes 
        - these are also known as multiple-inclusion protection OR circular-inclusion protection

---------- Ex. #if pre-processor code ----------
    #if ! defined(UNIQUE_SYMBOL_FOR_THIS_LIBRARY_INTERFACE)
    #define UNIQUE_SYMBOL_FOR_THIS_LIBRARY_INTERFACE
    
        // prototype, const, typedef, etc.
    
    #endif
------------------------------------------------



Modern compilers implement something called a pragma.

---------- Ex. #pragma ----------
    #pragma once
---------------------------------

- The use of a pragma can replace the other pre-processor directives


To use a library in another piece of code, you need the following:
    #include "library_name.h"
It's critical to compile the other code file along with the library's implementation file.

---------- Ex. recommended compiling process ----------

    $ CPP other_code lib_name second_lib
    lib_name.cpp...
    other_code.cpp***
    second_lib.cpp...
    
    
    $ ./other_code.out
    ...
-------------------------------------------------------

Potentail Error Messages:
If you see "No main found...simply generating .o files...", then you forogt to list your main program's .cpp file.
If you see any "/tmp/XXXXX.o" followed by "undefined reference to...", you compiled without at least one implementation file.
    - Only when all .cpp files for the program are compiled together can you get an executable (.out)!

When scripting, don't forget to "cat" all of your C++ files:
    - .h files
    - .cpp files
If not, won't get credit for the assignment

Classes vs. Libraries:
- A class is a data type
- A library is a collection of tools that work to solve similar problems

How to define new data types:
- typedef old_name new_name;
- using new_name = old_name;
- (Refer to the following code)

class new_name
{
    
};

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}
