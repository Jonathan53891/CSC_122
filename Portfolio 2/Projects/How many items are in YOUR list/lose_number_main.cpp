#include "lose_number_templist.h"

int main(){
   TemperatureList temp(50);
   temp.add_temperature(4.0); temp.add_temperature(7.0); temp.add_temperature(8.0);temp.add_temperature(9.6);
  
   cout << "Last element is : " << temp.get_last() << endl;
   return 0;
}
