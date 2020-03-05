/*
 * Up To Now
 ************************************************************
 * class members of built-in types typically have an
 * accessor and mutator each, no special helpers, and are
 * parameterized in the extra constructor for the class.
 * Members of a class type (including string) are handled
 * similarly.  (Our only exception is when there is a
 * binding/intimate relationship between two (or more)
 * members such that altering one will have an impact on the
 * other(s).  In such cases, we use a common mutator for the
 * related members rather than separate ones for each
 * member.)
 *
 * For example, this class representing students in a course
 * tracks the students' names as well as their individual
 * grades:
 *
 *     class Student
 *     {
 *         string name;
 *         vector<double> grades;
 *         // ...
 *     };
 *
 *
 * Here are sample accessor and mutator methods for a string
 * member of a class:
 *
 *     string get_name(void) const
 *     {
 *         return name;
 *     }
 *
 *     bool set_name(const string & n)
 *     {
 *         name = n;                // normally we'd error check here,
 *         return true;             // but names are not really validatable
 *     }
 *
 * Constructors, likewise need to treat the member variable
 * in their member initialization list:
 *
 *     Student(void) : name() { }
 *     Student(const Student & c) : name(c.name) { }
 *     Student(const string & n) : name() { set_name(n); }
 *
 * But Now
 ************************************************************
 * If a class has a member which is of a vector type,
 * however, we are dealing with data of a different ilk
 * altogether!  The built-in types and class types (even
 * string) all mean to have objects of their type taken as
 * single items.  A vector, on the other hand, is meant to
 * be a sequence of ~individual~ items.  Therefore, the
 * accessor and mutator patterns for vector type members of
 * a class must take this collective/individual nature into
 * account.
 *
 * The simplest way to do so is to have the accessor and
 * mutator for the vector member each take a size_type
 * parameter to designate which item in the vector's
 * sequence the caller wishes to access/mutate.  Notice the
 * difference between the name (above) and grades members
 * with respect to their access patterns:
 *
 *     double get_grade(vector<double>::size_type which) const
 *     {
 *         return which < get_grade_count()     // grades.size()
 *              ? grades[which]
 *              : -1.0;                         // or some flag
 *     }
 *     vector<double>::size_type get_grade_count(void) const
 *     {
 *         return grades.size();
 *     }
 *
 * The string member -- name -- was accessed as a single
 * entity/thing.  The vector member -- grades -- is accessed
 * item by item.  If a grade we don't own is accessed, we
 * report its value to be -1.0 so that the careful
 * programmer ~can~ notice that something has gone awry.  In
 * addition, we provide a helper function which returns the
 * number of items in the grades vector to the programmer
 * using this class (probably calling the get_grade() method
 * in a for loop bounded, hopefully, by a call to
 * get_grade_count() to avoid running into that -1.0 value).
 *
 ****************************************************************
 *
 * Note how the get_grade() validates the which argument by
 * calling the get_grade_count() function rather than
 * directly calling the grades.size() function.  This
 * protects us from any underlying change in the
 * implementation of the grades data.  Right now vector may
 * be our only choice, but next semester or the one after
 * that we may decide to change to a different storage
 * medium.  Then there may be a different way to find out
 * the number of grades than '.size()'.  By calling on
 * get_grade_count(), we limit our reliance on
 * implementation knowledge and isolate those details into
 * individual functions.
 *
 * In fact, if I was really pushing this, I'd have begun our
 * class with a typedef as well:
 *
 *     class Student
 *     {
 *         string name;
 *         vector<double> grades;
 *     public:
 *         typedef vector<double>::size_type GradePos;  // GradeSize?
 *
 *         double get_grade(GradePos which) const;
 *         GradePos get_grade_count(void) const;
 *     };
 *
 * Now the functions themselves are protected from any
 * change in the underlying data storage technique with this
 * typedef name.  The programmer using our class just has to
 * refer to Student::GradePos rather than
 * vector<double>::size_type whenever they are talking about
 * a particular grade within the student's record.
 *
 * In fact, this is exactly the mechanism by which and
 * pretty much the reason why the vector and string classes
 * do this themselves!
 *
 * But perhaps I digress...
 *
 ******************************************************************
 *
 * Mutation patterns are similarly adjusted.  Note again the
 * difference between the name mutator above and this
 * mutator/helper pair for the grades member:
 *
 *     bool set_grade(vector<double>::size_type which, double g)
 *     {
 *         bool okay = false;
 *         if ( which < get_grade_count() )
 *         {
 *             grades[which] = g;   // validate element itself?
 *             okay = true;
 *         }
 *         else if ( which == get_grade_count() )
 *         {
 *             okay = add_grade(g);
 *         }
 *         return okay;
 *     }
 *
 *     bool add_grade(double g)
 *     {
 *         vector<double>::size_type old_size = get_grade_count();
 *         grades.push_back(g);   // validate element itself?
 *         return old_size < get_grade_count();
 *     }
 *
 * Notice that the string member -- name -- was mutated all
 * at once whereas the vector member -- grades -- is mutated
 * on an item-by-item basis.  It even requires a helper
 * function to add new items to the vector.  (It takes the
 * gentlemanly route of calling the add_grades() method when
 * the caller tries to modify the next grade that ~would~
 * exist.  The alternative would be to skip the else-if
 * branch altogether and just have the if branch and
 * return.)
 *
 ***************************************************************
 *
 * Finally, constructor patterns for a vector element.
 * These are oddly simpler than other types of members.
 * Because the class is assumed to manage the vector member
 * for its entire life-time, we don't typically need to
 * construct in other than an empty manner.  The one
 * different case -- copy construction -- is handled nicely
 * by the vector's own copy constructor.  For instance:
 *
 *     Student(void) : name(), grades() { }
 *     Student(const Student & c) : name(c.name), grades(c.grades) { }
 *
 * And we don't have a constructor to take in a vector from
 * the outside.  If you do have other members which need
 * construction, just default construct the vector member in
 * their alternative constructor's member initialization
 * list:
 *
 *     Student(const string & n) : name(), grades() { set_name(n); }
 *
 * Here I've assumed we have both a name string member and a
 * grades vector member.  The name can be initialized via a
 * parameter, but the grades cannot.  We will manage the
 * grades vector from inception to death.
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Student
{
    string name;
    vector<double> grades;

public:
    Student(void)
        : name(), grades()
    {
    }
    Student(const Student & s)
        : name(s.name), grades(s.grades)
    {
    }
    Student(const string & n)
        : name(), grades()
    {
        set_name(n);
    }

    bool input(void);
    void output(void) const;

    string get_name(void) const
    {
        return name;
    }
    double get_grade(vector<double>::size_type which) const
    {
        return which < get_grade_count() ? grades[which] : -1.0;
    }
    vector<double>::size_type get_grade_count(void) const
    {
        return grades.size();
    }

    bool set_name(const string & n)  // could maybe apply a name-case-ing here
    {
        name = n;
        return true;
    }
    bool set_grade(vector<double>::size_type which, double g)
    {
        bool okay = false;
        if ( which < get_grade_count() )
        {
            grades[which] = g;                // could check for >= 0.0 grade
            okay = true;
        }
        else if ( which == get_grade_count() )
        {
            okay = add_grade(g);
        }
        return okay;
    }
    bool add_grade(double g)
    {
        vector<double>::size_type old_size = get_grade_count();
        grades.push_back(g);                // could check for >= 0.0 grade
        return old_size < get_grade_count();
    }

    double get_average(void) const
    {
        double s = 0.0;
        for (vector<double>::size_type g = 0; g != get_grade_count(); ++g)
        {
            s += grades[g];
        }
        return s / get_grade_count();   // NaN returned if no grades -- statistically valid!
    }
};

int main(void)
{
    Student stu;
    string name;
    double grade;

    cout << "Enter student's name:  ";
    getline(cin, name);
    stu.set_name(name);

    name = stu.get_name();
    cout << "Enter " << name << '\'' // "'"
         << (name.back() == 's' ? "" : "s")
         << " grades ('quit' to end):\n";
    cin >> grade;
    while ( ! cin.fail() )
    {
        stu.add_grade(grade);
        cin >> grade;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << stu.get_name() << " earned a " << stu.get_average() << " on their "
         << stu.get_grade_count() << " score"
         << (stu.get_grade_count()==1 ? "" : "s") << ".\n";

    return 0;
}

void Student::output(void) const
{
    cout << name << '\n';
    if (!grades.empty())
    {
        for (vector<double>::size_type g = 0; g+1 != get_grade_count(); ++g)
        {
            cout << grades[g] << ' ';
        }
        cout << grades.back() << '\n';
    }
    else
    {
        cout << "No grades\n";
    }
    return;
}

bool Student::input(void)
{
    double g;
    string n;
    getline(cin, n);
    set_name(n);
    cin >> g;
    while ( cin.peek() != '\n' && !cin.fail() )
    {
        add_grade(g);
        cin >> g;
    }
    if (cin.fail())
    {
        cin.clear();                  // defaults to goodbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear(ios_base::failbit);  // can also do badbit or eofbit
    }
    else   // cin.peek() == '\n'
    {
        add_grade(g);  // last grade -- no failure...
    }
    return !cin.fail();
}
