#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED

// A 2D point class
class Point
{
    double x, // x coordinate of point
           y; // y coordinate of point

public:
    Point(void) :x(0), y(0) {}
    Point(double new_x, double new_y):x(new_x), y(new_y) {}
    Point(const Point & p): x(p.x), y(p.y) {}

    void Output(void) const;   // output this point
    void Input(void);          // input this point

    // distance between this point and other
    double distance(const Point & other) const;
    // point in middle of this point and other
    Point midpoint(const Point & other) const;

    double get_x(void) const { return x; }  // accessors
    double get_y(void) const { return y; }

    void set_x(double new_x);               // mutators
    void set_y(double new_y);

    Point flip_x(void) const; // new point is this one flipped
    Point flip_y(void) const; // about specified axis

    Point shift_x(double move_by) const;  // new point is this one
    Point shift_y(double move_by) const;  // shifted move_by in the
                                          // specified direction
};

#endif
