/*
 * Sometimes it is useful to collect together multiple
 * values before processing them all at once.  This will
 * help us attack certain new problems we'd have once found
 * insurmountable as well as helping us design old programs
 * in new and better ways.
 *
 * One simple example is that of collecting multiple values
 * about which we want statistical information:  mean,
 * median, etc.  Some of that information we could collect
 * as the data was entered -- mean, minimum, maximum, for
 * instance.  We could just have a single variable to hold
 * each piece of data entered and overwrite it as we looped
 * around:
 *
 *     cin >> data;
 *     while ( ~~ there's more data ~~ )
 *     {
 *         // update statistics
 *         cin >> data;
 *     }
 *
 * *************************************************************
 *
 * But other things like the median (or any of the *tiles)
 * require us to have all the data available and examinable
 * at once rather than just one piece of information at a
 * time like we'd have done in chapter 3.  (After all, the
 * median is the middle element of a set of data.  This
 * requires us to not only see all the data at once rather
 * than one piece at a time, but also to place the data into
 * order somehow so that we know what the middle is!)
 *
 * *************************************************************
 *
 * We've done such gathering of lots of data before with
 * words/phrases -- gathering sequences of chars -- thanks
 * to the string class.  But if we wanted to hold multiple
 * double's, short's, or other data, we were out of luck.
 * We'd've had to have made multiple variables with stupid
 * names like:
 *
 * +====+        +====+        +====+        +====+        +====+        +====+
 * | 42 | age1   | 47 | age2   | 12 | age3   | 34 | age4   | 17 | age5   | 25 | age6
 * +====+        +====+        +====+        +====+        +====+        +====+
 *
 * This could easily become horrible to maintain and follow.
 * We need something better.  Some way to store multiple
 * values in a single variable.
 *
 * *************************************************************
 *
 * What's that?  A class can store multiple variables?
 * Well, yes, but it still requires us to name them all
 * individually.  We'd be right back to where we started.
 * Plus, the class imposes security mechanisms:  private
 * areas, accessors, and mutators.  That would suck even
 * worse for our purposes here!
 *
 * *************************************************************
 *
 * vectors to the rescue!
 *
 * The vector library (from the standard libraries) contains
 * a class type called vector.  (Weird, no?)
 *
 * A vector can contain any type of information -- called
 * the base type -- except void.  This makes it a more
 * powerful data containment tool than a string in that
 * string is limited to sequences of char.
 *
 * The base type is specified when you first declare your
 * vector [object/variable] by using angle brackets after
 * the class and around the desired base type:
 *
 *     vector<short> ages;
 * 
 * This declares the object/variable ages to be a vector of
 * short integers.  (Note we use the phrasing 'of' -- just
 * like with function notation -- to indicate the base type
 * verbally.)
 * 
 * 
 * 
 * 
 * --------------------------------------------------------------
 * We read vector<short> as "vector of short"
 * --------------------------------------------------------------
 * 
 * 
 * 
 * 
 * 
 *
 *
 * *************************************************************
 *
 * At some point in the program, the ages vector might look
 * like this in memory:
 *
 *    +====+====+====+====+====+====+
 *    | 42 | 47 | 12 | 34 | 17 | 25 |  ages
 *    +====+====+====+====+====+====+
 *       0    1    2    3    4    5    (positions)
 *
 * Notice how positions are numbered from 0 just like for
 * strings.  We can access individual values within the
 * vector using the subscript operator just like we can for
 * strings, too:
 *
 *     cout << ages[0];    // prints 42
 
 
 
 // ages is a size_type integer, so we use unsigned integer quantities within "ages[]"
 
 
 
 *
 * If we want to access individual elements (values within
 * the vector) non-literally, we'll need to use the vector
 * class' size_type -- just like we did with the string
 * class.  A tricky bit here is that we need to indicate the
 * base type of the vector to declare a variable of the
 * vector's size_type to use as a subscript:
 *
 *     vector<short>::size_type age_pos;
 *
 * This declares age_pos to be capable of storing
 * position/size information about a vector of short
 * integers.  (Although the name makes it clear that it is
 * focused on position information, it could technically
 * store either.)
 *
 * If this is too much for you to type a lot, don't forget
 * that you can make your own alias or typedef for this data
 * type:
 *
 *     typedef vector<short>::size_type vecS_sz;
 *
 * or:
 *
 *     using vecS_sz = vector<short>::size_type;
 *
 * Here, vecS_sz is now equivalent to
 * vector<short>::size_type which is equivalent to the best
 * unsigned integer on the system for storing size (and
 * therefore position) information about vectors of short
 * integers!
 *
 * To go along with the subscript operation and the
 * ::size_type we also have a .size() function:
 *
 *     cout << ages.size();    // prints 6 <--- because there are 6 things in our vector right now
 
 //find the number of things within the container
 
 *
 * And we even have a .empty() function to report the
 * complete absence of any elements:
 *
 *     if ( ! ages.empty() )
 *     {
 *         for (age_pos = 0; age_pos+1 != ages.size(); ++age_pos)
 *         {
 *             cout << ages[age_pos] << ' ';
 *         }
 *         cout << ages[age_pos] << '\n';
 *     }
 
 
 //this error message checks to see if there even is anything in the container or not
 
 //.size() can be used in vectors and strings
 
 //size_type can read the SIZE of something within a vector, and because of that it 
 //holds the POSITION of everything within a vector
 
 //size_type reads 'unsigned int' because we dont need negative or half positions
 
 
 *
 * *************************************************************
 *
 * But, the base type is not known until compile-time when a
 * programmer such as yourself declares the vector variable.
 * During its design, the programmers who wrote the vector
 * class had no specific knowledge of what its base type
 * would be.  Therefore, the vector class cannot provide all
 * of the facilities that we might like to have on a
 * container of items -- as strings did.  What it does
 * provide, however, is quite a nice set upon which to build
 * our needs:
 
 
 
 base type ---> tells what 'int' to call the data member. 
 So if it's a short int it reads 'short' or if it's a long int it reads 'long'
 
 
 
 *
 *     basic vector functionality:
 *
 *        --                // default construction to an
 *                          //    empty vector
 *        -- (v)            // copy construction from
 *                          //    another vector
 *        -- operator =     // assign one vector to be
 *                          //    exactly like another
 *        -- ::size_type    // for sizes and positions
 *                          //    within the vector
 *        -- .size()        // no .length()!!
 *        -- .empty()       // true when vector contains no
 *                          //    elements
 *        -- .clear()       // erase all vector elements --
 *                          //    make it empty
 *        -- operator []    // subscript/index operation
 *        -- .at()          // subscript/index function
 *                          //    (crashes when
 *                          //    out-of-bounds)
 *        -- .front()       // gives a reference to the 0th
 *                          //    item  (like v.at(0))
 *        -- .back()        // gives a reference to the
 *                          //    (.size()-1)st item
 *                          //    (like v.at(v.size()-1))
 *        -- ( n )          // construct a vector of n items
 *                          //    -- each is itself default
 *                          //    constructed
 *        -- ( n, e )       // construct a vector of n items
 *                          //    -- each is itself a copy
 *                          //    of the value e
 *        -- = { e1, e2, ... , en }  // construct the vector
 *                         // of n items each a copy of the
 *                         // corresponding initializer
 *        -- .push_back(e)  // put [new] element e onto the
 *                          //    back of the vector
 *        -- .pop_back()    // removes the last item from
 *                          //    the vector; if the data is
 *                          //    at position p rather than
 *                          //    the end, just swap(v[p],v.back());
 *                          //    before you call v.pop_back();
 
 
 
 //.emplace_back() takes everything in () as initial arguments for the element constructor
 // can be effective to use when your vector elements are actually class objects
 
 
 
 
 *
 * Taking into account these new capabilities, I can clean
 * up my printing loop like so:
 *
 *     if ( ! ages.empty() )
 *     {
 *         for (vector<short>::size_type age_pos = 0;
 *              age_pos+1 != ages.size(); ++age_pos)
 *         {
 *             cout << ages[age_pos] << ' ';
 *         }
 *         cout << ages.back() << '\n';
 *     }
 *
 * Don't forget that you can use a typedef to make a handy
 * alias for the size_type of any vector you are using in
 * your program:
 *
 *     typedef vector<short>::size_type vecSh_sz;
 *
 * And then the for loop becomes more normal looking:
 *
 *     if ( ! ages.empty() )
 *     {
 *         for (vecSh_sz age_pos = 0; age_pos+1 != ages.size(); ++age_pos)
 *         {
 *             cout << ages[age_pos] << ' ';
 *         }
 *         cout << ages.back() << '\n';
 *     }
 *
 * *************************************************************
 *
 * Additionally, vector supports the following operations:
 *
 *        -- .resize(n)     // change vector to be n
 *                          //    elements long; if n is
 *                          //    greater than .size(), new
 *                          //    elements are default
 *                          //    constructed         
 *
 *                          // if .size() is used, it will just chop off the elements being used
 * 
 *        -- .resize(n,e)   // change vector to be n
 *                          //    elements long; if n is
 *                          //    greater than .size(), new
 *                          //    elements are copy ctor'd
 *                          //    from e
 *        -- .capacity()    // reports the currently
 *                          //    available storage for
 *                          //    the vector -- typically
 *                          //    >= .size()         
 
 
 
 // .capacity() holds extra storage. 
 // you can do push_back() two more times before having the vector grow
 
 
 
 *
 * []:    0     1     2     3     4     5     ?     ?
 *     +===============================================+
 *     | xxx | yyy | zzz | www | aaa | bbb |     |     |
 *     +===============================================+
 *  .size() == 6
 *  .capacity() == 8
 *
 *        -- .max_size()    // reports the largest .size()
 *                          // the vector can possibly achieve 
 *                          // (not terribly accurate and 
 *                          // implementation defined)
 *
 * *************************************************************
 *
 * Notably missing are things like the string class'
 * .insert(), .erase(), .assign(), .replace(), .substr(),
 * and even the .*find*() functions!  You also cannot use +
 * or += for concatenation operations on a vector.  Most
 * annoyingly missing, however, are insertion and
 * extraction!  In order to input a vector, we must input a
 * single element and then .push it on the back() of the
 * vector.
 */
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const streamsize UNTIL_YOU_THROW_OUT = numeric_limits<streamsize>::max();

