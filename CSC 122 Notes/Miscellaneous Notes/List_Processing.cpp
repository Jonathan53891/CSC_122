/*
 * There are two main search algorithms:  linear search and
 * binary search.
 *
 * Linear search is something a hunting dog might come up
 * with:  start at one end of the list/vector and look at
 * each item in turn until you find what you want or run out
 * of things to look at.  (Analytically, the function
 * describing how many comparisons it will take to find any
 * particular item turns out to be a linear function.)
 *
 * Binary search would take a bit more brain power.  It
 * might be developed by a bright 4-year-old or certainly by
 * a 5-year-old.  It is a one-dimensional hotter-colder
 * algorithm more commonly known as high-low.  In fact, it
 * is the optimal high-low strategy.  The function which
 * analytically describes the number of comparisons required
 * -- given that the data in the list is in order -- is
 * logarithmic.  (Logarithms, of course, grow much more
 * slowly than lines and so this seems like the ideal
 * searching algorithm.)
 *
 * What was that about 'ordered data', though?
 * Oh...er...yeah...  More on that later...
 */

#include <vector>
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * To save typing vector<basetype> and/or
 * vector<basetype>::size_type over and over and over
 * and...well, to keep from doing that, you can pick a
 * shorter, yet still meaningful, name to use.  Teaching
 * this new name to the compiler is as simple as including a
 * type-definition:
 */
typedef vector<short> sh_Vec;          // now 'sh_Vec' is equivalent to
                                           // 'vector<short>'
typedef sh_Vec::size_type sh_Vec_sz;   // now 'sh_Vec_sz' is equivalent to
                                           // 'vector<short>::size_type'

/*
 * Searches thru vector v for element f.  Returns position f
 * was found or v.size() when f was not present in the
 * vector.
 */
sh_Vec_sz linear_search(const sh_Vec & v, short f,
                        sh_Vec_sz begin = 0);

/*
 * Searches through vector v for element f.
 *
 * NOTE:  The elements of v **MUST** be in order for this
 *        search to work!!!  (We assume non-decreasing --
 *        ascending -- order here.)
 *
 * Returns position of f if found or a position not
 * containing f (if f is not present).
 */
sh_Vec_sz binary_search(const sh_Vec & v, short f);

int main(void)
{
    sh_Vec nums;
    sh_Vec_sz pos;
    short find_me, x;
    char yes_no;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "\nSearching with LINEAR search...\n";
    for (sh_Vec_sz n = 0; n != 100; n++)
    {
        nums.push_back(rand() % 101);
    }
    do
    {
        cout << "Find what?  ";
        cin >> find_me;
        pos = linear_search(nums, find_me);
        if (pos >= nums.size())
        {
            cout << "Couldn't find " << find_me << " in my vector!\n";
        }
        else
        {
            cout << "Found " << find_me << " at position " << pos
                 << " within the vector.\n";
        }
        cout << "\nAgain?  ";
        cin >> yes_no;
        yes_no = tolower(yes_no);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while ( yes_no != 'n' );

    cout << "\nSearching with BINARY search...\n";
    nums.clear();
    x = 20;   // rand() % 10000;
    for (sh_Vec_sz n = 0; n != 100; n++)
    {
        nums.push_back(x);
        x++;  // += rand() % 5 + 1;
    }
    do
    {
        cout << "Find what?  ";
        cin >> find_me;
        pos = binary_search(nums, find_me);
        if (pos >= nums.size() || nums[pos] != find_me)
        {
            cout << "Couldn't find " << find_me << " in my vector!\n";
        }
        else
        {
            cout << "Found " << find_me << " at position " << pos
                 << " within the vector.\n";
        }
        cout << "\nAgain?  ";
        cin >> yes_no;
        yes_no = tolower(yes_no);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while ( yes_no != 'n' );
    return 0;
}









/*
 * Searches thru vector v for element f.  Returns position f
 * was found or v.size() when f was not present in the
 * vector.
 */
sh_Vec_sz linear_search(const sh_Vec & v, short f,
                        sh_Vec_sz begin)
{
    sh_Vec_sz p = begin > v.size() ? v.size() : begin;
    while (p < v.size() &&   // more elements to search thru
           v[p] != f)        // not what we want
    {
        ++p;           // move along...nothing to see here...
    }
    return p;  // will be position of f _OR_ >=v.size() (when not found)
}
/*
 * The != test could change depending on the base type of
 * the vector, of course.  != works for integral types,
 * chars, and even strings.  But for types like double or
 * class types we might need different codes like:
 *
 *      base type   |  code for !=
 *    --------------+----------------------------
 *      double      |  fabs(v[p] - f) > EPSILON
 *      Point2D     |  ! v[p].isSame(f)
 *
 * And so on.  (Hopefully these two examples prove
 * illustrative enough to allow you to generalize all other
 * situations.  *grin*)
 *
 * ***********************************************************
 *
 * What if there are duplicates?  Then use a for loop
 * instead and push_back each found position onto a running
 * list and return that:
 *
 * void linear_search(const sh_Vec & v, short f,
 *                    sh_Vec_sz begin,
 *                    vector<sh_Vec_sz> & poses)
 * {
 *     for ( sh_Vec_sz p = 0; p != v.size(); ++p )
 *     {
 *         if ( v[p] == f )
 *         {
 *             poses.push_back(p);
 *         }
 *     }
 *     return;
 * }
 */







/*
 * Searches through vector v for element f.
 *
 * NOTE:  The elements of v **MUST** be in order for this
 *        search to work!!!  (We assume non-decreasing --
 *        ascending-like -- order here.)
 *
 * Returns position of f if found or a position not
 * containing f (if f is not present).
 */
// remember that v must be in order (I'm assuming ascending-like order here)
sh_Vec_sz binary_search(const sh_Vec & v, short f)
{
    sh_Vec_sz bot = 0,
              top = v.size() - 1,
              mid = (bot + top) / 2;
cerr << "looking for " << f << "\t[" << bot << ".." << top << "] @ " << mid << '\n';
    while (bot < top &&  // more elements to search thru
           v[mid] != f)  // not what we want
    {
cerr << "not found!  " << f << " is ";
        if (v[mid] < f)  // f falls above middle
        {
            bot = mid + 1;    // move bottom up just past middle
cerr << "after " << v[mid] << ".  updating bottom to " << bot;
        }
        else  // v[mid] > f  -- f falls below middle
        {
            top = mid;        // move top down to middle (balances mid's integer division)
cerr << "before " << v[mid] << ".  updating top to " << top;
        }
        mid = (bot + top) / 2;
cerr << "\nlooking for " << f << "\t[" << bot << ".." << top << "] @ " << mid << '\n';
    }
    return mid;   // item is either at mid or not there
}

// It would be nice if the result of binary search were
// either the place the data is or the place the data
// ~should be~ to help us maintain the ordered-ness of our
// list.  E.G.
//
// 1 2 3 4 5 7 8 9 10
//           ^---- is where 6 should be
//
// Tweaking the algorithm above to provide such a cleverly
// useful return value is left as an exercise for the
// intrepid || horribly bored reader.

/*
 * What might concern you is what happens when the elements
 * are not unique within the vector?  Can you modify the two
 * searches to find all occurrences of the value within the
 * vector?  You should be able to...
 *
 * (Hint:  Think about 'returning' a lower and upper bound
 * on the positions for binary search but for linear search
 * maybe a vector of positions -- like with our sub_set
 * display function.)
 */
