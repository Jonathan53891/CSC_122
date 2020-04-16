#ifndef SHAPE_OF_IT_SPHERE_H
#define SHAPE_OF_IT_SPHERE_H
#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_threeD.h"
class Sphere :public ThreeD
{
    double radius;
public:
    Sphere(std::string i_name, Point i_p, double i_radius) :
        ThreeD(i_name, i_p), radius(i_radius) {}
    virtual ~Sphere() {}
    virtual void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        std::cout << "Point: " << get_pointp() << std::endl;
        std::cout << "radius: " << radius << std::endl;
    }
};

#endif
