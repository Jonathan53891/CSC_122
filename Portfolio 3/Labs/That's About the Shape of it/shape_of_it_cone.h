#ifndef SHAPE_OF_IT_CONE_H
#define SHAPE_OF_IT_CONE_H
#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_threeD.h"
class Cone :public ThreeD
{
    double height, radius;
public:
    Cone(std::string i_name, Point i_p, double i_height, double i_radius) :
        ThreeD(i_name, i_p), height(i_height), radius(i_radius) {}
    virtual ~Cone() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point: " << get_pointp() << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Radius: " << radius << std::endl;
    }
};

#endif

