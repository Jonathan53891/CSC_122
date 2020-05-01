#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED

#include <iostream>
// A 2D point class
class Point
{
    double x, // x coordinate of point
        y; // y coordinate of point

public:
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);
    double operator-(const Point & P) const;
    Point operator/(const Point & P) const;
    bool operator ==(const Point & P) const;
    bool operator !=(const Point & P) const;
    double operator[](const char& ch)const;
    Point(void);
    Point(double new_x, double new_y);

    void Output(void) const;   // output this point
    void Input(void);    // input this point
    double distance(Point other);   // distance between this point and other

    double get_x(void) { return x; }
    double get_y(void) { return y; }

    void set_x(double new_x);
    void set_y(double new_y);

    Point flip_x(void);
    Point flip_y(void);

    Point shift_x(double move_by);
    Point shift_y(double move_by);
};

#endif
