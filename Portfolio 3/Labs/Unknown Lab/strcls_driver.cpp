#include <iostream>

#include "menu.h"

//uncomment this to fix gcount problems on the HP box
#define HPUX_CRAP

#include "strcls.h"

// could do this to turn on memory debugging in the String class
// bool String::debug = true;

using namespace std;

bool process_main(short choice);
// still left to test:
//    operator!
//    translation functions:  good, eos, fail, tellg, seekg, skipws, clear,
//                            operatror>> (long, short, ...), getline(String)
//    operator[]
//    case_sensitive()
//
// suggested to be tested in:
//    construction test
//    new submenu
//    assignment or comparison (both?)
//    comparison
//
int main(void)
{
    do_menu("\n   Main Menu\n\n"
            "1) Construction\n"
            "2) Destruction\n"
            "3) Assignment\n"
            "4) coMparison\n"
            "5) concaTenation\n"
            "6) Searching\n"
            "7) Quit\n\n"
            "Choice:  ",
            "1Cc2Dd3Aa4Mm5Tt6Ss7Qq",
            process_main);
    return 0;
}

bool process_constr(short choice);
bool process_asgn(short choice);
bool process_concat(short choice);
bool process_find(short choice);

#ifndef VISUAL_CRAP
bool process_compar(short choice);
#endif

