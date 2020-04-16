#ifndef THREED_H
#define THREED_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
class ThreeD :public Shape
{
public:
    ThreeD(std::string i_name, Point i_p) :
        Shape(i_name, i_p) {}
    virtual ~ThreeD() {}
    virtual void print(std::ostream & out) const = 0;
};

#endif
