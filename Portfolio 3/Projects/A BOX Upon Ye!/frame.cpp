#include "frame.h"
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

ostream& operator<<(ostream& out, const Frame& f) // output overload operator
{
    typedef std::vector<std::string>::size_type vct_str_type;
    typedef std::string::size_type str_type;
    //middle of frame
    vct_str_type height = f.word_list.size();
    str_type width = 0;
    for (vct_str_type pos = 0; pos < height; pos++) //finds width of frame 
    {
        str_type tmp_width = f.word_list[pos].length();
        if (tmp_width > width)
        {
            width = tmp_width;
        }
    }
    switch (f.style)
    {
    case '0': //use character
    {

        if (f.align == 'L') // Left align
        {
            out << string(width + 4, f.frame_ch) << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << f.frame_ch << ' ' << setw(width)<<left << f.word_list[i];
                out << ' ' << f.frame_ch << endl;
            }
            out << string(width + 4, f.frame_ch) << endl;
        }
        else if (f.align == 'C') // Center allign
        {
            out << string(width + 4, f.frame_ch) << endl;
            size_t padding_L, padding_R;
            for (str_type i = 0; i < height; i++)
            {
                //calculation for centering
                size_t word_length = f.word_list[i].length();
                padding_L = (width - word_length) / 2;
                padding_R = width - word_length - padding_L;
                out << f.frame_ch << ' ' << string(padding_L, ' ');
                out << f.word_list[i] << string(padding_R, ' ');
                out << ' ' << f.frame_ch << endl;
            }
            out << string(width + 4, f.frame_ch) << endl;
        }
        else if (f.align == 'R') //right align
        {
            out << string(width + 4, f.frame_ch) << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << f.frame_ch << ' ' << setw(width) << right << f.word_list[i];
                out << ' ' << f.frame_ch << endl;
            }
            out << string(width + 4, f.frame_ch) << endl;
        }
        else //error
        {
            cerr << "Error: invalid option for alignment." << endl;
        }

    }
    break;
    case '1': // Single line
    {
        if (f.align == 'L') //left align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << '|' << ' ' << setw(width) << left << f.word_list[i];
                out << ' ' << '|' << endl;
            }
            out << '+' << string(width + 2, '-') << '+' << endl;

        }
        else if (f.align == 'C') // center align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            size_t padding_L, padding_R, word_length;
            for (str_type i = 0; i < height; i++)
            {
                //calculation for center align
                word_length = f.word_list[i].length();
                padding_L = (width - word_length) / 2;
                padding_R = width - word_length - padding_L;
                out << '|' << ' ' << string(padding_L, ' ');
                out << f.word_list[i] << string(padding_R, ' ');
                out << ' ' << '|' << endl;
            }
            out << '+' << string(width + 2, '-') << '+' << endl;

        }
        if (f.align == 'R') //right align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << '|' << ' ' << setw(width) << right << f.word_list[i];
                out << ' ' << '|' << endl;
            }
            out << '+' << string(width + 2, '-') << '+' << endl;

        }
        else //error
        {
            cerr << "Error: invalid option for alignment." << endl;
        }

    }
    break;
    case '2': // Single line, shaded
    {
        if (f.align == 'L') //left align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << '|' << ' ' << setw(width) << left << f.word_list[i];
                out << ' ' << "|*" << endl;
            }
            out << '+' << string(width + 2, '-') << "+*" << endl;
            out << ' ' << string(width + 4, '*') << endl;

        }
        else if (f.align == 'C') //center align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            size_t padding_L, padding_R, word_length;
            for (str_type i = 0; i < height; i++)
            {
                //center align calculation
                word_length = f.word_list[i].length();
                padding_L = (width - word_length) / 2;
                padding_R = width - word_length - padding_L;
                out << '|' << ' ' << string(padding_L, ' ');
                out << f.word_list[i] << string(padding_R, ' ');
                out << ' ' << "|*" << endl;
            }
            out << '+' << string(width + 2, '-') << '+' << endl;
            out << ' ' << string(width + 4, '*') << endl;

        }
        else if (f.align == 'R') //right align
        {
            out << '+' << string(width + 2, '-') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << '|' << ' ' << setw(width) << right << f.word_list[i];
                out << ' ' << "|*" << endl;
            }
            out << '+' << string(width + 2, '-') << "+*" << endl;
            out << ' ' << string(width + 4, '*') << endl;
        }
        else
        {
            cerr << "Error: invalid option for alignment." << endl;
        }

    }
    break;
    case '3': // Double line
    {
        if (f.align == 'L') //left align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << "||" << ' ' << setw(width) << left << f.word_list[i];
                out << ' ' << "||" << endl;
            }
            out << '+' << string(width + 4, '=') << '+' << endl;

        }
        else if (f.align == 'C') //center align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            size_t padding_L, padding_R, word_length;
            for (str_type i = 0; i < height; i++)
            {
                //calculation for center align
                word_length = f.word_list[i].length();
                padding_L = (width - word_length) / 2;
                padding_R = width - word_length - padding_L;
                out << "||" << ' ' << string(padding_L, ' ');
                out << f.word_list[i] << string(padding_R, ' ');
                out << ' ' << "||" << endl;
            }
            out << '+' << string(width + 4, '=') << '+' << endl;

        }
        else if (f.align == 'R') //right align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << "||" << ' ' << setw(width) << right << f.word_list[i];
                out << ' ' << "||" << endl;
            }
            out << '+' << string(width + 4, '=') << '+' << endl;
        }

    }
    break;
    case '4': // Double line, shaded
    {
        if (f.align == 'L') //left align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << "||" << ' ' << setw(width) << left << f.word_list[i];
                out << ' ' << "||#" << endl;
            }
            out << '+' << string(width + 4, '=') << "+#" << endl;
            out << ' ' << string(width + 6, '#');

        }
        else if (f.align == 'C') // center align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            size_t padding_L, padding_R, word_length;
            for (str_type i = 0; i < height; i++)
            {
                //calculation for center align
                word_length = f.word_list[i].length();
                padding_L = (width - word_length) / 2;
                padding_R = width - word_length - padding_L;
                out << "||" << ' ' << string(padding_L, ' ');
                out << f.word_list[i] << string(padding_R, ' ');
                out << ' ' << "||#" << endl;
            }
            out << '+' << string(width + 4, '=') << "+#" << endl;
            out << ' ' << string(width + 6, '#');

        }
        else if (f.align == 'R') //right align
        {
            out << '+' << string(width + 4, '=') << '+' << endl;
            for (str_type i = 0; i < height; i++)
            {
                out << "||" << ' ' << setw(width) << right << f.word_list[i];
                out << ' ' << "||#" << endl;
            }
            out << '+' << string(width + 4, '=') << "+#" << endl;
            out << ' ' << string(width + 6, '#');
        }

    }
    break;
    default:
    {
        cerr << "Error: invalid option for style." << endl;
    }
    }

    return out;
}

//inputs phrase
istream& operator>>(istream& in, Frame& f) 
{
    bool get_first = false;
    char first;
    while (!get_first) // ignores garbage input until 
    {
        in >> first;
        if (first == '"')
        {
            get_first = true;
        }
    }
    bool done = false;
    string str_tmp;
    char char_tmp;
    while (!done) // vector input
    {
        if (in.peek() == ' ') // finds space
        {
            in >> char_tmp; // takes in last letter before space
            if (!str_tmp.empty()) // something in string
            {
                f.word_list.push_back(str_tmp);
                str_tmp = char_tmp;
            }
        }
        else if (in.peek() == '\"') // Finds end of parenthesis
        {
            in >> char_tmp; //gobble quotes
            if (!str_tmp.empty()) // something in string
            {
                f.word_list.push_back(str_tmp);
                str_tmp = "";
            }
            done = true;
        }
        else //finds character that is not space or "
        {
            in >> char_tmp; // ins char
            str_tmp = str_tmp + char_tmp;
        }
    }
    
    return in;
}
