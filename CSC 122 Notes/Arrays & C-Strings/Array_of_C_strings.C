/******************************************************************************

6a. Array of C-strings

*******************************************************************************/
#include <stdio.h>

int main()
{
    //char* message; //message is a string
    
    //char* messages2[10]; //messages is an array of 10 elements
                          //each element in the array is of type "char*"
                        
    /* Being of type "char*" means that it contains the address of another
    location where we have a string. 
    
    So, 
    - messages[0] 
    - messages[1] 
    - messages[2]
    
    are all strings. 
    
    Also, we can always write something like the following:
    */
    
    //char* messages[10] { "One", "Two","Three"};
    
    /* 
        The stages of these elements are:
        
        0 == One
        1 == Two
        2 == Three
        
    */
    
    /* 
    Now, let's construct code that can combine the three strings above into just
    one, large string. 
    */
    
    char *allstrings;
    char* messages[5];// = { "One", "Two","Three"};
    int i;
    int total = 0;
    for (i=0; i<5; i++)
    {
        printf("Enter a string: ");
        messages[i] = (char*) malloc(10);
        //line above is used to appropriate allocate memory to the string 
        //line above can only hold a maximum of 10 characters
        scanf("%s", messages[i]);
        total += strlen(messages[i]);
    }
    
    allstrings = (char*) malloc(total);
    strcpy(allstrings,messages[0]);
    
    for (i=0; i<5; i++)
    {
        //strcat(allstrings, " "); //adds a space to the combo of strings
        strcat(allstrings, messages[i]);
    }
    printf("%s", messages[i]);
    free(allstrings); //frees the memory from the end of the program
    for (i=0; i<5; i++)
        free(messages[i]);
    
}
