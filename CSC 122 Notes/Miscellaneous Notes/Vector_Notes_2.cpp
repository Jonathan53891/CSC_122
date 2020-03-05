/*
 * Managing a list of information stored in a vector is not
 * necessarily a difficult thing.  It is merely complicated
 * by the lack of vector-supplied functionality...
 *
 * Operations we'd expect to be performed on/by a list would
 * be:
 *
 *     -- display the list elements
 *        -- all?
 *        -- subrange?                             (subset?)
 *        -- numbered?                      (1-based shift!)
 *           -- relative or absolute?
 *     -- insert a new item into the list
 *        -- at end?                            (push_back!)
 *        -- in the middle?
 *        -- in front?
 *     -- remove an item from the list
 *        -- from end?                           (pop_back!)
 *        -- from the middle?
 *        -- from front?
 *     -- locate an item within the list
 *        -- present?
 *           -- duplicated?
 *        -- ordered?
 *     -- place a list in order                (aka sorting)
 *        -- ascending/descending?
 *        -- non-decreasing/non-increasing?
 *
 * Of these, vector provides none natively.  Oh, maybe it is
 * difficult.
 *
 * Nah...just kidding!  All of these things can be done with
 * relative ease by building from the tools we've already
 * been given by the vector.
 */
#include <iostream>
#include <vector>
#include <cctype>
#include <limits>
#include <cmath>

using namespace std;




/*
 * Prints [to cout] the given vector's elements in the range
 * of subscripts [begin..end_before).  The list of elements
 * is displayed one per line and will be numbered at the
 * caller's option.
 *
 * The inline helper function outputs the entire vector
 * rather than a specific sub-range of elements.
 */
const bool DISPLAY_NUMBERED = true,
           DISPLAY_PLAIN    = false;
// const bool NUMBER_RELATIVE = true,
//            NUMBER_ABSOLUTE = false;
void display(const vector<double> & vec,
             vector<double>::size_type begin,
             vector<double>::size_type end_before,
             bool numbered = DISPLAY_PLAIN); // ,
          // bool relative = NUMBER_ABSOLUTE);
    inline
void display(const vector<double> & vec,
             bool numbered = DISPLAY_PLAIN) // ,
          // bool relative = NUMBER_ABSOLUTE)
{
    display(vec, 0, vec.size(), numbered); // , relative);
    return;
}
void display(const vector<double> & vec,
             const vector<vector<double>::size_type> & poses,
             bool numbered = DISPLAY_PLAIN); // ,
          // bool relative = NUMBER_ABSOLUTE);

/*
 * Print all elements in the given vector.  Caller may
 * specify strings to be placed before, after, and between
 * the elements of the vector.
 */
void display(const vector<vector<double>::size_type> & v,
             const string & pre = "{ ",
             const string & post = " }",
             const string & between = ", ",
             vector<double>::size_type adjustment = 1);













/*
 * Finds an element in the given vector whose value is
 * [approximately] equal to the desired value.  Returns
 * either the position of the first such element found or
 * vec.size() to indicate no such element was found.  (A
 * value farther than EPSILON from another is considered
 * unequal.)
 *//*
inline vector<double>::size_type locate(const vector<double> & vec,
                                        double find_me,
                                        vector<double>::size_type start = 0,
                                        double EPSILON = 1e-6)
{
    vector<double>::size_type pos = start;  // start at specified position
    while (pos < vec.size() &&              // not at end of vector  AND
           fabs(vec[pos]-find_me) > EPSILON) // not found, yet...   ( != )
    {
        ++pos;                              // try next one...
    }
    return pos;                             // either place find_me was, or .size()
}*/












/*
 * Similar to above but finds all occurrences of target in
 * the vector.  Stores the positions of matches in the
 * provided vector (possibly appending to data already
 * located therein).
 */
void locate(const vector<double> & vec, double find_me,
            vector<vector<double>::size_type> & poses,
            bool append = false, double EPSILON = 1e-6);







#include "listops.h"






/*
 * Place the new element into the specified vector at the
 * position given.  The current element at that position (as
 * well as any which follow it) are shifted toward the end
 * of the vector.  A value of true will be returned if we
 * are able to grow the vector and store the new value;
 * false will be returned otherwise.  (If the insertion is
 * successful, the vector will have one more element upon
 * return than when it was called.)
 *
 * The first inline helper function merely appends the
 * proffered item to the current vector contents --
 * .push_back() with a 'will it fit' test.
 *
 * The second inline helper function takes a value in front
 * of which the new value is to be placed -- rather than a
 * position.  It uses the locate() function above before
 * calling the primary insert() function.
 */
