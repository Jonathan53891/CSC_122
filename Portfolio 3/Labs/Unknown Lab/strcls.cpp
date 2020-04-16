// uncomment this to fix problems with the HP compiler
// (the latest CPP uses g++ -- not the HP compiler (aCC))


#include "strcls.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include <climits>

using namespace std;

// These are for debugging memory leaks...
bool String::debug = false;

// to turn on memory debugging (UNIX only) please do NOT
// #define the symbol NOT_UNIX if you are running in
// Linux, HP/UX, SunOS, Solaris, Mac OSX, or even CygWin
//
// in any case, if you are on Windows directly, feel free to
// define NOT_UNIX as a project-wide symbol (in Visual 6.0 or
// before you do this in the project settings -- the symbols
// are a comma separated list, btw;  I haven't found it on
// Visual .NET or later, yet...still looking)

#include <time.h>




#include "strextra.h"
#include "handy.h"

short String::compare(const String & other) const
{
    const char *left, *right;
    short retval;
    left = string;
    right = other.string;
    if ((left == NULL) || (right == NULL))
    {
        retval = ((left == NULL) && (right == NULL))
                     ? 0
                     : (((left == NULL) && (right != NULL))
                            ? -1
                            : 1);
    }
    else
    {
        if ((flags & case_on) != 0)   // should we consider the other
                                      // guy's case sensitivity, too?
        {
            while ((*left != EOS) &&
                   ((*left-*right)==0))
            {
                left++;
                right++;
            }
        }
        else
        {
            while ((*left != EOS) &&
                   ((toupper(*left)-toupper(*right))==0))
            {
                left++;
                right++;
            }
        }
        retval = ((flags & case_on) != 0)
                      ? (*left-*right)
                      : (tolower(*left)-tolower(*right));
    }
    return retval;
}

short String::compare(const char other[]) const
{
    return compare(String(other));
}

short String::compare(const char other) const
{
    return compare(String(other));
}

short compare(const char other[], const String & me)
{
    return String(other).compare(me);
}

short compare(const char other, const String & me)
{
    return String(other).compare(me);
}

bool String::operator==(const String & right) const
{
    return compare(right) == 0;
}

bool String::operator==(const char right[]) const
{
    return compare(right) == 0;
}

bool String::operator==(const char right) const
{
    return compare(right) == 0;
}

bool operator==(const char left[], const String & right)
{
    return String(left).compare(right) == 0;
}

bool operator==(const char left, const String & right)
{
    return String(left).compare(right) == 0;
}

bool String::operator<(const String & right) const
{
    return compare(right) < 0;
}

bool String::operator<(const char right[]) const
{
    return compare(right) < 0;
}

bool String::operator<(const char right) const
{
    return compare(right) < 0;
}

bool operator<(const char left[], const String & right)
{
    return String(left).compare(right) < 0;
}

bool operator<(const char left, const String & right)
{
    return String(left).compare(right) < 0;
}

bool String::operator>(const String & right) const
{
    return compare(right) > 0;
}

bool String::operator>(const char right[]) const
{
    return compare(right) > 0;
}

bool String::operator>(const char right) const
{
    return compare(right) > 0;
}

bool operator>(const char left[], const String & right)
{
    return String(left).compare(right) > 0;
}

bool operator>(const char left, const String & right)
{
    return String(left).compare(right) > 0;
}

bool String::operator!=(const String & right) const
{
    return !(*this == right);
}

bool String::operator!=(const char right[]) const
{
    return !(*this == right);
}

bool String::operator!=(const char right) const
{
    return !(*this == right);
}

bool operator!=(const char left[], const String & right)
{
    return !(left == right);
}

bool operator!=(const char left, const String & right)
{
    return !(left == right);
}

bool String::operator<=(const String & right) const
{
    return !(*this > right);
}

bool String::operator<=(const char right[]) const
{
    return !(*this > right);
}

bool String::operator<=(const char right) const
{
    return !(*this > right);
}

bool operator<=(const char left[], const String & right)
{
    return !(left > right);
}

bool operator<=(const char left, const String & right)
{
    return !(left > right);
}

bool String::operator>=(const String & right) const
{
    return !(*this < right);
}

bool String::operator>=(const char right[]) const
{
    return !(*this < right);
}