//const streamsize numeric_limits<streamsize>::max() = numeric_limits<streamsize>::max(); 
//the line above was was error on the notes provided online

/*
 * Add up all elements in the given vector.  vector contents
 * are NOT harmed in the totalling process.  The sum is
 * returned for caller use.
 */
double total(const vector<double> & v); //pass by reference so you dont change anything and you dont make a copy

/*
 * Read a sequence of numbers, storing each into the vector
 * in input order.  We stop reading when some non-numeric
 * value is entered.  At this point cin is clear'd and its
 * buffer emptied of the non-numeric value(s).
 *
 * The caller may also specify a prompt to be displayed
 * [once] before we begin extracting numbers.  (The default
 * is an empty string -- i.e. no prompt.)
 *
 * Finally, the caller may specify whether or not to add the
 * input numbers to the current vector contents or to erase
 * the old contents and start fresh.  (The default is to
 * erase the original contents and begin anew -- i.e. to NOT
 * append.)
 */
const bool ADD_NEW_NUMS = true,
           ERASE_OLD_NUMS = false;
void input_all_nums(vector<double> & v,
                    const string & prompt = "",
                    bool append = ERASE_OLD_NUMS);

/*
 * Print all elements in the given vector.  Caller may
 * specify strings to be placed before, after, and between
 * the elements of the vector.
 *
 * Should only be called with at least one element in your
 * vector!
 */
