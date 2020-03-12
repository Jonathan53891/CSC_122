/******************************************************************************

1. Old Streams, New Habits

*******************************************************************************/


/*

An I/O operation typically has two steps:
    1) Formatting data
    2) Communicating data to external devices

Formatting data is the responsibility of a 'stream' class.

Communicating data to external devices is done by "stream buffer", which is the
internal module of a stream. 

So if we have the following code:

*/

cout << 34;

/* 

'cout' is responsible for converting '34' into an appropriate format and 
delegating the job of communicating data to its internal module, which is a 
'stream buffer'. 

We can use the following function:

*/

streambuf* pbuf = cout.rdbuf();

/*

to get a pointer to the internal module of the 'stream buffer'. 

So, the 'cout' is responsible for formatting the data, and the 'stream buffer'
is responsible for ultimately transferring data to 'standard out'.

Now if we add in this next line of code:

*/

ostream myCout(pbuf);

/*

We can see that we have created another 'ostream' that has the same 'stream 
buffer' as 'cout'. In other words, 'myCout' has the same transferring channel
as 'cout'.

Now, if we do:

*/

myCout << 34; // 34 to stdout

/*

Then, '34' will be printed out to 'standard out'.

Now, if we want to change the format of 'myCout', consider the following:

*/

myCout.setf(ios::showpos);

/*

The line above will show the positive sign of a number.

*/

myCout.width(20);

/*

The line above will send the width to be 20, and our data will be aligned to
the right.

Now, if we do the following:

*/

myCout << 12 << endl; //                  +12

/*

The line above will print out something like the commented line of code in line
89 above.

Now, if we do the following:

*/

cout << 12 << endl;  // 12

/*

The line of code above will print out something like the commented line of code 
in line 100 above.

This become useful when you want to temporarily change the format to 'standard
out' without changing 'cout', in case someone else is using 'cout', to make the
code more reusable and thus more sustainable.

Now, let's look at another example (on line 115):

*/

ofstream of("MyLog.txt");

streambuf* origBuf = cout.rdbuf(); //added in from lines 157-158

/*

The line of code above (line 115) will open the file " of("MyLog.txt") "

Now, if we do:

*/

//cout.rdbuf();

/*

We must note that, when this function is taking a parameter, it is assigning a
different 'stream buffer' to the stream of 'cout'. So we must write the 
following:

*/

cout.rdbuf(of.rdbuf());

/*

Now, we are assigning the 'stream buffer' of 'of' to 'cout'.

As a result, if we do the following:

*/

cout << "Hello" << endl; //MyLog.txt has "Hello"
//Redirecting

/*

This string of 'hello' will go to "MyLog.txt". This is called "Redirecting".
We are 'redirecting' the 'standard out' to a 'log' file. However, you must be
careful later on if you want to restore 'cout' to its original 'stream buffer',
you cannot do so anymore because the original 'stream buffer' is lost. 

So a better way to do that is using a temporary variable to save the original
'stream buffer'. (We will add this in line 117)

Now that we added that line of code into our program, we can now restore 'cout'
to its original 'stream buffer'. Doing so, we can continue with this next line 
of code:

*/

cout.rdbuf(origBuf);

/*

Now, if we do the following:

*/

cout << "Goodbye" << endl;

/*

We'll have a "Goodbye" message.

Another way to access the 'screen buffer' is by using a type of iterator called
the "stream buffer iterator". For example, we have:

*/

//Stream buffer iterator
istreambuf_iterator<char> i(cin);  //stream iterator #1

/*

Now, we can define another 'ostream':

*/

ostreambuf_iterator<char> o(cout); //stream iterator #2

/*

Then, we can write the following 'while' statement:

*/

while (*i != 'x')
{
    *o = *i;
    ++o;
    ++i;
}

/*

The 'while' loop above will take everything from the 'input' and echo it out to 
the 'standard output' until it sees the letter 'x'.

Another way to do this is by using the following algorithm function:

*/

copy(istreambuf_iterator<char> (cin), istreambuf_iterator<char> (), ostreambuf_iterator<char>(cout));

/*

The above line of code is an iterator that points to the start of the 'input 
stream buffer'. At this point, we are referring specifically to: 
---> istreambuf_iterator<char> (cin)

We then add a 'default constructor'. At this point, we are referring 
specifically to:
---> istreambuf_iterator<char> ()
The 'default constructor' points to the end of the 'input stream buffer'.

We then add one more iterator. At this point, we are referring specifically to:
---> ostreambuf_iterator<char>(cout)
This iterator is pointing to the start of the 'output stream buffer'. 



This ONE line of code will do the same thing that the 'while' loop does. 
However, it does not have the exit letter that the 'while' loop has (recall:
the loop ends when the program discovers the letter 'x')

*/







//for more space
