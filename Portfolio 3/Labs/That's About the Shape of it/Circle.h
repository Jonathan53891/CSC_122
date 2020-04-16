#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
#include "TwoD.h"
class Circle :public TwoD
{
    double radius;
public:
    Circle(std::string i_name, Point i_p, double i_radius) :
        TwoD(i_name, i_p), radius(i_radius) {}
    virtual ~Circle() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point: " << get_pointp() << std::endl;
        std::cout << "Radius: " << radius << std::endl;
    }
};

#endif
