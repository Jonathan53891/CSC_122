// Save as DynamicStringArray.h

#include<iostream>
#include<string>
using namespace std;

class DynamicStringArray { //The class should have the following:
private:
string* dynamicArray; //1. A private member variable called dynamicArray that references a dynamic array of type string.
int size; //2. A private member variable called size that holds the number of entries in the array.
public:
DynamicStringArray();
int getSize();
void addEnrty(string str);
bool deleteEntry(string str);
string getEntry(int index);
DynamicStringArray(const DynamicStringArray& D);
DynamicStringArray& operator = (const DynamicStringArray& D);
~DynamicStringArray();
};


// Save as DynamicStringArray.cpp
#include "DynamicStringArray.h"

DynamicStringArray::DynamicStringArray(){ //3. A default constructor that sets the dynamic array to Null and sets size to 0.
dynamicArray = NULL;
size = 0;
}
int DynamicStringArray::getSize() { return size; }//4. A function that returns size.
//5. A function named addEnrty that takes a string as input.
void DynamicStringArray::addEnrty(string str){
//The function should create a new dynamic array one element larger than dynamicArray,
    if(size!=0){
    string* local = new string[size+1];
   //   copy all elements from dynamicArray into the new array,
   for(int i=0; i<size; i++)
   local[i] = dynamicArray[i];
   //add the new string onto the end of the new array,
   local[size] = str;
     //   increment size,
   size++;
   //delete the old dynamicArray,
   delete[] dynamicArray;
   // and then set dynamicArray to the new array.
   dynamicArray = local;
   }
   else
   {
   dynamicArray = new string[1];
   size = 1;
   dynamicArray[0] = str;
   }
}
// 6. A function named deleteEnrty that takes a string as input.
bool DynamicStringArray::deleteEntry(string str){
//The function should search dynamicArray for the string. If not found, it returns false.
   int i;
   for(i=0; i<size; i++){
       if(dynamicArray[i].compare(str)==0)
       break;
   }
   if(i==size) return false;
   //If found, it creates a new dynamic array one element smaller than dynamicArray.
   string* local = new string[size-1];
   //It should copy all elements except the input string into the new array,
   int index = 0;
   for(i=0; i<size; i++){
       if(dynamicArray[i].compare(str)!=0)
       local[index++] = dynamicArray[i];
   }
   //delete dynamicArray,
   delete[] dynamicArray;
   dynamicArray = local;
   //decrement size, and return true.
   size--;
   return true;
}
//7. A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray.
string DynamicStringArray::getEntry(int index){
// It should return Null if the index is out of dynamicArray
