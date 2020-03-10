/******************************************************************************

6. Dynamic Members of a Class

*******************************************************************************/

/*

Objects are no different from simple data types. For example, consider the
following code where we are going to use an array of objects to clarify the 
concept:

*/

#include <iostream>

using namespace std;

class Box
{
    public:
        Box() //constructor
        /*
        We know that the constructor is simply an input function, whose name is
        the same name as the class name, and it should be defined under the 
        public section of the class. Also, whenever an object needs to be 
        defined under that class, the constructor will be executed by default. 
        */
        {
            cout << "Constructor called!" << endl;
        }
        ~Box() //destructor
        /* 
        A destructor is usually used to deallocate memory (and do other 
        cleanup) for a class object and its class members when the object is 
        destroyed. A destructor is called for a class object when that object 
        passes out of scope or is explicitly deleted.
        
        The destructor function must have the same name as the class name. 
        Similar to a constructor, a destructor must NOT have any return types, 
        specific positions, or inputs arguments.
        
        In this case, we have our destructor here. The destructor must always
        be defined under the "public" section of the class. In addition, the
        function name of the destructor must always begin with the '~' sign.
        Apparently, the '~' sign is called a 'tilde'.
        
        To reiterate, the destructor will be executed whenever an object needs
        to release its allocate space. 
        */
        {
            cout << "Destructor called!" << endl;
        }
};

int main()
{
    Box* myBoxArray = new Box[4]; //delete array
    /* 
    With the line of code above, we will define a pointer variable. The
    pointer variable in this case is 'myBoxArray', and it is getting 
    initialized with 4 object locations, and within those locations, they 
    contain 'Box' objects, and its starting address will begin with the 
    'myBoxArray' variable.
    
    Whenever this line of code is executed, for each and every location within 
    the array, memory allocation will take place for each respective object 
    inside the array. This is why the constructor will also be executed for
    every object location that is found within the array (which, in this 
    particular example, will be 4 times). 
    */ 
    delete [ ] myBoxArray; //Delete array
    /*
    Later, we can delete the entire array, and when the array is being 
    deleted, the respective destructor will be called. Since there are 4 
    elements inside the array, the destructor will be called 4 times as a 
    result.
    
    As the entire array is being deleted, each and every object within the array
    will release its allocated memory space. As each object within the array is
    being deleted and is releasing its allocated memory space, the destructor 
    will be called, by default, as many times as there are objects inside the 
    array (which, in this particular example, will be 4 times). 
    */
    return 0;
}







//for more space
