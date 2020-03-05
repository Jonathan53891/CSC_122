#ifndef PROBLEM_SET_H
#define PROBLEM_SET_H
#include <string>
#include <vector>
#include <cmath>

class Problem_Set 
{
    std::string name;
    std::vector<short> list;
    void Insert_Sort(const short& input);

public:

    Problem_Set() : name(), list() {}
    void Input_List(std::string const& prompt);
    void Output() const;

    short Num_Length(const double input) const // finds "length" of number
    {
        return ((input < 1) ? 1 : log10(input) + 1);
    }

};

#endif /* PROBLEM_SET_H */