bool String::operator>=(const char right) const
{
    return !(*this < right);
}

bool operator>=(const char left[], const String & right)
{
    return !(left < right);
}

bool operator>=(const char left, const String & right)
{
    return !(left < right);
}

String String::operator+(const String & right) const
{
    char * t = NULL;
    if ((length > 0) && (right.length > 0))
    {
        t = new char [length+right.length+1];
        if (t != NULL)
        {
            strcpy(t,string);
            strcat(t,right.string);
        }
    }
    else if (length > 0)
    {
        t = new char [length+1];
        if (t != NULL)
        {
            strcpy(t,string);
        }
    }
    else if (right.length > 0)
    {
        t = new char [right.length+1];
        if (t != NULL)
        {
            strcpy(t,right.string);
        }
    }
    // no else since NULL above covers it...

    String t2(t);    // what should t2's translation state and case
                     // sensitivity be?

    delete [] t;     // avoid memory leak!
    t = NULL;        // just cleaning up nice...

    return t2;
}

String String::operator+(const char right[]) const
{
    return *this + String(right);
}

String String::operator+(const char right) const
{
    return *this + String(right);
}

String operator+(const char left[], const String & right) // friend?
{
    return String(left) + right;
}

String operator+(const char left, const String & right) // friend?
{
    return String(left) + right;
}

String & String::operator+=(const String & right)
{
    return *this = *this + right;
}

String & String::operator+=(const char right[])
{
    return *this = *this + right;
}

String & String::operator+=(const char right)
{
    return *this = *this + right;
}

String::String(void)
   : string(NULL), length(0),
     translate_position(0), translate_state(String::eosbit),
     flags(String::case_on)
{ }

String::String(const char s[])
   : string(NULL), length(0),
     translate_position(0), translate_state(String::eosbit),
     flags(String::case_on)
{
    if (debug)
    {
        cerr << "Creating String from:  '" << (s==NULL?"":s) << '\'' << endl;
    }
    alloc_val(s==NULL?0:strlen(s));  // strlen crashes on NULL!!!
    copy_val(s);
    clear();
    seekg();
    clear((string==NULL)?eosbit:goodbit);
    flags = case_on;

}

String::String(const char ch)
   : string(NULL), length(0),
     translate_position(0), translate_state(String::eosbit),
     flags(String::case_on)
{
    if (debug)
    {
        cerr << "Creating String from:  '" << ch << '\'' << endl;
    }
    alloc_val((ch == EOS) ? (0) : (1));
    copy_val(&ch);
    clear();
    seekg();
    clear((string==NULL)?eosbit:goodbit);
    flags = case_on;

}

String::String(long new_len, const char ch) // default ch = EOS
   : string(NULL), length(0),
     translate_position(0), translate_state(String::eosbit),
     flags(String::case_on)
{
    long i;
    if (debug)
    {
        cerr << "Creating String of " << new_len << " '" << ch << "'s" << endl;
    }
    alloc_val(new_len);
    for (i = 0; i < length; i++)
    {
        string[i] = ch;
    }
    if (string != NULL)
    {
        string[length] = EOS;
    }
    clear();
    seekg();
    clear((string==NULL)?eosbit:goodbit);
    flags = case_on;

}

String::String(const String & other)
   : string(NULL), length(0),
     translate_position(0), translate_state(String::eosbit),
     flags(String::case_on)
{
    if (debug)
    {
        cerr << "Creating String from:  '" << other << '\'' << endl;
    }
    alloc_val(other.length);
    copy_val(other.string);


    // should the flags and translation information
    // be exact or fresh?  you decide!
    //
    // but, probably most people would expect:
    clear();
    seekg(other.translate_position);
    clear(other.translate_state);
    flags = other.flags;
}

void String::alloc_val(long new_len)  // private
{
    if (debug)
    {
        cerr << "allocating String of " << new_len << endl;
#ifndef NOT_UNIX
        struct rusage MemUsed;
        if (getrusage(RUSAGE_SELF, &MemUsed) == 0)
        {
            cerr << "Max Memory:  " << MemUsed.ru_maxrss << endl
                 << "Shared Memory:  " << MemUsed.ru_ixrss << endl
                 << "Data Memory:  " << MemUsed.ru_idrss << endl
                 << "Stack Memory:  " << MemUsed.ru_isrss << endl << endl;
        }
        else
        {
#endif
            cerr << "Unable to report memory statistics...\n" << endl;
#ifndef NOT_UNIX
        }
#endif
    }
    if (new_len > 0)
    {
        string = new char [new_len+1];
        length = (string != NULL) ? (new_len) : (0);
    }
    else
    {
        string = NULL;
        length = 0;
    }
    return;
}

