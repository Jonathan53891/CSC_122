#include "city_point.h"
#include <iostream>
#include <cmath>

using namespace std;

// read standard 2D point notation (x,y) -- ignore
// window dressing

void Point::Input(void)
{
    char dummy;
    cin >> dummy >> x >> dummy >> y >> dummy;
    return;
}

// output standard 2D point notation (x,y)

void Point::Output(void) const
{
    cout << '(' << x << ", " << y << ')';
    return;
}

// calculate distance between two 2D points --
// the one that called us and the argument

double Point::distance(const Point & other) const
{
    return sqrt(pow(x - other.x, 2.0) +
            pow(other.y - y, 2.0));
}

// calculate midpoint between two 2D points --
// the one that called us and the argument

Point Point::midpoint(const Point & other) const
{
    return Point((x + other.x) / 2.0, (other.y + y) / 2.0);
}

// set coordinates to programmer-specified values

void Point::set_x(double new_x)
{
    x = new_x; // no error checking since anything is legal
    return;
}

// set coordinates to programmer-specified values

void Point::set_y(double new_y)
{
    y = new_y; // no error checking since anything is legal
    return;
}

// creates a point flipped about the x axis from us

Point Point::flip_x(void) const
{
    return Point(x, -y);
}

// creates a point flipped about the y axis from us

Point Point::flip_y(void) const
{
    return Point(-x, y);
}

// creates a point shifted along the x axis from us

Point Point::shift_x(double move_by) const
{
    return Point(x + move_by, y);
}

// creates a point shifted along the y axis from us

Point Point::shift_y(double move_by) const
{
    return Point(x, y + move_by);
}
