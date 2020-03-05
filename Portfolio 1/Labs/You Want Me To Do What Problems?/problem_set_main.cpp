#include <cstdlib>
#include "problem_set.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Problem_Set a;
    string prompt = "Welcome to the HW list simplifier!\n"
            "Enter your problem list: ";
    a.Input_List(prompt);
    a.Output();
}
