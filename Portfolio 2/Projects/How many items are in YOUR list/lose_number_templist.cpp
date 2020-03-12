#include "templist.h"

TemperatureList::TemperatureList(int n){
   list = new double[n];
   MAX_SIZE = n;
   size = 0;
}

void TemperatureList::add_temperature(double temperature){
   if (full() == false){
       list[size] = temperature;
       size += 1;
   }
}

bool TemperatureList::full() const{
   if (size == MAX_SIZE) return true;
   return false;
}

long TemperatureList::get_size() const{
   return size;
}

double TemperatureList::get_temperature(long position) const{
   if (position >= size || position < 0) return 0.0;
   return list[position];
}

void TemperatureList::output(ostream &outs) const{
   for (long i = 0; i < size; i++)
       outs << list[i] << endl;
}

double TemperatureList::get_last() const{
   if (size == 0) return 0.0;
   return list[size-1];
}

void TemperatureList::detele_last(){
   if (size > 0);
       size -= 1;
}