bool process_main(short choice)
{
    bool quit = false;
    switch (choice)
    {
        case 1:
        {
            do_menu("\n   Construction Menu\n\n"
                    "1) Default construction\n"
                    "2) init from Long\n"
                    "3) init from Char\n"
                    "4) init from Null-terminated string\n"
                    "5) copy from String object\n"
                    "6) return to Main Menu\n\n"
                    "Choice:  ",
                    "1Dd2Ll3Cc4Nn5Ss6Mm",
                    process_constr);
        } break;
        case 2:
        {
            String::debug = !String::debug;
            cout << "\n\nMemory checking is now "
                 << (String::debug ? "on" : "off")
                 << "!\n" << endl;
        } break;
        case 3:
        {
            do_menu("\n   Assignment Menu\n\n"
                    "1) assign from Char\n"
                    "2) assign from Null-terminated string\n"
                    "3) assign from String object\n"
                    "4) return to Main Menu\n\n"
                    "Choice:  ",
                    "1Cc2Nn3Ss4Mm",
                    process_asgn);
        } break;
        case 4:
        {
#ifndef VISUAL_CRAP
            do_menu("\n   Comparison Menu\n\n"
                    "1) chanGe case sensitivity\n"
                    "2) compare to Char\n"
                    "3) compare to Null-terminated string\n"
                    "4) compare to String object\n"
                    "5) return to Main Menu\n\n"
                    "Choice:  ",
                    "1Gg2Cc3Nn4Ss5Mm",
                    process_compar);
#else
            cout << "Unable to compile the simple comparison "
                    "templates in Visual C++ (6.0)."
                 << endl;
#endif
        } break;
        case 5:
        {
            do_menu("\n   Concatenation Menu\n\n"
                    "1) concat in Front\n"
                    "2) concat Behind\n"
                    "3) concat with Assign\n"
                    "4) return to Main Menu\n\n"
                    "Choice:  ",
                    "1Ff2Bb3Aa4Mm",
                    process_concat);
        } break;
        case 6:
        {
            do_menu("\n   Searching Menu\n\n"
                    "1) find a Char\n"
                    "2) find a Null-terminated string\n"
                    "3) find a String object\n"
                    "4) return to Main Menu\n\n"
                    "Choice:  ",
                    "1Cc2Nn3Ss4Mm",
                    process_find);
        } break;
        case 7:
        {
            cout << "\n\nThanks for testing the String class!\n\n"
                    "Have a nice day!\n"
                 << endl;
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}

bool process_constr(short choice)
{
    bool quit = false;
    switch (choice)
    {
        case 1:
        {
            String x;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 2:
        {
            long s;
            char c;
            cout << "Enter length for string:  ";
            cin >> s;
            if (yesno("Would you like a particular character?  "))
            {
                cout << "Enter your character:  ";
                cin.ignore();  // ignore newline from length
                cin.get(c);
            }
            else
            {
                c = '\0';   // not really using default arg, but okay...
            }
            String x(s,c);
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 3:
        {
            char c;
            cout << "Enter your character:  ";
            cin.ignore();  // ignore newline from menu choice
            cin.get(c);
            String x(c);
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 4:
        {
            char s[5000];
            cout << "Enter your Cstring:  ";
            get_line(s, 5000, cin);
            String x(s);
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 5:
        {
            String o;
            cout << "Enter your String:  ";
            get_line(o);
            String x(o);
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 6:
        {
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}

bool process_asgn(short choice)
{
    bool quit = false;
    switch (choice)
    {
        case 1:
        {
            char c;
            cout << "Enter your character:  ";
            cin.ignore();  // ignore newline from menu choice
            cin.get(c);
            String x;
            x = c;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
            x = x;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 2:
        {
            char s[5000];
            cout << "Enter your Cstring:  ";
            get_line(s, 5000, cin);
            String x;
            x = s;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
            x = x;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 3:
        {
            String o;
            cout << "Enter your String:  ";
            get_line(o);
            String x;
            x = o;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
            cout << "\nSelf assignment:\n\n";
            x = x;
            cout << "string contains '" << x << "' and is "
                 << x.size() << " characters long." << endl;
        } break;
        case 4:
        {
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}

#ifndef VISUAL_CRAP
template <typename One, typename Other>
bool JJnotequal(const One & x, const Other & o)
{
    return x != o;
}

template <typename One, typename Other>
bool JJequal(const One & x, const Other & o)
{
    return x == o;
}

template <typename One, typename Other>
bool JJless(const One & x, const Other & o)
{
    return x < o;
}

template <typename One, typename Other>
bool JJgreater(const One & x, const Other & o)
{
    return x > o;
}

template <typename One, typename Other>
bool JJlessequal(const One & x, const Other & o)
{
    return x <= o;
}

template <typename One, typename Other>
bool JJgreaterequal(const One & x, const Other & o)
{
    return x >= o;
}

template <typename One, typename Other, typename CompFnc>
void compare_one(const One & x, const Other & o, CompFnc comp,
                 const char true_msg[], const char false_msg[])
{
    cout << (comp(x, o) ? true_msg : false_msg) << endl;
    return;
}

template <typename CompA, typename CompB>
void run_compare(const CompA & a, const CompB & b)
{
    cout << a << " compared to " << b << ':' << endl;
    compare_one(a, b, JJequal<CompA,CompB>, "They're equal!",
                "They're NOT equal!");
    compare_one(a, b, JJnotequal<CompA,CompB>, "They're NOT equal!",
                "They're NOT NOT equal!");
    compare_one(a, b, JJless<CompA,CompB>, "They're less!",
                "They're NOT less!");
    compare_one(a, b, JJlessequal<CompA,CompB>,
                "They're less or equal!",
                "They're NOT less or equal!");
    compare_one(a, b, JJgreater<CompA,CompB>, "They're greater!",
                "They're NOT greater!");
    compare_one(a, b, JJgreaterequal<CompA,CompB>,
                "They're greater or equal!",
                "They're NOT greater or equal!");
    return;
}

template <typename CompTo, typename ReadFnc>
void compare_to(CompTo & c, const char desc[], ReadFnc read_with, bool Case)
{
    String x;
    cout << "Enter your " << desc << ":  ";
    read_with(c);
    cout << "Enter your String:  ";
    get_line(x);
    if (Case)
    {
        x.setf(String::case_on);
    }
    else
    {
        x.unsetf(String::case_on);
    }
    cout << "\nThey compare as:  " << x.compare(c) << '.' << endl;
    run_compare(x,c);
    cout << '\n';
    run_compare(c,x);
    return;
}

// one to read next character...another to skip preceeding newlines
void read_ch_nl(char & ch)
{
    cin.ignore();
    cin.get(ch);
    return;
}

void read_ch(char & ch)
{
    cin.get(ch);
    return;
}

void read_str(char str[5000])
{
    get_line(str, 5000, cin);
    return;
}

// had to make this since the overloaded get_line confused
// template instantiation!
void read_Str(String & Str)
{
    get_line(Str);
    return;
}

bool process_compar(short choice)
{
    bool quit = false;
    static bool Case = true;
    switch (choice)
    {
        case 1:
        {
            Case = !Case;
            cout << "Case is now " << (Case ? "on" : "off") << '.' << endl;
        } break;
        case 2:
        {
            char c;
            compare_to(c, "character", read_ch_nl, Case);
        } break;
        case 3:
        {
            char c[5000];
            compare_to(c, "Cstring", read_str, Case);
        } break;
        case 4:
        {
            String c;
            compare_to(c, "String", read_Str, Case);
        } break;
        case 5:
        {
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}
#endif

bool process_concat(short choice)
{
    bool quit = false;
    char c, s[5000];
    String x;
    switch (choice)
    {
        case 1:
        {
            cout << "Enter your String:  ";
            get_line(x);
            cout << "Enter your Cstring:  ";
            get_line(s, 5000, cin);
            cout << "Enter your character:  ";
            cin.get(c);
            cout << c << " + " << x << " = " << (c+x) << endl;
            cout << s << " + " << x << " = " << (s+x) << endl;
            cout << x << " + " << x << " = " << (x+x) << endl;
        } break;
        case 2:
        {
            cout << "Enter your String:  ";
            get_line(x);
            cout << "Enter your Cstring:  ";
            get_line(s, 5000, cin);
            cout << "Enter your character:  ";
            cin.get(c);
            cout << x << " + " << c << " = " << (x+c) << endl;
            cout << x << " + " << s << " = " << (x+s) << endl;
            cout << x << " + " << x << " = " << (x+x) << endl;
        } break;
        case 3:
        {
            cout << "Enter your String:  ";
            get_line(x);
            cout << "Enter your Cstring:  ";
            get_line(s, 5000, cin);
            cout << "Enter your character:  ";
            cin.get(c);
            cout << x << " += " << c << " == ";
            cout << (x+=c) << endl;
            cout << x << " += " << s << " == ";
            cout << (x+=s) << endl;
            cout << x << " += " << x << " == ";
            cout << (x+=x) << endl;
        } break;
        case 4:
        {
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}

template <typename FindInType, typename FindThisType>
void do_find(const FindInType & x, const FindThisType & y)
{
    long at, from;
    at = x^y;
    if (at == -1)
    {
        cout << "Could not find " << y << " in " << x << '.' << endl;
    }
    else
    {
        cout << "Found " << y << " at position " << at
             << " in " << x << '.' << endl;
        cout << "Enter new position to search from:  ";
        cin >> from;
        while ((at = String(x).find(y,from)) != -1)
        {
            cout << "Found " << y << " at position " << at
                 << " in " << x << '.' << endl;
            cout << "Enter new position to search from:  ";
            cin >> from;
        }
    }
    return;
}

template <typename FindType, typename ReadFnc>
void find_a(FindType & y, const char desc[], ReadFnc read_fnc)
{
    String x;
    cout << "Enter your String:  ";
    get_line(x);
    cout << "Enter a " << desc << ":  ";
    read_fnc(y);
    cout << "\nFinding forwards:" << endl;
    do_find(x,y);
    cout << "\nFinding backwards:" << endl;
    do_find(y,x);
    return;
}

bool process_find(short choice)
{
    bool quit = false;
    char c, s[5000];
    String x;
    switch (choice)
    {
        case 1:
        {
            find_a(c,"character", read_ch);
        } break;
        case 2:
        {
            find_a(s,"Cstring", read_str);
        } break;
        case 3:
        {
            find_a(x,"String", read_Str);
        } break;
        case 4:
        {
            quit = true;
        } break;
        default:
        {
            cout << "\n\aInvalid choice!  Please try again!\n"
                 << endl;
        } break;
    }
    return quit;
}
