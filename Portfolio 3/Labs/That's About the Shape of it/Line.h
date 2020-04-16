#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
#include "OneD.h"
class Line :public OneD
{
public:
    Line(std::string i_name, Point i_p, Point i_q) : OneD(i_name, i_p, i_q) {}
    virtual ~Line() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point 1: " << get_pointp() << std::endl;
        std::cout << "Point 2: " << get_pointq() << std::endl;
    }
};

#endif