void display(const vector<double> & v,
             const string & pre = "{ ",
             const string & post = " }",
             const string & between = ", ");

// Writing the print statements in this way makes this re-usable. 
// It becomes re-usable because the 'const string & pre', 'const 
// string & post', and 'const string & between' lets whoever is 
// working on the program to print whatever needs to be printed
// in different ways

int main(void)
{
    vector<double> heights;

    cout << "\n\n\t\tWelcome to the Amazing Height "
            "Averager!!!\n";

    input_all_nums(heights,
                   "\nEnter your heights, 'quit' to "
                   "end...\n");

    cout << "\nI've read your " << heights.size()
         << " height value"
         << (heights.size() == 1 ? "" : "s") << ".\n";

    if ( ! heights.empty() )
    {
        cout << "\nProcessing...done!\n\nYour list of "
                "heights:\t\t";

        display(heights); 
                          // different printing methods:
                          
                          //, "", "", "\a ");
                          //, "< ", " >", " ");
                          //, "\n{\n\t", "\n}\n", "\n\t");
                          //, "", " and that's all, folks!", " and ");

        cout << "\n\nThe average height is "
//             << (heights.size()==0 ? 0.0
//                                   : total(heights) /
//                                     heights.size())
             << total(heights) / static_cast<double>(heights.size())
             << ".\n";
    }
    else
    {
        cout << "\n\aThanks for wasting my time, bozo!  "
                "*phbbt*\n";
    }

    cout << "\nPlease run AHA again sometime!\n\nHave a "
            "nice day!  *wave*\n\n";

    return 0;
}