void String::copy_val(const char s[])  // private
{
    long i;
    if ((s != NULL) && (string != NULL))
    {
        strncpy(string, s, length);
        string[length] = EOS;
    }
    else if (string != NULL)
    {
        for (i = 0; i <= length; i++)
        {
            string[i] = EOS;
        }
    }
    return;
}

String::~String(void)
{
    destroy();
}

void String::destroy(void) // private
{
    if (debug)
    {
        cerr << "destroying String:  '" << *this << "' (" << length << ')'
             << endl;
#ifndef NOT_UNIX
        struct rusage MemUsed;
        if (getrusage(RUSAGE_SELF, &MemUsed) == 0)
        {
            cerr << "Max Memory:  " << MemUsed.ru_maxrss << endl
                 << "Shared Memory:  " << MemUsed.ru_ixrss << endl
                 << "Data Memory:  " << MemUsed.ru_idrss << endl
                 << "Stack Memory:  " << MemUsed.ru_isrss << endl << endl;
        }
        else
        {
#endif
            cerr << "Unable to report memory statistics...\n" << endl;
#ifndef NOT_UNIX
        }
#endif
    }
    delete [] string;
    string = NULL;
    length = 0;
    clear();
    seekg();
    clear(eosbit);
    flags = case_on;

    return;
}

String & String::operator=(const String & right)
{
    if (this != &right)
    {
        destroy();
        alloc_val(right.length);
        copy_val(right.string);


        // should the flags and translation information
        // be exact or fresh?  YOU decide!
        // (should you decide the same for here and
        //  copy construction?)
        //
        // but, probably most people would expect:
        seekg(right.translate_position);
        clear(right.translate_state);
        flags = right.flags;
    }
    return *this;
}

String & String::operator=(const char right[])
{
    destroy();
    alloc_val(right==NULL?0:strlen(right));  // strlen crashes on NULL!!!
    copy_val(right);
    return *this;
}

String & String::operator=(const char right)
{
    destroy();
    alloc_val((right==EOS)?0:1);
    copy_val(&right);
    return *this;
}

// What happened to the case sensitivity flag?!  EEK!
long String::operator^(const char find_me) const
{
    return (string == NULL) ? ((find_me == EOS) ? 0 : -1)
                            : ::find(string,find_me);   // calls strextra
                                                        // function
                                                        // (not String::find)
}

long String::operator^(const char find_me[]) const
{
    return (string == NULL)
              ? ((find_me == NULL || find_me[0] == EOS) ? 0 : -1)
              : ((find_me == NULL) ? 0
                                   : ::find(string,find_me));
}

long String::operator^(const String & find_me) const
{
    return (string == NULL)
              ? ((find_me.string == NULL) ? 0 : -1)
              : ((find_me.string == NULL) ? 0
                                          : ::find(string,find_me.string));
}

long operator^(const char find_in, const String & find_me)
{
    return (find_me.string == NULL) ? ((find_in == EOS) ? 0 : -1)
                           : ((find_me.length > 1) ? -1 :
                              ((find_me.string[0] == find_in) ? 0 : -1));
}

long operator^(const char find_in[], const String & find_me)
{
    return (find_in == NULL || find_in[0] == EOS)
              ? ((find_me.string == NULL) ? 0 : -1)
              : ((find_me.string == NULL) ? 0
                                   : ::find(find_in,find_me.string));
}

long String::find(const String & find_me, long start_looking) const
{
    return (string == NULL)
              ? ((find_me.string == NULL) ? 0 : -1)
              : ((find_me.string == NULL) ? 0
                                          : ::find(string,
                                                   find_me.string,
                                                   start_looking));
}

long String::find(const char find_me[], long start_looking) const
{
    return (string == NULL)
              ? ((find_me == NULL || find_me[0] == EOS) ? 0 : -1)
              : ((find_me == NULL) ? 0
                                   : ::find(string, find_me,
                                            start_looking));
}

