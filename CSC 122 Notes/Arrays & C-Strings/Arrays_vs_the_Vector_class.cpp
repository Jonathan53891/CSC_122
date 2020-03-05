/******************************************************************************
2. Arrays vs. the Vector class

*******************************************************************************/

/* The biggest difference between arrays and vectors is whether or not you can
assign them to another variable of the same type. 

For instance, let's create a vector: */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> stuff; //take "stuff" and assign it to another vector
    vector<int> things = stuff;
    
    /* You can do what was written above with vectors and templatized arrays, 
    however, you cannot do this with the standard C-style arrays. 
    
    So when it comes to C-style arrays, it's much harder to work with if you 
    already have some variable that contains data, and you want to put it into 
    an array. You might have to iterate through that collection and assign it 
    one at a time to the array. 
    
    When you're working with vectors and templatized arrays, it's nice and
    simple, since you can simply do a copy by assigning the value to another 
    variable. 
    
    Overall, vectors are easier to use and are much more scalable than arrays.
    when it comes to managing a codebase. Arrays or templatized arrays will
    require a very specific use to become more useful than what functionality
    a vector can already bring to the table. 
    
    In addition, the templatized arrays are typically better than the C-style
    arrays. 
    
    So far, the templatized arrays and vectors can be assigned to other 
    variables of the same type. Another difference between the templatized 
    arrays, vectors, and C-style arrays is that the C-style arrays are passed 
    by pointer. In other words, when you pass an array to a function, it decays
    to a pointer and essentially forgets how large the size of memory reserved
    for that array is. So you usually have to pass an additional size.
    
    The significance of passing by pointer within C-style arrays means that you 
    can modify the array by default inside of the function. Whereas for the 
    templatized arrays and vectors, you pass by value, so it is just a copy of
    and you can't change the variable that is being passed in by default. You 
    have to pass by reference if you want to change the variables within the
    array. 
    
    Both vectors and templatized arrays have a "size" method that you can use 
    to get the size of the array or vector. Whereas for the standard, C-style
    arrays, you either have to have another argument if you're working with 
    functions, or you need to calculate the size using the "sizeof" operator. 
    So if you take the "sizeof" the entire variable and divide it by how large
    each element is (so "sizeof" whatever data type you're working with). Then
    you will ultimately get the size of the array. That is only going to work 
    in the scope where you define that array, though. 
    
    Overall, you have C-style arrays on one side, and templatized arrays and 
    vectors on the other side. The only thing is that when it comes to the 
    templatized array is also statically sized, which gives it one noticeable
    similarity that it shared with the standard, C-style arrays. 
    
    ______________________________________________________________________________
    | key characteristics  | C-style arrays | templatized arrays |    vectors    |
    |______________________|________________|____________________|_______________|
    | static sizing VS.    |                |                    |               |
    | dynamic sizing:      |     static     |       static       |    dynamic    |
    |______________________|________________|____________________|_______________|
    | how they are passed: |    decay to a  |                    |               |
    |                      |    pointer     |   pass by value    | pass by value |
    |______________________|________________|____________________|_______________|
    | how it knows its     | must pass      |                    |               |
    | size:                | around size    | uses ".size()"     | uses ".size()"|
    |______________________|________________|____________________|_______________|
    | can be assigned to   |                |                    |               |
    | different variables? |      NO        |        YES         |      YES      |
    | (Y/N):               |                |                    |               |
    |______________________|________________|____________________|_______________|
    
    */
}



//for space