#if 0
bool insert(vector<double> & vec,
            vector<double>::size_type before_me,
            double new_item);
    inline
bool insert(vector<double> & vec, double new_item)
{
    vector<double>::size_type old_size = vec.size();
    /*bool okay = vec.size() != vec.max_size();
    if (okay)
    {*/
    /*try
     *{*/
        vec.push_back(new_item);
    /*}
     *catch (...)
      {
         // do nothing but stop the exception from going
         // further
      }*/
    //}
    return old_size < vec.size(); //okay;
}
#endif

const bool APPEND_ON_NOT_FOUND = true,
           ERROR_ON_NOT_FOUND  = false;
    inline
bool insert(vector<double> & vec, double before_me,
            double new_item,
            bool not_found_appends = APPEND_ON_NOT_FOUND)
{
    bool okay;
    vector<double>::size_type before_here = locate(vec, before_me);
    if (before_here != vec.size())
    {
        okay = insert(vec, before_here, new_item);
    }
    else  // we couldn't find 'before_me' in 'vec'... should we claim failure
    {                 // or insert the 'new_item' in our default location?
        okay = not_found_appends && insert(vec, new_item);
    }
    return okay;
}


/*
 * Deletes all elements in the specified sub-range interval
 * [from_here..to_before_here) from the given vector.
 * Returns true when this erasure succeeds; false when
 * either from_here is an illegal position or to_before_here
 * is before from_here, or the range is empty.
 *
 * The first inline helper removes just the single element
 * position specified.
 *
 * The second inline helper removes the first occurrence of
 * the specified value from the vector.  It will return
 * false if the specified value is not currently in the
 * vector.
 *//*
bool remove(vector<double> & vec,
            vector<double>::size_type from_here, 
            vector<double>::size_type to_before_here);
    inline
bool remove(vector<double> & vec,
            vector<double>::size_type remove_me)
{
    return remove(vec, remove_me, remove_me+1);
}
*/
// see also the bottom for a different design idea...
const bool REMOVE_ALL = true,
           REMOVE_ONE = false;
bool remove(vector<double> & vec, double remove_me,
            bool all_copies = REMOVE_ONE);






int main(void)
{
    vector<double> heights;
    vector<double>::size_type pos;
    vector<vector<double>::size_type> posits;
    double height;
    char choice;
    bool done = false;
    do
    {
        cout << "\nMain Menu\n\n"
                "1) Enter height\n"
                "2) Delete height\n"
                "3) find First height\n"
                "4) find All heights\n"
                "5) Print heights\n"
                "6) Quit\n\n"
                "Choice:  ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (toupper(choice))
        {
            case '1': case 'E':     // enter new list item
            {
                cout << "\nEnter new height:  ";
                cin >> height;
                // don't need to know position when list is
                // currently empty...
                if (heights.empty())
                {
                    insert(heights, height);
                }
                else
                {
                    cout << "\nSelect a position in front "
                            "of which to place the new "
                            "height:\n";
                    display(heights, DISPLAY_NUMBERED);
                    cout << (heights.size()+1)
                         << ":  ~~END~~\n";
                    cout << "\nPosition for new height?  ";
                    cin >> pos;
                    // fail check against negative position?
                    --pos;
                    if (pos < heights.size())
                    {
                        insert(heights, pos, height);
                    }
                    else if (pos == heights.size())
                    {
                        insert(heights, height);
                    }
                    else
                    {
                        cout << "\n\a\tIllegal position "
                                "chosen!  Please try "
                                "again...\n";
                    }
                }
            } break;
            case '2': case 'D':        // delete list item
            {
                if (heights.empty())
                {
                    cout << "\n\a\tYou cannot delete from "
                            "an empty list!\n";
                }
                else
                {
                    cout << "\nSelect a value to delete:\n";
                    display(heights, DISPLAY_NUMBERED);
                    cout << "\nDelete data at which "
                            "position?  ";
                    cin >> pos;
                    // fail check against negative position
                    // or decimal values?
                    --pos;
                    if (pos < heights.size())
                    {
                        remove(heights, pos);
                    }
                    else
                    {
                        cout << "\n\a\tIllegal position "
                                "chosen!  Please try "
                                "again...\n";
                    }
                }
            } break;
            case '3': case 'F':           // find in list
            {
                cout << "\nEnter value to find:  ";
                cin >> height;
                pos = locate(heights, height);
                if (pos == heights.size())
                {
                    cout << "\n\a\tCould not find '"
                         << height << "' in list!\n";
                }
                else
                {
                    cout << "\nFound '" << height << "' at "
                            "position '" << (pos+1)
                         << "' in your list.\n";
                }
            } break;
            case '4': case 'A':       // find all in list
            {
                cout << "\nEnter value to find:  ";
                cin >> height;
                locate(heights, height, posits);
                if (posits.empty())
                {
                    cout << "\n\a\tCould not find '"
                         << height << "' in list!\n";
                }
                else
                {
                    cout << "\nFound '" << height
                         << "' at positions:";
                    display(posits, "  '", "' ");
                    cout << "in your list.\n";
                }
            } break;
            case '5': case 'P':              // print list
            {
                cout << "\nYou've entered:\n";
                display(heights);
                cout << "in your list...\n";
            } break;
            case '6': case 'Q': case 'X':    // quit (exit)
            {
                done = true;
            } break;
            default:                     // nothing good...
            {
                cout << "\n\a\tInvalid selection!  Please "
                        "try again...\n";
            } break;
        }
    } while (!done);
    return 0;
}


