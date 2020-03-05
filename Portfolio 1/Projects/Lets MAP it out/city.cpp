// Headers
#include "point.h"
#include "city.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Accessors

Point City::get_location() const
{
    return location;
}

string City::get_name() const
{
    return name;
}

double City::get_distance(const City & other) const
{
    return location.distance(other.location);
}

//Mutators

void City::set_location(Point i_loc)
{
    location = i_loc;
}

void City::set_name(string i_name)
{
    name = i_name;
}
