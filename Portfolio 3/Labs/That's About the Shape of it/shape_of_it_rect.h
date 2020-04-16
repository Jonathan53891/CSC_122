#ifndef SHAPE_OF_IT_RECT_H
#define SHAPE_OF_IT_RECT_H
#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_twoD.h"
class Rect :public TwoD
{
    double length, width;
public:
    Rect(std::string i_name, Point i_p, double i_length, double i_width) :
        TwoD(i_name, i_p), length(i_length), width(i_width) {}
    virtual ~Rect() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point: " << get_pointp() << std::endl;
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
    }
};

#endif
