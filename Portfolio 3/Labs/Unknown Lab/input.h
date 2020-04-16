#ifndef INPUT_LIBRARY_HEADER_INCLUDED
#define INPUT_LIBRARY_HEADER_INCLUDED

#include <iostream>
#include <cctype>

// Boundaries are assumed to be solid -- low <= value <= high.

// Enum to say which end is to be bounded...
//
enum BoundType { Low, High, Both };

// Bounded entry function for long integers...
//
long get_bounded(long low, long high,
                 const char prompt[] = "Enter bounded value:  ",
                 BoundType which_end = Both);

// Overloaded for double data...
//
double get_bounded(double low, double high,
                   const char prompt[] = "Enter bounded value:  ",
                   BoundType which_end = Both);

// Limiting a character entry to one of a few...
//
char get_in_set(const char set[] = "YyNn",
                const char prompt[] = "Shall we play a game?  ",
                const char errmsg[] = "\nInvalid entry..."
                                      "try again, schmuck!\n\n");

// look at the next non-whitespace character
//
inline char peek(std::istream & in)
{
    while (std::isspace(in.peek()))
    {
        in.ignore();
    }
    return in.peek();
}

// clear until the character is found (remove the char, too)
//
inline void clear_until(std::istream & in = std::cin, char find_me = '\n')
{
    char ch;
    do
    {
        ch = in.get();
    } while (ch != find_me);
    return;
}

//
// true if user answers Yes, false if No.  No other responses
// are allowed.  On error, an error message is printed and
// the user is re-prompted.
//
bool yesno(const char prompt[] = "Yes/No?  ",
           const char errmsg[] = "\nY for Yes or N for No!!\n\a\n");

#endif
