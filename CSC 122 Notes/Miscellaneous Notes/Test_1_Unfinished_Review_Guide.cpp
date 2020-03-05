/******************************************************************************

4) Once you are ready, you’ll need to do two things to make a connection to a user’s file:
    - pass your string filename to the file connecting method as is.
    - use the open method with respect to your stream variable.

5) Given the following sort function:

// sort between start and end indices (inclusive) 
void good_bubble(vector<char> & vec,
                 vector<char>::size_type start, 
                 vector<char>::size_type end)
{
    vector<char>::size_type loop = start, cur; 
    bool done = false;
    while (loop != end && !done)
    {
        done = true;
        for (cur = start; cur != end; ++cur) 
        {
            if (vec[cur] < vec[cur+1]) 
            {
                swap(vec[cur], vec[cur+1]);
                done = false;
            }
        }
        ++loop; 
    }
    return; 
}

We can alter it to sort a vector of "Rational" objects:

void good_bubble(vector<Rational> & vec,
                 vector<Rational>::size_type start, 
                 vector<Rational>::size_type end)
{
    vector<Rational>::size_type loop = start, cur; 
    bool done = false;
    while (loop != end && !done)
    {
        done = true;
        for (cur = start; cur != end; ++cur) 
        {
            if (vec[cur].less(vec[cur+1])) 
            {
                swap(vec[cur], vec[cur+1]);
                done = false;
            }
        }
        ++loop; 
    }
    return; 
}

void swap(Rational & a, Rational & b)
{
    Rational c;
    c = a;
    a = b;
    b = c;
    return;
}


6) When opening a file connection, make sure the stream connected successfully to the file by:
    - checking for fail or !good or even just !.
    - using close and clear inside the checking loop.

7) A class named Avg contains a data member named Nums which is a vector of double values. 
   Show definitions for accessor and mutator methods for this data member.

typedef vector<double>::size_type vcD_sz;

bool Avg::set_num(vcD_sz which, double num) 
{
    bool worked = false;
    if (which < Nums.size()) 
    {
        Nums[which] = num;
        worked = true;
    }
    else if(which == Nums.size())
    {
        worked = add_new_num(num);
    }
    return worked;
}

bool Avg::add_new_num(double num) 
{
    //should we check Nums.max.size()?
    Nums.push_back(num);
    return true;
}

double Avg::get_num(vcD_sz which) const
{
    return (which < Nums.size()
            ? Nums[which] : -42.0);
}

vcD_sz Avg::get_num_nums(void) const
{
    return Nums.size()
}

8) 

a) What is the type of getline’s first argument that it can be used to read from either cin or an ifstream 
variable?
    - istream & is compatible with both the console stream cin and any ifstream variable.
b) What type should you use to allow a function to ’display’ to either cout or an ofstream variable?
    - ostream & is compatible with both the console stream cout and any ofstream variable.
    
9) 

a) Ideal prototype for a method to input an object of the class Rational from the user. 
    - bool Rational::input(void);
b) Now show an example of a call to the method whose prototype you chose above.

Rational a;
cout << "Some kind of prompt: "; 
while ( ! a.input() )
{
    // clear, ignore, error message, re-prompt... }
}

10) 

a) What functions/operations can you use to get data from an ifstream variable? ", 
    - getline, peek, etc.
b) What functions/operations can you use to put data into an ofstream variable? 
    - !, setw, flush, etc.

11) A class’ copy constructor is automatically called in three (3) situations. What/When are they?
    - when one object is declared and at the same time initialized with another object that already exists
    - when a function accepts an argument using the value mechanism, the formal argument is copy constructed 
    from the actual argument
    - when a function returns its result using the value mechanism, the result given back to the caller is 
    copy constructed from the value of the return expression


12) What two new keywords are used to specify where in the program access to the members of a class object is
available? Explain who (i.e. what parts of the program) can access members of each access type.
    - private
        ~ only the members (methods; data doesn’t access other data) of the class itself can access private 
        members (data or methods) of a class
    - public 
        ~ any part of the program can access public members (methods, typically; data would be silly) of a class


13)
    - All methods of a class can access the private data of the class.
    - Data which is public is generally NOT considered normal when defining a class.
    private methods, although rare, can often be useful for tasks the class must (or should) manage on its own.

14) Given that a class exists named "Complex" which has a method to add two "Complex" objects, we might call it like 
this (note the flexibility the caller has):

Complex a, b, c;
// fill in a and b
// with values somehow 
c = a.add(b);

Complex a, b;
// fill in a and b
// with values somehow
a.add(b).output();

Show the definition of a method to add two Complex objects. (Recall that a complex number is of the form a + or - bi,
where i represents sqrt(-1) -- the square root of -1, which is an imaginary value) 

// adds the Complex object ’other’ to the calling object 
// to produce the result which is returned to the caller 

const Complex Complex::add(const Complex & other) const 
{
    return Complex(real + other.real, imag + other.imag); 
}

// adds the ’real’ other value to the calling object
// to produce the result which is returned to the caller 
const Complex Complex::add(double other) const
{
    return Complex(real + other, imag); 
}

15) Any/All classes should include at least the following methods: 
    - constructors (at least default and copy)
    - accessors & mutators
    - input & output

16) What is the member access operator in C++?
    - The period or dot (.) is used to access members of a class in C++.
    
17) What does the term ’calling object’ mean, anyway?
    - The calling object is the object on the left side of the dot (.) operator in the call to a class method. 
    (I.E. a is the calling object in the Complex addition problem (#14)).

18) 

a) In relation to other parts of a program, where would a class definition be placed? 
    - Either above the main (typically after the using directive) or in the interface (.h) file of a library.
b) What about the definitions of [non-inline] class methods? 
    - Either after the main or in the implementation (.C or .cpp) file of a library.

19) 
    - In a method to add two Rational numbers, the calling object acts as the left-hand addend (value to be added). 
    (See the explanation of rational numbers in #9.)
    (i.e. left + right --> left.add(right) )
    - The single Rational argument DOES NOT act as the left-hand addend.
    - The result of the addition is NOT stored in a new Rational object — but we still may possibly change either 
    the left- or right- hand objects — or both!
    - This new object is returned from the add function by the return value mechanism
    
20) 

a) What is required to make a class argument ’pass-by-value’?
    - Nothing — just pass the formal argument with the class type and a name and pass the actual argument like normal.
b) What is required to make a class argument ’pass-by-reference’?
    - As with the built-in types (or string — which is a class, after all), place an ampersand (&) between the type of 
    the formal argument and its name. The actual argument is passed like normal.
    
21) Explain (briefly but correctly) the purpose of accessor and mutator methods in a class.
    - accessor: 
        ~ allows caller to view a copy of the value in a private data member of the class (without direct access, they 
    cannot accidentally change the member’s value!)
    - mutator: 
        ~ allows the caller to perform controlled changes to the specified private data member of the class; contains 
        any error checking and/or validity checking codes necessary to ensure that the class’ data members are not 
        butchered, garbled, or otherwise messed up/destroyed
        
22)

a) Why don’t class input methods typically display a prompt for the user?
    - They are trying to be as generic/general/re-usable as possible. With a literal prompt, they’d be in the way of 
    interface customization or be too specific to a particular application. With an argument prompt...well, Jason 
    just said it would be ’untrue to the zen of class programming’. . . or something like that. And with a prompt member 
    (& proper accessor/mutator), we’d be managing data outside of our class’ ’true nature’. . . whatever that means.
b) Shouldn’t the program always prompt before input?
    - Yes, but that is the program — not our class! We want to be re-used by program after program after program... 
    ”Don’t tie me down!”
c) Why don’t class output methods typically print labels and/or spacing?
    - Similar to the input methods part and prompting — it isn’t generic! If I want my time writing this class to be 
    rewarded by lots of people downloading it and using it, I’ve gotta keep myself. . . er. . . it as general and 
    re-usable as I can!
d) Shouldn’t the program always label outputs?
    - Well, the program should, certainly. But I’m a simple data type and I don’t know what kind of program I’m in. 
    I’m not going to presume what kind of labels or even spacing might be appropriate around my data! I’ll just 
    print the raw essence of my being to the display and hope the program has set up appropriate labeling and spacing 
    either before or after me if not both...

23) Name and describe the three types of constructors briefly:
    - default
        ~ takes no input, fills in data members with sensible values (or purposely erroneous values) when programmer 
        didn’t supply any
    - copy
        ~ takes a [constant] reference to the class type as input, fills in data members of the object being 
        constructed with copies of those from the object we have a reference to (via the formal argument)
    - initialization parameterized
        ~ takes formal arguments appropriate to initialize some/all data members of the class as input, there may be 
        many versions of this type of constructor — each would take a different number or type(s) of arguments to 
        overload the others

24) Benefits that classes give us over the built-in data types:
    - improved initialization of new variables/objects via constructors (most notably the default constructor — 
    built-in types are simply left with garbage bits by default!)
    - data are closely coupled with the operations that work with them
    - allow us to more naturally represent real-world data by collecting together all the little pieces in one place 
    rather than scattered variables each with a part of the whole
    - collected data can be of multiple different types — a built-in typed variable is just the one type (even a 
    string can only collect many values of the type character together!)
    - primitive data security via the private/public keywords and the accessor/mutator methods we provide

25) Other than those you chose above (#15), what methods might/should a Complex class include?
    - Complex add(const Complex & c) const;
    - Complex add(double x) const;
    - Complex conjugate(void) const;
    - double magnitude(void) const;

26) 

a) What is the only real difference between an ADT and a class?
    - An ADT is a general description that could be used by a programmer to implement it in any programming 
    language. classes are the C++ mechanism for implementing ADTs.
b) What does ADT stand for, anyway?
    - Abstract Data Type

27) How is overloading involved with constructors?
    - Since all constructors have to be named after the class they construct, we must overload them to allow the 
    programmer using our class to create their objects in useful ways: by default, with specific values right away, 
    as a copy of another object, etc.




*/
