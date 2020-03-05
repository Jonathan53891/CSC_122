/******************************************************************************

1. Basics of 1D Arrays

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    /*
    
    General set-up of an array:
    
              0    1   2    3
            ___________________
    iaArray | 3 | -2 | 0 | -2 |
            |___|____|___|____|
    */
    
    int iaArray[4];
    iaArray[0] = 3;  //these 4 lines initialize the entries of the array
    iaArray[1] = -2; //these 4 lines initialize the entries of the array
    iaArray[2] = 0;  //these 4 lines initialize the entries of the array
    iaArray[3] = -2; //these 4 lines initialize the entries of the array
    
    cout << iaArray[0] << endl;
    cout << iaArray[1] << endl;
    cout << iaArray[2] << endl;
    cout << iaArray[3] << endl;
    
    cout << "----------------------------" << endl;
    
    /* We can also initialize the entire array at once */
    
    //int ibArray[4] = {3,-2,0,7}; // We can define the size of the array by putting "ibArray[4]".
    int ibArray[] = {3,-2,0,7}; /* We can also remove the set array size and allow the computer
                                to choose the size of the array. This allows us to update the
                                contents of the array without having to be worried about
                                changing the size parameter of the array. */
    cout << ibArray[0] << endl;
    cout << ibArray[1] << endl;
    cout << ibArray[2] << endl;
    cout << ibArray[3] << endl;
    
    cout << "----------------------------" << endl;
    
    /* If we wish to copy an array, we do the following: */
    
    double values[5] = {10,5,7,13};
    double copy[5];
    
    for (int i = 0; i < 5; i++)
    {
        copy[i] = values[i];
        cout << copy[i] << endl;
    }
    return 0;
    
    /* We can print an array with characters. However, they act differently compared to numbered 
    arrays. Note that the array will always end with a "0" at the end of its array, since zero
    signifies the end of a character string. */
    
}
