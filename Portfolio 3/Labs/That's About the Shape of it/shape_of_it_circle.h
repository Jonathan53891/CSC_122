#ifndef SHAPE_OF_IT_CIRCLE_H
#define SHAPE_OF_IT_CIRCLE_H
#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_twoD.h"
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
