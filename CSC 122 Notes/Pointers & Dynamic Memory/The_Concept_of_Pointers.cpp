/******************************************************************************

1. The Concept of Pointers

*******************************************************************************/
/*

A pointer is simply a data type that "points" to another value stored in memory.

For instance, let's refer to the following chart:
    ________________________________
    |        |         |           |
    |  Name  |  Value  |  Address  |
    |________|_________|___________|
    |        |         |           |
    |   p    |   0003  |    0000   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0001   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0002   |
    |________|_________|___________|
    |        |         |           |
    |   x    |    25   |    0003   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0004   |
    |________|_________|___________|
    
Let's assume that "x" is an 'int' variable, and "p" is a 'pointer' variable.
More specifically, we can say that "p" is an 'integer pointer', meaning that
it is capable of holding memory locations (or "addresses", here).
    
Here, p has the value 0003, and it is able to reference the memory location, 
or address, 0003. Since we're able to reach this particular memory location,
we also have the ability to access the value that is stored at that 
particular memory location. 
    
Syntax for declaring a pointer:
    - int* p; //the type is 'int', the name is 'p'
    - int *p;
    - string* q;
    
Common pointer operations:
    - & ---> address of operator
    - * ---> contents of operator
    
Now, let's return to the table that we started out with previously:

int x = 25;
int* p = &x;
    ________________________________
    |        |         |           |
    |  Name  |  Value  |  Address  |
    |________|_________|___________|
    |        |         |           |
    |   p    |   0003  |    0000   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0001   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0002   |
    |________|_________|___________|
    |        |         |           |
    |   x    |    25   |    0003   |
    |________|_________|___________|
    |        |         |           |
    |        |         |    0004   |
    |________|_________|___________|
 
If we use this 'cout' statement below here:

cout << p << endl;

The program will output:

0003


The contents of operator (or the dereference operator) allows us to get the
value stored at the address held by the pointer.

If we use this 'cout' statement below here:

cout << *p << endl;

The program will output:

25

Now, let's discuss how to dereference the pointer p/having it be an alias of x.
We want them to be the same thing. Consider the lines of code below:

x = x + 5; //x is on the left and right side, but they have 2 different meanings
           
           //On the right hand side of the assignment statement, we're saying 
           //to get the value that is stored at this particular memory location 
           //that is associated with 'x'. So in this example, 'x' on the right 
           //hand side gets '25'. So the right hand side becomes '25 + 5'
           
           //On the left hand side of the assignment statement, 'x' means that 
           //we want to store the result of the right hand side at the memory 
           //location specified by 'x'. Also '25 + 5' == '30'. So the value of 
           //'30' will be stored at that particular memory location designated
           //by 'x'.

x = *p + 5;
           //In this example here, we are still continuing the process of
           //dereferencing *p. So instead of getting the address '0003', we
           //would ideally end up with the contents at that particular address,
           //which in this case would be '30'. So we get the value of '30' and
           //add it to '+ 5', and store it back into the variable location that
           //was previously specified, 'x'. So the value 'x' will be updated to 
           //'35'.

*p = *p + 5;
           //In this last example, we have the dereferencing of pointer p on
           //both sides of the assignment statement. Again, we are deferencing 
           //the pointer p on the right hand side. Dereferencing the pointer p
           //would simply get the value that has already been stored, '35'. But
           //now, as we dereference the pointer p that is on the left hand side, 
           //it allows us to store a value at the designated location, which, 
           //to reiterate, assigns the value to x. The same location that 
           //started out as '25', moved to '30', and is currently '35'. So here,
           //we have the value '35' and add it to '+ 5', which turns it into the
           //value '40', and the value '40' gets stored at that particular 
           //memory location. So we can see that dereferencing the pointer p
           //on the right hand side serves the exact same purpose as the
           //variable 'x'. They (now) have the same meaning. 


Lastly, consider the following line of code/print statement below:

cout << &*p << endl;

Using the information we determined from the above examples, we can say that
the dereferencing of 'p' here is essentially the same thing as saying the 
variable 'x'. If we are able to get the address of 'x', that would just simply 
mean the value of '0003'. We can also think of this address of operator 
cancelling out the '*' operator. So any time we see these two things as pairs, 
we can think of them simply cancelling each other out. So fundamentally, the 
print statement will essentially act like:

cout << p << endl;

Which ultimately prints out:

0003

How pointers are ACTUALLY used:
    - Pointers refer to new memory that is reserved during program execution.
    - Pointers refer and share large data structures without making a copy of
    the structures themselves
    - Pointers are used to specify relationships among data (i.e. linked lists,
    trees, graphs, etc.)


*/

#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}





//for more space
