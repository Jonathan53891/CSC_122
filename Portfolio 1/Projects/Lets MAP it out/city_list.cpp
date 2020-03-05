#include "city_list.h"
#include "city.h"
#include <iostream>

using namespace std;

City City_list::get_city(vector<City>::size_type index) const
{
    return city_list[index];
}

void City_list::list_cities(const string & error) const
{
    if (city_list.size() > 0) // checks to see list is not empty
    {
        for (vector<City>::size_type pos = 0; pos < city_list.size(); pos++)
        {
            cout << pos + 1 << ": ";
            cout << get_city(pos).get_name() << " at ";
            (city_list[pos].get_location()).Output();
            cout << ".\n";
        }
    }
    else // List is empty
    {
        cerr << error << endl;
    }
}

void City_list::set_city(vector<City>::size_type index, const City & new_city)
{
    city_list[index] = new_city;
}

bool City_list::add_city(const City & new_city)
{
    bool added;
    if (city_list.size() < MAX_CITIES)
    {
        city_list.push_back(new_city);
        added = true;
    }
    else
    {
        added = false;
    }
    return added;
}

vector<City>::size_type City_list::get_list_length() const
{
    return city_list.size();
}
