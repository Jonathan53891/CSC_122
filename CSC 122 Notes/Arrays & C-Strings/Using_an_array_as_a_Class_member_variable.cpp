/******************************************************************************

5. Using an array as a class member variable

*******************************************************************************/
 /*
 
 To begin, recall that an array is an indexed collection of data elements of the
 same type (where the indexing runs from 0 through size-1). In addition to 
 building arrays of built-in types, we can have arrays of objects.
 */
 
 Fraction rationals[20];  // array of 20 Fraction objects 
 Complex nums[50];        // an array of 50 Complex objects
 Hydrant fireplugs[10];   // an array of 10 objects of type Hydrant (a dog's dream!)
 
 /*
 In an array of objects, each array position is a single object.
 
 For instance, given the above declaration of the "rationals" array, there are 
 20 Fraction objects, named rationals[0], rationals[1], ... , rationals[19]
 
 Normally the constructor initializes an object. But how would be cite the 
 appropriate constructor for each object in an array?
 
 The normal array declaration style uses the default constructor for each object
 in the array (if the class has a default constructor)
 */
 
 Fraction numList[4];       // builds 4 fractions using default constructor
 
 /*
 To specify different constructors for different array items, an initializer 
 set can be used. Since there are no literals for class types, we can instead 
 use explicit constructor calls:
 */
 
 Fraction numList[3] = { Fraction(2,4) , Fraction(5) , Fraction() }; 
 // the above code allocates an array of 3 fractions, initialized to 2/4, 5/1, and 0/1
 
 /*
 
 Indexing works the same as with regular arrays. The dot-operator works the same
 as with single names:
 */
 
 objectName.memberName
 
 /*
 Just remember that the name of such an object is now:
 */
 
 arrayName[index]
 
 /* Examples of this can be found below: */
 
 Fraction rationals[20]; // create an array of 20 Fraction objects
 // ...
 rationals[2].Show();    // displays the third Fraction object 
 rationals[6].Input();   // calls Input function for the 7th Fraction 
 cout << rationals[18].Evaluate(); 

/*

C-style arrays are pretty old. C-style arrays don't come with boundary checking. 
This is pretty crappy, espeically when someone is just learning how to code. 

If an array is used as member data of a class, the member functions can add in 
error-checking and boundary protection. This is a good technique for creating 
safer array types -- user defined classes that store large amounts of data

Also notice that when an array is member data of a class, it's already in scope 
for the member functions. So there will be less need to pass the array as a 
parameter. However, this doesn't mean you'll never have array parameters. You
just have to use array parameters less frequently.

*/

 bool Delete(int n);  // delete the nth element of the list
                      //  return true for success, false if n not a valid position

 double Sum();        // return the sum of the elements of the list
 double Average();    // return the average of the elements of the list
 double Max();        // return the maximum value in the list
 void Clear();        // reset the list to empty
 int Greater(double x); // count how many values in the list are greater 
                        //  than x.  Return the count.





//for more space
