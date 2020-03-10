/******************************************************************************

7. Dynamic 2D Arrays

*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void fill(int**,int,int);
void print(int**,int,int);

int main()
{
    //int *board[4];
    /* 
    In the line of code above, we have a pointer variable called 'board'. This
    will create an array of 4 other pointers where each pointer is of type 
    'int'. Since board 0, 1 , 2, and 3 are all pointers, you can use these 
    pointers to create the new rows of board. 
    
    Now, suppose that each row of board has 6 columns. Then, the 'for' loop 
    on this next line of code will create the array. 
    */
    //for (int row = 0; row < 4; row++)
        //board[row] = new int[6];
        /*
        The 'new int[6]' on this next line will creates an array of 6 components 
        of type 'int', and returns the base address of the array. The assignment
        statement then stores the "return to" address into 'row', which is found
        on the left hand side of the assignment statement. So, for instance, the
        row 0 will have 6 new integers, and so on.
        */
        
    /*
    So after the execution of the above 'for' loop, we must see that 'board' is
    a 2D-array of 4 rows and 6 columns. We can adjust the amount of rows by
    simply changing the number on line 28, so it is a dynamic array in that 
    aspect. However, since we can't do the same to the amount of rows the array
    has, it's not yet a truly dynamic array. 
    */
    
    int **board;
    /*
    So if we consider this statement above, we can see that we are declaring
    'board' to be a pointer to a pointer.
    
    We can see here that 'board' can store the address of a pointer or an array 
    of pointers of type 'int', and the '*board' can store an address of of type
    'int' into a memory space or an array of integer variables.
    */
    board = new int* [10];
    /*
    Suppose that we wanted 'board' to be an array of 10 rows and 15 columns. To
    accomplish this, we create an array of 10 pointers of type 'int' -- which is
    what we do in the above line of code -- and we assign the address of this 
    array to 'board'. Then, we will create the columns of 'board' in essentially
    the same way we had done previously in line 28. However, we have the 'new 
    int' pointer of 10 being assigned to 'board'. Now, to access the components
    of 'board', we can use the array subscripting notation -- such as "[10]" --
    but we must also note that the number of rows and the number of columns of
    'board' can be specified during the program's execution as well. We did not
    technically do this in the first couple examples that we have completed 
    above. 
    
    So we are going to just comment out lines 17, 27, 28, 45, and 54.
    
    */
    
    /*
    Now, we have 2 functions here. Notice our pointer to '*board' of type 'int', 
    and then we also have just our regular integer variables: 
        1) rows
        2) columns. 
    
    Now in our function prototypes, we're using the pointer to '*int' and the
    other two integers as well, and we're also going to be using them in 'print' 
    (as seen in line 12 and line 13). 
    */
    for (int row = 0; row < 10; row++)
        board[row] = new int[15];
    
    //int **board, rows, columns;
    int rows, columns;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> columns;
    cout << endl;
    
    board = new int* [rows]; //creates rows of 'board'
    for (int row = 0; row < rows; row++)
        board[row] = new int[columns];//creates columns of 'board'
    
    fill(board,rows,columns);//input elements into 'board'
    cout << endl;
    print(board,rows,columns);//output elements of 'board'
    system("PAUSE");
    return 0;
}

int row, col;
void fill(int **p, int rowSize, int colSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << colSize << " numbers for row number " << row << ": ";
    }
    //int row, col;
    for (int col = 0; col < colSize; col++)
        cin >> p[row][col]; //stores the number of rows into the pointer here
    cout << endl;
}

//code below prints the array using the pointer to a pointer
void print(int **p, int rowSize, int colSize)
{
    for (int row = 0; row < rowSize; row++)
        cout << setw(5) << p[row][col];
    cout << endl;
}







//for more space
