#ifndef SHAPE_OF_IT_TWOD_H
#define SHAPE_OF_IT_TWOD_H

#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
class TwoD :public Shape
{
public:
    TwoD(std::string i_name, Point i_p) :
        Shape(i_name, i_p) {}
    virtual ~TwoD() {}
    virtual void print(std::ostream & out) const = 0;
};

#endif
