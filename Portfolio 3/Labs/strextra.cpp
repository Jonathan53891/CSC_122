#include "strextra.h"

#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cfloat>

using namespace std;

#include "handy.h"

// find a character (ch) in the string (str)
// returns the offset of ch in str or -1 if
// the character isn't present in the string
//
// looks along the string until it finds
// either ch or EOS.  Returns pos when
// ch is found, -1 when not.
//
long find(const char str[],    // in
          const char ch,       // in
          const long from)     // in
{
    long pos = from;              // start at beginning of string

    while ((str[pos] != EOS) &&   // not at end of string
           (str[pos] != ch))      // haven't found ch
    {
        pos++;                    // move to next character of string
    }
    return (str[pos] == ch) ? (pos)   // even works if ch == EOS
                            : (-1);
}

long find(const char str1[], // in
          const char str2[], // in
          const long from)   // in
{
    long hold, pos1, pos2;
    bool found;
    pos1 = from;
    found = false;
    while ((str1[pos1] != EOS) && !found)
    {
        hold = pos1;
        pos2 = 0;
        while ((str1[pos1] != EOS) && (str1[pos1] == str2[pos2]))
        {
            pos1++;
            pos2++;
        }
        found = str2[pos2] == EOS;
        pos1 = hold+1;
    }
    return (found) ? (hold) : (-1);
}

// like strcpy, but allows you to copy from the
// middle (any position) of the source string
// WARNING:  no verification is attempted on the
//           validity of copy_from vs the length
//           of the original source string!!
//
// starts at beginning of destination and copies
// from an equal offset from src[copy_from].  stops
// when EOS is found.  always appends EOS to dest.
//
void strcpy_middle(char dest[],       // out
                   const char src[], // in
                   long copy_from)   // in
{
    long copy = 0;                          // start at beginning
    while (src[copy_from+copy] != EOS)      // haven't seen end
    {
        dest[copy] = src[copy_from+copy];   // copy next character
        copy++;                             // move to next character
    }
    dest[copy] = EOS;                       // make sure to end string
    return;
}

// splits the first string into two pieces at the
// location of the given character.
//    str --> str + ch + rest
// either str or rest (or both) may be empty when
// done
//
// locates ch in str (see find above).  if found,
// does a middle of the string copy (strcpy_middle
// above) from str at pos+1 to rest.  then it
// overwrites ch with EOS.
//
void split(char str[],  // in/out
           char rest[], // out
           char ch)     // in
{
    long pos = find(str, ch);    // find ch in str

    rest[0] = EOS;               // empty rest

    if (pos != -1)                         // found it
    {
        strcpy_middle(rest, str, pos+1);   // copy from one past ch
        str[pos] = EOS;                    // overwrite ch
    }
    return;
}

// splits the first string into two pieces at the
// location given.
//    str --> str + rest
// either str or rest (or both) may be empty when
// done
//
// copys to rest from the middle of str (position
// at) and overwrites str[at] with end of string
//
void split(char str[],  // in/out
           char rest[], // out
           long at)     // in
{
    strcpy_middle(rest, str, at);
    str[at] = EOS;
    return;
}

// aids mixing cin.getline with cin >> by avoiding
// reading empty lines when cin >> leaves the '\n'
// behind.  otherwise behaves as cin.getline
//
// peeks at next character in buffer, if it's a
// newline ('\n'), we remove it from the buffer.
// either way we do a getline as instructed.
//
void get_line(char str[],      // out
              const long MAX,  // in
              istream & in)    // in/out
{
    if (in.tie() != NULL)
    {
        in.tie()->flush(); // HP's compiler doesn't prompt for peeking
    }
    while (in.peek() == '\n')  // could also go with isspace(in.peek())
    {
        in.ignore();
    }
    in.getline(str, MAX);
    return;
}

short StrCmp(const char x[], const char y[])
{
    long pos = 0;
    while ((toupper(x[pos]) == toupper(y[pos])) &&
           (x[pos] != EOS))
    {
        pos++;
    }
    return (short)toupper(x[pos]) - (short)toupper(y[pos]);
}
short StrnCmp(const char x[], const char y[], const long n)
{
    long pos = 0;
    while ((toupper(x[pos]) == toupper(y[pos])) &&
           (x[pos] != EOS) && (pos < n))
    {
        pos++;
    }
    return (short)toupper(x[pos]) - (short)toupper(y[pos]);
}

