#include <iostream>
using namespace std;

int main()
{
char stringA[256];
char stringB[256];
  
cout << "Enter string A:";
cin.getline(stringA,256);
cout << "stringA is : " << stringA << endl ;
cout << "Enter string B: ";
cin >> stringB;
cout << "stringB is: " << stringB << endl ;
  
return 0;
}
