/******************************************************************************

6b. 2D Arrays

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    
    /*
    int Matrix[3][3] = {    {   1,      2,      3   }, //row1
                            {   4,      5,      6   }, //row2
                            {   7,      8,      9   }  //row3
                          //{column1,column2,column3}
                       };
    */
    
    /* Code written above is the code needed to describe a 3x3 matrix. The 
    notation of a matrix here (and just in general), is "rows x columns". */
    
    /*
    Can also be written as:
    
    int Matrix[3][2] = {    {   1,      2   }, //row1
                            {   4,      5   }, //row2
                            {   7,      8   }  //row3
                          //{column1,column2}
                       };
    
    OR
    
    */
    
    char Matrix[3][2] = {   {   'A',    'B'  }, //row1
                            {   'C',    'D'  }, //row2
                            {   'E',    'F'  }  //row3
                          //{column1,column2}
                        };
    /*
    
    How the computer reads matrices:
                        
                COLUMNS
        
             0     1     2
          ___________________
          |     |     |     |
        0 |  A  |  B  |  C  |
   R      |_____|_____|_____|
   O      |     |     |     |
   W    1 |  D  |  E  |  F  |
   S      |_____|_____|_____|
          |     |     |     |
        2 |  G  |  H  |  I  |
          |_____|_____|_____|
          
    This gets further translated by the computer to:
    _______________________________
    |         |         |         |
    |  (0,0)  |  (0,1)  |  (0,2)  |
    |_________|_________|_________|
    |         |         |         |
    |  (1,0)  |  (1,1)  |  (1,2)  |
    |_________|_________|_________|
    |         |         |         |
    |  (2,0)  |  (2,1)  |  (2,2)  |
    |_________|_________|_________|
    
    */
    
    /*
    
    We can also initialize matrices like the following:
    
    char Matrix[][2] = { {'A','B'},     //compiler will figure out that with 2
                         {'C','D'},     //columns and 6 elements, it needs 3
                         {'E','F'}      //rows, despite not being told that
                       };
    
    OR 
    
    char Matrix[3][2] = {'A','B',
                         'C','D',
                         'E','F'
                        };
                        
    //Similarly to the matrix above, by telling the program the exact amount of
    //rows and columns you want (here, 3 and 2, respectively), and there are 
    //clearly 6 elements listed the computer will automatically figure out 
    //where to plug in the elements from there. So there is no need for the 
    //curly '{}' brackets.
    
    We can clean up the matrices we used above and format it like the following:
    */
    
    char Matrix0[3][2] = {{'A','B'},{'C','D'},{'E','F'}};
    char Matrix1[][2] = {{'A','B'},{'C','D'},{'E','F'}};
    char Matrix2[3][2] = {'A','B','C','D','E','F'};
    
    //cout << Matrix[0][1] << endl;
    //Matrix[0][0] = 'Z'; //this line of code can change values within the matrix
    cout << Matrix0[1][0] << endl;
    
    return 0;
}









//for more space