long String::find(const char find_me, long start_looking) const
{
    return (string == NULL)
              ? ((find_me == EOS) ? 0 : -1)
              : ::find(string, find_me, start_looking);
}

char * String::new_and_cat(char * &old, const char block[], // private
                           long &had, long just_read)       // static helper
{
    char * dyn = old;
    if (just_read > 0)          // there is something new to add
    {
        dyn = new char [had+just_read+1];
        if (dyn != NULL)             // successful allocation
        {
            if (old != NULL)         // we had old stuff
            {
                strcpy(dyn,old);
                delete [] old;
                old = NULL;
            }
            else                     // nothing before
            {
                dyn[0] = EOS;
            }
            strcat(dyn,block);       // add on new stuff
            had += just_read;
        }
    }
    return dyn;
}

long String::getline(istream &strm)
{
    const long MAX = 400;
    long had;
    char * old_dyn;
    char block[MAX];

    old_dyn = NULL;
    had = 0;

// loop to get full blocks
    while (strm.getline(block,MAX).fail())    // getline sets fail when
                                              // it doesn't extract '\n'


    {
        strm.clear();
        old_dyn = new_and_cat(old_dyn, block, had, strm.gcount());
                                            // gcount works for unformatted
                                            // input only (like getline)
    }

// process any final incomplete block
    old_dyn = new_and_cat(old_dyn, block, had,
                          strm.gcount()+(strm.eof()?0:-1));
                                            // -1 to not include '\n' which
                                            // getline removed but did not
                                            // store; not when eof in line!

    destroy();
    string = old_dyn;
    length = had;

    clear(string==NULL ? eosbit : goodbit);

    return length;
}

istream & operator >>(istream & strm, String & me)
{
    const long MAX = 400;
    long had, read;
    char * old_dyn;
    char block[MAX];

    old_dyn = NULL;
    had = 0;

// loop to get full blocks
    strm >> setw(MAX) >> block;
    while ((read = strlen(block)) == (MAX-1))    // can't use gcount
                                                 // since >> isn't 'formatted'


    {
        old_dyn = String::new_and_cat(old_dyn, block, had, read);
        strm >> setw(MAX) >> block;
    }

// process any final incomplete block
    old_dyn = String::new_and_cat(old_dyn, block, had, read);

    me.destroy();
    me.string = old_dyn;
    me.length = had;
    me.clear(me.string==NULL ? String::eosbit : String::goodbit);

    return strm;
}

long String::size(void) const
{
    return length;
}

bool String::operator!(void) const
{
    return (string == NULL);
}

bool String::good(void) const
{
    return (translate_state & goodbit) != 0;
}

bool String::fail(void) const
{
    return (translate_state & failbit) != 0;
}

bool String::eos(void) const
{
    return (translate_state & eosbit) != 0;
}


void String::skipws(void) const
{
    while (good() && isspace(string[translate_position]))
    {
        translate_position++;
    }
    return;
}

long String::clear(long new_state) const // default state = goodbit
{
    long hold = translate_state;
    translate_state = new_state;
    return hold;
}

long String::seekg(long new_position) const // default pos = 0
{
    long hold = translate_position;
    if (good() && (new_position <= length))
    {
        translate_position = new_position;
    }
    return hold;
}

long String::tellg(void) const
{
    return translate_position;
}

long String::setf(long new_flags) const
{
    long hold = flags;
    flags |= new_flags;    // bit-wise or with assign
    return hold;
}

long String::unsetf(long drop_flags) const
{
    long hold = flags;
    flags ^= drop_flags;    // bit-wise xor with assign
                            // actually toggles...should we
                            // do the &= ~ version?
    //flags &= ~drop_flags;  // bit-wise and with assign to
                           // 1's complement of flags to remove
    return hold;
}

bool String::case_sensitive(void) const
{
    return (flags & case_on) != 0;   // bit-wise and
}

