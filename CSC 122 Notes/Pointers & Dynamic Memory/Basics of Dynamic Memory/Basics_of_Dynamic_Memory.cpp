/******************************************************************************

4. Basics of Dynamic Memory

*******************************************************************************/

//new <type>

//new int; //space becomes allocated in the heap (see attached PDF for more info)


/*

Let's say that the 'int' above was allocated at the address '500'.
In terms of the value that exists here, we're not exactly sure what is contained
here at this given point in time, so we will say that the value is '?' for now.

          HEAP
    __________________
    |                |
    |                |
    |      500       |
    |   _________    |
    |   |       |    |
    |   |   ?   |    |
    |   |_______|    |
    |                |
    |________________|

Now, let's build a mechanism to reference the 'int' value from above.
    
*/

//int* p = new int;
	
/*

It turns out, not only does the 'new' operation actually allocate space for an
'int' out in the heap, but it also returns the address of wherever the 'int' is
located in. So from the example above, the address '500' would be returned. 

So, we know that with a pointer, we can actually hold an address. (Let's recall
that a pointer is simply a data type that holds an address for a particular 
thing). So we can declare an 'int' pointer as we do above on the left hand side
of the assignment statement. We have:

// int (pointer) p <--- we are declaring a pointer of type 'int', and it is 
                        able to hold the address '500'

So the pointer p actually exists out on the stack. A visual representation of
the stack can be seen below: 

            STACK
    _____________________
    |                   |
    |                   |
    |                   |
    |    ___________    |
    |    |         |    |
    |  p |   500   |    | //the pointer p is able to hold the address '500'
    |    |_________|    |
    |                   |
    |___________________|

So now, we can imagine that p is referring to the 'int' out in the heap.

So now that we have this pointer p that is able to reference the 'int' element
out in the heap, we actually manipulate what this 'int' element holds. So on
this next line of code:

*/

//*p = 5;

/* Here we have dereference of the pointer p on the left hand side of the 
assignment statement. This just simply gets us to the value of the 'int' that is
out in the heap, and it allows us to assign a value to it. In this particular
example, we are assigning it the value '5'. So we can update our visual 
representation of the heap to look like: 

          HEAP
    __________________
    |                |
    |                |
    |      500       |
    |   _________    |
    |   |       |    |
    |   |   5   |    |
    |   |_______|    |
    |                |
    |________________|
    
    
So now that we are familiar with the operator 'new', and it allows us to create 
things out in the heap, let's create a 'new int' out in the heap, and this time
we are going to initialize it to have the value '10'. 

*/

//p = new int(10);

/*

So we can further visualize the heap to look like:

          HEAP
    __________________
    |                |
    |                |
    |      700       |
    |   _________    |
    |   |       |    |
    |   |   10  |    |
    |   |_______|    |
    |                |
    |                |
    |      500       |
    |   _________    |
    |   |       |    |
    |   |   5   |    |
    |   |_______|    |
    |                |
    |________________|
    
We can see on the left hand side of the assignment operator that we've just 
re-assigned our pointer p to point to the information on the right hand side of
the assignment operator. Again, the new operator will return the address, so it 
will simply return '700'. And now, we must update where 'p' is pointing to, 
which will now be the address '700', and it is now referencing the 'int' value 
'10' out in the heap.

What we can then notice from here is that we still have our other 'int' with the
value '5' that is still out in the heap. This particular 'int' here is no longer
accessible. So anytime we've created/allocated something out in the heap that we 
can no longer reference/get to, this is what we call garbage. Garbage is a bad
thing. Especially if we're working with larger programs where we're allocating
a lot of stuff out in the heap and, in turn, creating a lot of garbage, maybe
even over and over again by some function call (or whatever the case may be).
We may potentially run out of heap space, and whenever we run out of heap space
and try to invoke the new operator and continue to create something out in the 
heap, it can (and most likely will) crash our program. What we see in the visual
example above with the value '5' and the memory location '500' is now garbage.
As you might expect, we want to create as little garbage as possible. So now, we
will go about how we can re-allocate memory so we can avoid creating garbage out
in the heap.

Now let's reorganize our code:

*/

int* p = new int; //line 34
*p = 5;           //line 73
delete p;         //NEW LINE
p = new int(10);  //line 100

