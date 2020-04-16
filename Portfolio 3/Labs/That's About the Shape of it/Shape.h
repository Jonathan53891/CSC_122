#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include "point.h"
class Shape
{
private:
    std::string name;
    Point p;
public:
    Shape(std::string i_name, Point i_p) : name(i_name), p(i_p) {}
    virtual ~Shape() {}
    virtual void print(std::ostream & out) const = 0;
    std::string get_name() const { return name; }
    Point get_pointp() const { return p; }
};

#endif
