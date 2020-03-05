/*
 * Insertion Sort places each 'incoming' piece of data into
 * place within the already sorted portion of the list
 * ...often during entry of the vector/list's data.
 */
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/*
 * Place the new element into the head of the sub-vector
 * specified of the given vector.  The current element at
 * that position (as well as any which follow it) are
 * shifted toward the end of the sub-vector.  A value of
 * true will be returned if the sub-vector was non-empty;
 * false will be returned otherwise.
 */
bool insert(vector<short> & vec, vector<short>::size_type before_me,
            short new_item, vector<short>::size_type end);

// vector is placed into in sorted order -- non-ascending
// (decreasing)
void good_insertion(vector<short> & vec);

// for non-ascending list...
bool data_in_order(const vector<short> & vec);

int main(void)
{
    vector <short> data;
    short t;

    cout << "Enter your integers:  ";
    cin >> t;
    
    while ( ! cin.fail() )
    {
        data.push_back(t);
        cin >> t;
    }
    cin.clear();
    cout << "The program reaches here. ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //POTENTIAL ISSUE W/ PROGRAM
    cout << "The program does NOT reach here. ";


    if ( data_in_order(data) )
    {
        cout << "\nMiraculously, your data is already in order!\n";
    }
    else
    {

        cout << "\nYou entered:  '";
        for (vector<short>::size_type c = 0; c != data.size(); c++)
        {
            cout << data[c] << ' ';
        }
        cout << "'\n";

        good_insertion(data);

        if ( data_in_order(data) )
        {
            cout << "\nNow sorted it is:  '";
            for (vector<short>::size_type c = 0; c != data.size(); c++)
            {
                cout << data[c] << ' ';
            }
            cout << "'\n";
        }
        else
        {
            cout << "Something nasty happened!  Data could not be sorted!  *eek*"
                    "  Run for your lives!\a\n";
        }
    }

    return 0;
}

/*
 * Place the new element into the head of the sub-vector
 * specified of the given vector.  The current element at
 * that position (as well as any which follow it) are
 * shifted toward the end of the sub-vector.  A value of
 * true will be returned if the sub-vector was non-empty;
 * false will be returned otherwise.
 */
bool insert(vector<short> & vec, vector<short>::size_type before_me,
            short new_item, vector<short>::size_type end)
{
    bool okay = before_me < end;
    if (okay)
    {
        for (vector<short>::size_type pos = end; pos > before_me; pos--)
        {
            vec[pos] = vec[pos-1];
        }
        vec[before_me] = new_item;
    }
    return okay;
}

// vector is placed into in sorted order -- non-ascending
// (decreasing)
void good_insertion(vector<short> & vec)
{
    vector<short>::size_type next, dest;
    short holder;
    next = 1;                       // next unsorted item
    while (next < vec.size())
    {
        holder = vec[next];           // hold that
        dest = next;
        while (dest > 0 &&           // look amongst the already sorted
               vec[dest-1] < holder) // for where the new guy goes (in front)
        {
            --dest;
        }
        if (dest != next)               // not already in place?
        {
            insert(vec, dest, holder, next);    // insert 'im in front of dest
        }
        ++next;
    }
    return;
}
/*
 * The search for the next item's destination above could
 * have also been done from the opposite end of the sorted
 * area like so:
 *
        dest = 0;
        while (dest < next &&          // look amongst the already sorted
               vec[dest] > holder)     // for where the new guy goes (in front)
        {
            ++dest;
        }
 *
 * They both work, but searching from the beginning will
 * ruin insertion sort's stability (see the discussion of
 * merge sort elsewhere for more on stability).
 */

// for non-ascending list...
bool data_in_order(const vector<short> & vec)
{
    bool in_order = true;
    vector<short>::size_type pos = 0;
    while ( pos < vec.size()-1 && in_order )
    {
        in_order = in_order && vec[pos] >= vec[pos+1];
        ++pos;
    }
    return in_order;
}



//for more space on my MacBook screen