/*
 * Add up all elements in the given vector.  vector contents
 * are NOT harmed in the totalling process.  The sum is
 * returned for caller use.
 */
double total(const vector<double> & v)  // const& since we aren't changing it
{
    double t = 0.0;  // sum init with additive identity
    for (vector<double>::size_type p = 0;      // from beginning of vector
         p != v.size();                        // to (but not including) end
         ++p)                                  // one by one...
    {
        t += v[p];                             // add each to the sum
    }
    return t;
}
//
// To avoid the hideously long and potentially unwieldy
// syntactic construct:
//
//     vector<double>::size_type
//
// You can use a typedef'inition.  Simply place this:
//
//     typedef vector<double>::size_type vecD_sz;
//
// at the top of your program (between the using directive
// and its first use) and you can there-after refer to such
// instances thusly:
//
//     for (vecD_sz p = 0; p != v.size(); ++p)
//
// Which is, of course, much shorter and most likely as
// clear to most.
//
// This could've also been a nice range-based for loop like
// so:
//
//     for (auto n : v)
//     {
//         t += n;
//     }
//
// (If we wanted to change the elements, we could use 'auto &'
// or if we want to not change but be extra efficient with
// larger element types, we could use 'const auto &' or
// 'auto const &'.

/*
 * Print all elements in the given vector.  Caller may
 * specify strings to be placed before, after, and between
 * the elements of the vector.
 */
void display(const vector<double> & v, const string & pre,
             const string & post, const string & between)
{
    cout << pre;
    if ( ! v.empty() )
    {
        for (vector<double>::size_type p = 0;
             p+1 != v.size(); ++p)
        {
            cout << v[p] << between;
        }
        cout << v.back();
    }
    cout << post;
    return;
}

/*
 * Read a sequence of numbers, storing each into the vector
 * in input order.  We stop reading when some non-numeric
 * value is entered.  At this point cin is clear'd and its
 * buffer emptied of the non-numerics.
 *
 * The caller may also specify a prompt to be displayed
 * [once] before we begin extracting numbers.  (The default
 * is an empty string -- i.e. no prompt.)
 *
 * Finally, the caller may specify whether or not to add the
 * input numbers to the current vector contents or to erase
 * the old contents and start fresh.  (The default is to
 * erase the original contents and begin anew -- i.e. to
 * NOT append.)
 */
void input_all_nums(vector<double> & v,
                    const string & prompt, bool append)
{
    double t;  // temporary to read from cin before putting it in the vector
    // t is a local helper variable

    if ( ! append )  // caller does NOT want to add new items to the end of v
    {
        v.clear();   // erase old v contents
    }
    cout << prompt;
    cin >> t;
    while ( ! cin.fail() )  // could check for negatives (or a special value were
    {                       // we reading strings...)
        v.push_back(t);  // grows as needed to add more data
        cin >> t;
    }
    cin.clear();                  // clear cin's >> failure
    cin.ignore(UNTIL_YOU_THROW_OUT, '\n');    // erase buffer contents
    return;
}