/*
 * Deletes all elements in the specified sub-range interval
 * [from_here..to_before_here) from the given vector.
 * Returns true when this erasure succeeds; false when
 * either from_here is an illegal position or to_before_here
 * is before from_here, or the range is empty.
 *//*
bool remove(vector<double> & vec,
            vector<double>::size_type from_here,
            vector<double>::size_type to_before_here)
            
        
            // Size_type looks at the data type and picks 
            // size_type to represent size information about
            // doubles within a vector. Using your own data
            // type could mess with the program and things 
            // might not run as well as it could by simply
            // using size_type.
            
            
{
    vector<double>::size_type count;
    to_before_here = to_before_here > vec.size()
                         ? vec.size() : to_before_here;
    bool okay{to_before_here >= from_here};   // to_before_here is already
                                              // <= vec.size() so
                                              // transitivity protects
                                              // from_here, too
             ____________________________
            |   |   |   |   |   |   |   |
    Begins: | a | b | d | e | f | g | h |
            |___|___|___|___|___|___|___|
            
           ________________
          |   |   |   |   |
    Ends: | a | b | g | h |      // f g h from the previous list above are removed
          |___|___|___|___|
         
    count = to_before_here - from_here;
    if (okay && count > 0)
    {
             // auto
        for (vector<double>::size_type pos{to_before_here};
             pos != vec.size(); ++pos)
        {
            vec[pos-count] = vec[pos];
        }
        vec.resize(vec.size()-count);
    }
    return okay;
}
*/
bool remove(vector<double> & vec, double remove_me,
            bool all_copies)
{
    bool okay;
    vector<double>::size_type remove_here; //, count = 0;
    do
    {
        remove_here = locate(vec, remove_me);
        if (remove_here != vec.size())
        {
            okay = remove(vec, remove_here);     // call inline helper
            /*if (okay)
            {
                ++count;
            }*/
        }
        else
        {
            okay = false;
        }
    } while (all_copies && okay);
    return all_copies // && count > 0
           || okay;
}




/*
 * Place the new element into the specified vector at the
 * position given.  The current element at that position (as
 * well as any which follow it) are shifted toward the end
 * of the vector.  A value of true will be returned if we
 * are able to grow the vector and store the new value;
 * false will be returned otherwise.  (If the insertion is
 * successful, the vector will have one more element upon
 * return than when it was called.)
 */
#if 0
bool insert(vector<double> & vec,
            vector<double>::size_type before_me,
            double new_item)
{   // auto
    vector<double>::size_type old_size{vec.size()};
    bool okay{false}; //vec.size() != vec.max_size();
    if (before_me == old_size)
    {
        okay = insert(vec, new_item);
    }
    else if (before_me < old_size)
    {
        vec.resize(old_size+1); //gives us room to put a new element in
        okay = old_size < vec.size();
        if (okay)
        {         // auto
            
            for (vector<double>::size_type pos = old_size-1; 
            pos >= before_me && pos+1 != 0;
                 --pos)
            {
                vec[pos] = vec[pos-1]; //single argument
            }
            
            /* old code found on website
            for (vector<double>::size_type pos{old_size}; pos > before_me;
                 --pos)
            {
                vec[pos] = vec[pos-1];
            }
            */
            
            vec[before_me] = new_item;
            /* a not so efficient, but convenient way...
            vec.push_back(new_item);
            for (vector<double>::size_type pos = old_size-1;
                 pos >= before_me; --pos)
            {
                swap(vec[pos], vec[pos+1]); //requires 3 steps, so this option is less efficient
            }
            */
        }
    }
    return okay;
}
#endif









