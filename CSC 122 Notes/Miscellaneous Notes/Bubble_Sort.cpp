/*
 * Bubble Sort swaps neighboring elements which are 'out of
 * order' until nothing has to move during a 'pass' through
 * the vector/list.
 *
 * Out of order means not in order, of course.  So if you
 * want the list to end up in non-increasing order,
 * increasing neighbors are out of order.  That is, the
 * situation where the left/first neighbor's value is less
 * than the right/second neighbor's value.
 *
 * A pass through the list starts at the beginning and moves
 * from one element to the next all the way to the
 * [next-to-] last element.  (Next-to-last since we are
 * working with neighbors -- pairs -- and the last element
 * has no following neighbor.)
 */
#include <vector>
#include <iostream>

using namespace std;

inline void swap(char & a, char & b)
{
    char c = a;
    a = b;
    b = c;
    return;
}

// vector is placed into in sorted order -- non-ascending
// (decreasing-like)
void good_bubble(vector<char> & vec);

int main(void)
{
    vector <char> data;

    cout << "Enter your characters:  ";
    cout.flush();
    while (cin.peek() != '\n')
    {
        data.push_back(cin.get());
    }

    cout << "\nYou entered:  '";
    for (vector<char>::size_type c = 0; c != data.size(); c++)
    {
        cout << data[c];
    }
    cout << "'\n";

    good_bubble(data);

    cout << "\nNow sorted it is:  '";
    for (vector<char>::size_type c = 0; c != data.size(); c++)
    {
        cout << data[c];
    }
    cout << "'\n";

    return 0;
}

// vector is placed into in sorted order -- non-ascending
// (decreasing)
void good_bubble(vector<char> & vec)
{
    vector<char>::size_type loop = 0;
    bool done = false;
    while ((loop+1 < vec.size()) && ! done)
    {
         done = true;
         for (vector<char>::size_type cur = 0;
              cur+1 != vec.size(); ++cur)
         {
            if ( vec[cur] < vec[cur+1] )   // if out of order
            {
               swap( vec[cur], vec[cur+1] );    // swap
               done = false;                    // we moved stuff, we must not be done...
            }
         }
         ++loop;
    }
    return;
}
/*
 * To change this sort's direction, just change the < in the
 * if statement head to a >.
 *
 * In fact, you could allow the caller of the function to
 * pick the direction fairly easily with an extra bool
 * argument and some helper constants:
 *
 *     const bool NON_ASCENDING = true,
 *                NON_DESCENDING = false
 *                //...more names for different tastes?
 *                ;
 *
 *     void sort(vector<char> & vec, bool low_to_high)
 *     {
 *         // ...
 *         if ( (   low_to_high && vec[cur] < vec[cur+1] ) ||
 *              ( ! low_to_high && vec[cur] > vec[cur+1] ) )
 *         // ...
 *     }
 *
 * Or some such structure...
 *
 * ****************************************************************
 *
 * To change the base type of the vector being sorted, keep
 * in mind that you might have to adjust this comparison to
 * the new base type like so:
 *
 *   base type   |   non-ascending              |   non-descending
 * --------------+------------------------------+------------------------
 *     char      | vec[cur] < vec[cur+1]        | vec[cur] > vec[cur+1]
 *   Point2D (y) | vec[cur].isBelow(vec[cur+1]) | vec[cur].isAbove(vec[cur+1])
 *
 * The string class type could be used with either the
 * operators or the .compare() method, of course and so
 * might be used in either form.  But I guess the .compare()
 * is different enough to warrant its own example, eh?
 *
 *   base type   |   non-ascending                  |   non-descending
 * --------------+----------------------------------+------------------------
 *   string      | vec[cur].compare(vec[cur+1]) < 0 | vec[cur].compare(vec[cur+1]) > 0
 *
 * When you develop more complex classes of your own, you
 * could either use the approach of copy/pasting to create
 * different versions of the sorting routine for each member
 * you are interesting in sorting with respect to:
 *
 *     void sort_x_coord(vector<Point2D> & vec);
 *     void sort_y_coord(vector<Point2D> & vec);
 *
 * And each function would differ only in its if test head.
 * Or, you could place an enumeration along with your class
 * and a comparison function inside it.  The enumeration
 * would indicate with respect to which member a sort (or
 * search) operation is to be performed and could be passed
 * into the proper routine.  For example:
 *
 *     enum Pt2D_CompareBy { COMP_X, COMP_Y };
 *
 *     class Point2D
 *     {
 *         bool isLess(const Point2D & p,
 *                     Pt2D_CompareBy direc) const
 *         {
 *             return direc == COMP_X ? x < p.x : y < p.y;
 *         }
 *         bool isGreater(const Point2D & p,
 *                        Pt2D_CompareBy direc) const
 *         {
 *             return direc == COMP_X ? x > p.x : y > p.y;
 *         }
 *     };
 *
 *     // sorting into non-ascending order by specified
 *     // coordinate
 *     void sort(vector<Point2D> & vec, Pt2D_CompareBy axis)
 *     {
 *         // ...
 *         if ( vec[cur].isLess(vec[cur+1], axis) )
 *         // ...
 *     }
 *
 * But that isn't the only way, you could make it a pair of
 * const bool values in this case since there are only two
 * members to distinguish, for instance.  Or you could make
 * it a string::compare style function with a small integer
 * result to tell the direction of the comparison on the
 * indicated axis (rather than a pair of functions -- one
 * for each ordering -- each returning a bool).
 *
 * Or, you could have the comparison enumeration set as a
 * static member of the class so that all comparisons would
 * be in that manner until otherwise decided (aka mutated):
 *
 *     class Point2D
 *     {
 *         static Pt2D_CompareBy order_axis;
 *         // ...rest of members unaffected...
 *     public:
 *         static Pt2D_CompareBy get_current_ordering(void)
 *         {
 *             return order_axis;
 *         }
 *         static bool set_current_ordering(Pt2D_CompareBy new_dir)
 *         {
 *             order_axis = new_dir;
 *             return true;
 *         }
 *         bool isLess(const Point2D & p) const
 *         {
 *             return order_axis == COMP_X ? x < p.x : y < p.y;
 *         }
 *         bool isGreater(const Point2D & p) const
 *         {
 *             return order_axis == COMP_X ? x > p.x : y > p.y;
 *         }
 *     };
 *
 *     // initialize static member (normally in implementation)
 *     Pt2D_CompareBy Point2D::order_axis = COMP_X;
 *
 *     // sorting into non-ascending order by currently
 *     // chosen coordinate
 *     void sort(vector<Point2D> & vec)
 *     {
 *         // ...
 *         if ( vec[cur].isLess(vec[cur+1]) )
 *         // ...
 *     }
 *
 *     {
 *         vector<Point2D> data;
 *
 *         Point2D::set_current_ordering(COMP_Y);
 *         sort(data);
 *         // data is now sorted vertically
 *
 *         Point2D::set_current_ordering(COMP_X);
 *         sort(data);
 *         // data is now sorted horizontally
 *     }
 *
 * (See also the static.member example under classes.)
 */
