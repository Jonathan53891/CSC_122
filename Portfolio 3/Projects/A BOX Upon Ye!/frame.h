#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <iostream>
#include <vector>

class Frame
{

    std::vector<std::string> word_list;
    char frame_ch;
    char style;// 0=shaded, 1 = single, 2 = double
    char align; // L= Left, C = Center, R = Right
public:
    Frame() : frame_ch('|'), style(1), align('L') {}
    void print_word_list() const
    {
        typedef std::vector<std::string>::size_type vct_str_type;
        for (vct_str_type pos = 0; pos < word_list.size(); pos++)
        {
            std::cout << word_list[pos] << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Frame& f);
    friend std::istream& operator>>(std::istream& in, Frame& f);
    void input_config(std::istream& in)
    {
        in >> frame_ch >> style >> align;
    }
    void output_config(std::ostream& out)
    {
        out << frame_ch << std::endl <<style << std::endl << align << std::endl;
    }

};

#endif
