#ifndef SHAPE_OF_IT_CURVE_H
#define SHAPE_OF_IT_CURVE_H

#include <iostream>
#include <string>
#include "shape_of_it_point.h"
#include "shape_of_it_shape.h"
#include "shape_of_it_oneD.h"
#include <vector>
class Curve :public OneD
{
    std::vector<Point> points;
public:
    Curve(std::string i_name, Point i_p, Point i_q,
        std::vector<Point> i_points) : OneD(i_name, i_p, i_q), points()
    {
        points.push_back(i_p);
        points.push_back(i_q);
        points.insert(points.end(), i_points.begin(), i_points.end());
    }
    virtual ~Curve() {}
    void print(std::ostream & out) const
    {
        std::cout << "Name: " << get_name() << std::endl;
        typedef std::vector<Point>::size_type vecpt_sizet;
        for (vecpt_sizet pos = 0; pos < points.size(); pos++)
        {
            std::cout << "Point " << pos + 1 << ": ";
            points[pos].Output();
            std::cout << std::endl;
        }
    }
};

#endif