long locate(const char string[],   // in
            const char * const table[],   // in
            const long MAX,        // in
            bool case_sensitive)   // in
{
    long pos = 0;
    if (case_sensitive)
    {
        while ((pos < MAX) && (strcmp(string,table[pos]) != 0))
        {
            pos++;
        }
    }
    else
    {
        while ((pos < MAX) && (StrCmp(string,table[pos]) != 0))
        {
            pos++;
        }
    }
    return (pos >= MAX) ? (-1) : (pos);
}

void strip_spaces(char string[], short where)
{
    long at, non_space;
    if ((where & STRP_END) == STRP_END)
    {
        at = strlen(string)-1;
        while (isspace(string[at]) && (at >= 0))
        {
            string[at--] = EOS;
        }
    }
    if ((where & STRP_BEG) == STRP_BEG)
    {
        non_space = 0;
        while (isspace(string[non_space]) && (string[non_space] != EOS))
        {
            non_space++;
        }
        at = non_space;
        while (string[at] != EOS)
        {
            string[at-non_space] = string[at];
            at++;
        }
        string[at-non_space] = EOS;
    }
    return;
}

void str_to_long(const char string[],   // in
                 long & value,          // out
                 long & from,           // in/out
                 bool signable)         // in (default == true)
{
    long temp, sign, count;
    bool had_sign;
    while ((string[from] != EOS) && isspace(string[from]))
    {
        from++;
    }
    if (isdigit(string[from]) ||
        (signable && (find("+-",string[from]) != -1)))
    {
        sign = 1;
        had_sign = false;
        if (signable && (find("+-",string[from]) != -1))
        {
            sign = (string[from] == '-') ? (-1) : (+1);
            had_sign = true;
            from++;
        }
        // sanity check
        count = 0;
        while (isdigit(string[from+count]))
        {
            count++;
        }
        if (count < 1)
        {
            // adjust from back if was just a sign!!!
            if (had_sign)
            {
                from--;
            }
            value = 0;
        }
        else if (count > 10)
        {
            // adjust from to end of too-long number
            from += count;
            value = 0;
        }
        else if ((count == 10) && ((strncmp(string+from,"2147483647",10)>0) ||
                                   ((sign == -1) &&
                                    (strncmp(string+from,"2147483648",10)>0))))
        {
            // adjust from to end of too-large number
            from += 10;
            value = 0;
        }
        else
        {
            temp = 0;
            while (isdigit(string[from]))
            {
                temp *= 10;
                temp += (short)string[from] - (short)'0';
                from++;
            }
            value = sign * temp;
        }
    }
    else
    {
        value = 0;
    }
    return;
}

void str_to_double(const char string[],   // in
                   double & value,        // out
                   long & from)           // in/out
{
    long whole, frac, exp, hold, orig;
    long double temp;
    orig = hold = from;
    str_to_long(string, whole, from);
    if (from == hold)
    {
        whole = 0;
    }
    temp = whole;
    if (string[from] == '.')
    {
        from++;
        hold = from;
        str_to_long(string, frac, from, false);
        if (hold != from)
        {
            if (whole < 0)
            {
                temp -= pow(10.0,(double)hold-from)*frac;
            }
            else
            {
                temp += pow(10.0,(double)hold-from)*frac;
            }
            // check for eE notation
            if (toupper(string[from]) == 'E')
            {
                hold = from+1;
                str_to_long(string, exp, hold);
                if (hold != (from+1))
                {
                    from = hold;
                    temp *= pow(10.0L, (long double)exp);
                }
            }
        }
    }
    else if (toupper(string[from]) == 'E')
    {
        hold = from+1;
        str_to_long(string, exp, hold);
        if (hold != (from+1))
        {
            from = hold;
            temp *= pow(10.0L, (long double)exp);
        }
    }
    if ((temp > DBL_MAX) || (temp < -DBL_MAX))
    {
        value = 0;
        from = orig;
    }
    else
    {
        value = temp;
    }
    return;
}
