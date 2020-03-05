#ifndef CITY_LIST_H
#define CITY_LIST_H

#include "city.h"
#include <vector>

const short MAX_CITIES = 3;

class City_list 
{
    std::vector<City> city_list;

public:

    //Constructors
    City_list() : city_list() {}

    //Accessors
    void list_cities(const std::string & error) const;
    City get_city(std::vector<City>::size_type index) const;
    std::vector<City>::size_type get_list_length() const;

    //Mutators
    void set_city(std::vector<City>::size_type index, const City & new_city);
    bool add_city(const City & new_city);

};
#endif /* CITY_LIST_H */