/*

Before we reach line 154, we must de-allocate the garbage created as we move on
from value '5'/memory location '500'. We go about this by using the line from
line 153 "delete p". This deletes what p is pointing to on the heap. It doesn't
actually delete a pointer p, but rather it stays there on the stack until the 
function this particular code is currently in actually terminates that point in 
time that p would be removed off the stack along with any other local variables
that it might have. So the 'delete' operation deletes whatever it is pointing 
to, so it removes the value '5' and now this area of memory is now freed up.
Now, 'p' is still pointing to the address location '500', but it is no longer a
valid location in memory. So we wouldn't want to make use of 'p' at this point 
in time (i.e. dereferencing it, assigning a value to it, etc.). This is what we
call a "dangling pointer". A dangling pointer is just simply a pointer that no
longer points to something valid out on the heap. But this is fine because we 
are about to re-assign our pointer p to our 'int' value that we created out on
the heap. 

So to further visualize this, we go from this:

            STACK
    _____________________
    |                   |
    |                   |
    |                   |
    |    ___________    |
    |    |         |    |
    |  p |   500   |    |
    |    |_________|    |
    |                   |
    |___________________|

          HEAP
    __________________
    |                |
    |                |
    |      500       |
    |   _________    |
    |   |       |    |
    |   |   5   |    |
    |   |_______|    |
    |                |
    |________________|
    

To this:

            STACK
    _____________________
    |                   |
    |                   |
    |                   |
    |    ___________    |
    |    |         |    |
    |  p |   700   |    | //now pointing to the address '700' and it's able to
    |    |_________|    | //refer to the value '10'
    |                   |
    |___________________|

          HEAP
    ___________________
    |                 |
    |                 |
    |      700        |
    |   __________    |
    |   |        |    |
    |   |   10   |    |
    |   |________|    |
    |                 |
    |      500        | //this memory location is no longer valid
    |                 |
    |_________________|

So whenever we do a re-assignment, make sure to re-assign the pointer from the
old thing out on the heap to the new thing out on the heap. 

*/

//int* p = new int;
//*p = 5;
//delete p;
//p = NULL // p = 0;      //NEW LINE

/*

Also, if you're doing a 'delete' operation on a pointer where you're freeing up
heap space, and if you don't have something for the pointer p to be erased. Then,
instead of keeping your pointer as a dangling pointer, assign the pointer p to 
NULL. You can assign it to " = NULL" or " = 0". NULL is actually just a macro to
zero. This line just simply indicates that the pointer is not referencing
anything. In this particular case here, the 'delete' operation will free up the
memory out on the heap. Then the 'p = NULL' will allow the program to get rid of
the dangling pointer and it p simply refers to 0 in the stack. If we use the 
pointer p here, it will refer to NULL (or zero). This is good programming 
practice.

In addition to all of this, there is actually another way that we can create 
garbage. This is a more commonly used way to create garbage.

*/

void x()
{
    int* p = new int; //creating a 'new int' out onto the heap
    //some other code
}

/*

                STACK
        _____________________
        |                   |
        |                   |
        |                   |
        |    ___________    |
        |    |         |    |
   x    |  p |   500   |    | //references the address 500 in the heap
        |    |_________|    |
        |    ___________    |
        |    |         |    |
   main |    |   x();  |    |  //main calls the function x
        |    |_________|    | 
        |                   |
        |___________________|

               HEAP
        ___________________
        |                 |
        |                 |
        |      500        |
        |   __________    |
        |   |        |    |
        |   |   ?    |    |
        |   |________|    |
        |                 |
        |                 | 
        |                 |
        |_________________|

The issue with the code above is that if we don't use a delete operation inside
this particular function we're using up above, then we're going to end up having
this memory stored out onto the heap. When we get rid of 'x', we are left with
the following

                STACK
        _____________________
        |                   |
        |                   |
        |    ___________    |
        |    |         |    |
   main |    |   x();  |    |  //main calls the function x
        |    |_________|    | 
        |                   |
        |___________________|

               HEAP
        ___________________
        |                 |
        |                 |
        |      500        |
        |   __________    |
        |   |        |    | //clearly, we still have our 'int' out on the heap
        |   |   ?    |    | //and nobody/nothing can reference it, so we find
        |   |________|    | //that we have created garbage here
        |                 |
        |                 | 
        |                 |
        |_________________|

In summary:
    - 'new' ---> allocates space dynamically on the heap (free store)
            ---> returns the address of the allocated memory
    - We use 'pointers' to reference the memory allocated on the heap
    - 'delete' ---> used to deallocate memory that is allocated on the heap
    - 'garbage' ---> what is created when we can no longer access previously
                     allocated memory on the heap
    - 'dangling pointer' ---> a pointer that no longer points to something valid
                              on the heap

*/
	
	
	
//for more space
