#ifndef ONED_H
#define ONED_H
#include <iostream>
#include <string>
#include "point.h"
#include "Shape.h"
class OneD :public Shape
{
    Point q;
public:
    OneD(std::string i_name, Point i_p, Point i_q) : 
        Shape(i_name,i_p), q(i_q) {}
    virtual ~OneD() {}
    virtual void print(std::ostream & out) const = 0;
    Point get_pointq() const { return q; }
};

#endif
