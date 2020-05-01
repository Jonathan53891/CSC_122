#ifndef SHAPE_OF_IT_CUBE_H
#define SHAPE_OF_IT_CUBE_H

#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_threeD.h"
class Cube :public ThreeD
{
    double width;
public:
    Cube(std::string i_name, Point i_p, double i_width) :
        ThreeD(i_name, i_p), width(i_width) {}
    virtual ~Cube() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point: " << get_pointp() << std::endl;
        std::cout << "Width: " << width << std::endl;
    }
};

#endif
