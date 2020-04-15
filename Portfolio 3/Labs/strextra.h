#ifndef STRING_EXTRA_FUNCTIONS_LIBRARY_INCLUDED
#define STRING_EXTRA_FUNCTIONS_LIBRARY_INCLUDED

#include <iostream>

#ifdef HPUX_CRAP
#include <cstring>
#endif

#include "input.h"

// perhaps useful constant for the '\0' character
// (end of string)
const char EOS = '\0';

// find a character (ch) in the string (str)
// returns the offset of ch in str or -1 if
// the character isn't present in the string
long find(const char str[],       // in
          const char ch,          // in
          const long from = 0);   // in
long find(const char str1[],      // in
          const char str2[],      // in
          const long from = 0);   // in

// like strcpy, but allows you to copy from the
// middle (any position) of the source string
// WARNING:  no verification is attempted of
//           the validity of copy_from vs the
//           length of the source string!!
void strcpy_middle(char dest[],       // out
                   const char src[], // in
                   long copy_from);  // in

// splits the first string into two pieces at the
// location of the given character.
//    str --> str + ch + rest
// either str or rest (or both) may be empty when
// done
void split(char str[],  // in/out
           char rest[], // out
           char ch);    // in

// splits the first string into two pieces at the
// location given.
//    str --> str + rest
// either str or rest (or both) may be empty when
// done
void split(char str[],  // in/out
           char rest[], // out
           long at);    // in

// aids mixing istream::getline with operator>> by avoiding
// reading empty lines when operator>> leaves the '\n'
// behind.  otherwise behaves as istream::getline
void get_line(char str[],       // out
              const long MAX,   // in
              std::istream & in = std::cin);  // in/out

// reads a string from a line and then clears the rest of the line
inline void get_one_string(char str[],         // out
                           const long MAX,     // in
                           std::istream & in = std::cin) // in/out
{
    get_line(str, MAX, in);
    if (in.fail()
#ifdef HPUX_CRAP
          || (std::strlen(str) == (MAX-1))   // HP/UX doesn't seem to follow
                                        // the standard here
#endif
       )
    {
        in.clear();
        clear_until(in);
    }
    return;
}

// case insensitive comparison
short StrCmp(const char x[], const char y[]);
short StrnCmp(const char x[], const char y[], const long n);

// find a string in a table of length MAX
// may be case sensitive or not
long locate(const char string[],   // in
            const char * const table[],   // in
            const long MAX,        // in
            bool case_sensitive = true);   // in

// constants for specifying which end to strip spaces from
const short STRP_BEG = 0x01,
            STRP_END = 0x02,
            STRP_BTH = STRP_BEG | STRP_END;

// remove spaces from string as indicated
void strip_spaces(char string[], // in/out
                  short where = STRP_BTH);  // in

// translate a string to a long integer starting from the given
// position;  the bool indicates if a sign is allowed; the
// ending position of translation is returned through the position
// argument
void str_to_long(const char string[],   // in
                 long & value,          // out
                 long & from,           // in/out
                 bool signable = true); // in

// translate the string to a double value starting from the
// given position; the ending position of translation is
// returned through the position argument
void str_to_double(const char string[],   // in
                   double & value,        // out
                   long & from);          // in/out

#endif
