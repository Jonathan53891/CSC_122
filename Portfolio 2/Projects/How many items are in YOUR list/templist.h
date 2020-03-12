#ifndef TEMPLIST_H_
#define TEMPLIST_H_

#include <iostream>
using namespace std;

struct TemperatureList{
   public:
       double* list;
       long size;
       long MAX_SIZE;
       TemperatureList(int n);
       void add_temperature(double temperature);
       bool full() const;
       long get_size() const;
       double get_temperature(long position) const;
       void output(ostream &outs) const;
       double get_last() const;
       void detele_last();
};

#endif
