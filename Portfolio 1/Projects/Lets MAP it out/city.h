#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <string>
#include "point.h"


// A 2D point class

class City 
{
    Point location;
    std::string name;
public:

    // Constructors

    City() : location(), name() {}
    City(Point i_loc) : location(i_loc), name() {}
    City(std::string i_name) : location(), name(i_name) {}
    City(Point i_loc, std::string i_name) : location(i_loc), name(i_name) {}

    // Accessors
    Point get_location() const;
    std::string get_name() const;
    double get_distance(const City & other) const;
    void display_city_info();

    // Mutators
    void set_location(Point i_loc);
    void set_name(std::string i_name);
};
#endif // CITY_H_INCLUDED
