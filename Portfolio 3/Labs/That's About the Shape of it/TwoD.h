#ifndef TWOD_H
#define TWOD_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
class TwoD :public Shape
{
public:
    TwoD(std::string i_name, Point i_p) :
        Shape(i_name, i_p) {}
    virtual ~TwoD() {}
    virtual void print(std::ostream & out) const = 0;
};

#endif