ostream & operator<<(ostream & out,
                     const String & other) // friend?
{
    long i, wide, shorter;
    if (other.length > 0)
    {
        wide = out.width(0);
        if (wide != 0)
        {
            shorter = min(wide,other.length);
            if (((out.flags() & ios::adjustfield) != ios::left) &&
                (shorter < wide))
            {
                out << setw(wide-shorter) << "";
            }
            for (i = 0; i < shorter; i++)
            {
                out << other.string[i];
            }
            if (((out.flags() & ios::adjustfield) == ios::left) &&
                (shorter < wide))
            {
                out << setw(wide-shorter) << "";
            }
        }
        else
        {
            out << other.string;
        }
    }
    return out;
}

char & String::operator[](long index)
{
    static char error;
    error = EOS;
    return ((index >= 0) && (index < length))
               ? (string[index])
               : (error);
}

char String::operator[](long index) const
{
    return ((index >= 0) && (index < length))
               ? (string[index])
               : (EOS);
}

// not a great idea, but it needs to happen...
const char * String::Cstring(void) const
{
    return string;
}

const String & String::operator>>(long & data) const
{
    long remember_position;
    skipws();
    remember_position = translate_position;
    if (good())
    {
        str_to_long(string, data, translate_position);
        clear((translate_position==remember_position)
                  ?(failbit)
                  :((translate_position > length)
                      ?(eosbit)
                      :(goodbit)));
    }
    return *this;
}

const String & String::operator>>(short & data) const
{
    long remember_position, test_data;
    skipws();
    remember_position = translate_position;
    *this >> test_data;
    if (good())
    {
        if (test_data > SHRT_MAX || test_data < SHRT_MIN)
        {
            seekg(remember_position);
            clear(failbit);
        }
        else
        {
            data = test_data;
        }
    }
    return *this;
}

const String & String::operator>>(double & data) const
{
    long remember_position;
    skipws();
    remember_position = translate_position;
    if (good())
    {
        str_to_double(string, data, translate_position);
        clear((translate_position==remember_position)
                  ?(failbit)
                  :((translate_position > length)
                      ?(eosbit)
                      :(goodbit)));
    }
    return *this;
}

const String & String::operator>>(float & data) const
{
    long remember_position, test_data;
    skipws();
    remember_position = translate_position;
    *this >> test_data;
    if (good())
    {
        if (test_data > FLT_MAX || test_data < -FLT_MAX)
        {
            seekg(remember_position);
            clear(failbit);
        }
        else
        {
            data = test_data;
        }
    }
    return *this;
}

const String & String::operator>>(char & data) const
{
    if (good())
    {
        skipws();
        data = string[translate_position++];
        clear((translate_position > length) ? (eosbit) : (goodbit));
    }
    return *this;
}


const String & String::operator>>(String & data) const
{
    long remember_position;
    if (good())
    {
        skipws();
        remember_position = translate_position;
        while (!isspace(string[translate_position]) &&
               (string[translate_position] != EOS))
        {
            translate_position++;
        }
        data.destroy();
        data.alloc_val(translate_position-remember_position);
        data.copy_val(string+remember_position);
        data.clear((data.string==NULL) ? (eosbit) : (goodbit));
        clear((translate_position > length) ? (eosbit) : (goodbit));
    }
    return *this;
}





long String::getline(String & data,
                     const String & stop_at_any) const // defaults to '\n'
{
    long remember_position = translate_position;
    if (good())
    {                          // note this use of our find operator
        while (((string[translate_position] ^ stop_at_any) == -1) &&
               (string[translate_position] != EOS))
        {
            translate_position++;
        }
        data.destroy();
        data.alloc_val(translate_position-remember_position);
        data.copy_val(string+remember_position);
        data.clear((data.string==NULL) ? (eosbit) : (goodbit));
        clear((translate_position > length) ? (eosbit) : (goodbit));
    }
    return data.length;
}


const String & String::operator>>(bool & data) const
{
    long remember_position;
    String test_data;
    skipws();
    remember_position = translate_position;
    *this >> test_data;
    if (good())
    {
        if (test_data == "true")
        {
            data = true;
        }
        else if (test_data == "false")
        {
            data = false;
        }
        else
        {
            translate_position = remember_position;
            clear(failbit);
        }
    }
    return *this;
}

void get_line(String & line, istream & in)
{
    if (in.tie() != NULL)
    {
        in.tie()->flush();
    }
    if (in.peek() == '\n')
    {
        in.ignore();
    }
    line.getline(in);
    return;
}

