#ifndef CUBE_H
#define CUBE_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
#include "ThreeD.h"
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