/*
 * Finds an element in the given vector whose value is
 * [approximately] equal to the desired value.  Returns
 * either the position of the first such element found or
 * vec.size() to indicate no such element was found.
 */
void locate(const vector<double> & vec, double find_me,
            vector<vector<double>::size_type> & poses,
            bool append, double EPSILON)
{
    vector<double>::size_type pos;
    if ( ! append )
    {
        poses.clear();
    }
    pos = locate(vec, find_me, 0, EPSILON);   // find first occurrence..?
    while (pos != vec.size())          // still found one...
    {
        poses.push_back(pos);          // remember it
        pos = locate(vec, find_me, pos+1, EPSILON);   // try next one...
    }
    return;
}






/*
 * Prints [to cout] the given vector's elements in the range
 * of subscripts [begin..end_before).  The list of elements
 * is displayed one per line and will be numbered at the
 * caller's option.
 */
void display(const vector<double> & vec,
             vector<double>::size_type begin,
             vector<double>::size_type end_before,
             bool numbered) // , bool relative)
{
    end_before = end_before > vec.size() ? vec.size()
                                         : end_before;
    // vector<double>::size_type disp_pos = relative ? 1 : begin+1;
    for (vector<double>::size_type pos = begin;
         pos < end_before;                         // !=
         ++pos)
    {
        if (numbered)
        {
            //      disp_pos
            cout << (pos+1) << ":  ";
        }
        cout << vec[pos] << '\n';
        // ++disp_pos;
    }
    return;
}




void display(        const vector<double> & vec,
             const vector< vector<double>::size_type > & poses,
             bool numbered) // , bool relative
{
    for (vector<
                 vector<double>::size_type
               >
               ::size_type
           pos = 0; pos != poses.size(); ++pos)
    //for (vector<double>::size_type vpos : poses)
    //for (auto vpos : poses)
    {
        if (numbered)
        {                                //vpos
            cout << /*(relative ? pos :*/poses[pos]/*)*/ + 1
                 << ":  ";
        }     //vec[vpos]
        cout << vec[ poses[pos] ] << '\n';
    }
    return;
}

/*
 * But how to create the vector of positions?  Depends, but
 * let's say you wanted to display all vector elements which
 * were less than 6, you could do:
 *
 *     vector<vector<double>::size_type> disp_poses;
 *
 *     for (vector<double>::size_type pos = 0;
 *          pos != heights.size(); ++pos)
 *     {
 *         if (heights[pos] < 6)
 *         {
 *             disp_poses.push_back(pos);
 *         }
 *     }
 
             ____________________________
            |   |   |   |   |   |   |   |
    Begins: | 2 | 7 | 4 | 5 | 8 | 6 | 5 |
            |___|___|___|___|___|___|___|
              0   1   2   3   4   5   6
            ------^           ^   ^
            |    -------------|   |
            |   |   --------------|
            |   |   |
           ____________
          |   |   |   |
    Ends: | 1 | 4 | 5 |      // looks for height >= 6
          |___|___|___|
            0   1   2
 
 *
 * And then call our display function:
 *
 *     display(heights, disp_poses);
 */


/*
 * Print all elements in the given vector.  Caller may
 * specify strings to be placed before, after, and between
 * the elements of the vector.
 */
void display(const vector<vector<double>::size_type> & v,
             const string & pre, const string & post,
             const string & between,
             vector<double>::size_type adjustment)
{
/*  typedef vector<double> vecD;
    typedef vecD::size_type vecD_sz;
    typedef vector<vecD_sz> vecD_Sz;
    typedef vecD_Sz::size_type vecD_Sz_sz;
*/
    cout << pre;
    if ( ! v.empty() )
    {              // vecD_Sz_sz
        for (vector<vector<double>::size_type>::size_type p = 0;
             p+1 != v.size(); ++p)
        {
            cout << v[p]+adjustment << between;
        }
        cout << v.back()+adjustment;
    }
    cout << post;
    return;
}










/*
 * Supplanted by the remove all version...
 *
    inline
bool remove(vector<double> & vec, double remove_me)
{
    bool okay;
    vector<double>::size_type remove_here = locate(vec, remove_me);
    if (remove_here != vec.size())
    {
        okay = remove(vec, remove_here, remove_here+1);
    }
    else
    {
        okay = false;
    }
    return okay;
}
*/
