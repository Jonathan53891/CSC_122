#ifndef SHAPE_OF_IT_THREED_H
#define SHAPE_OF_IT_THREED_H
#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
class ThreeD :public Shape
{
public:
    ThreeD(std::string i_name, Point i_p) :
        Shape(i_name, i_p) {}
    virtual ~ThreeD() {}
    virtual void print(std::ostream & out) const = 0;
};

#endif
