/*
 * Object Oriented Programming in C++
 *
 *    -- OO Paradigm
 *    -- OO Technologies       *phbbt*
 *    -- OO Concepts
 *    -- OO Field              *bleah*
 *
 * Object-oriented programmers describe the data (focally;
 * oriented toward the data, that is) and what it does or
 * what can be done to it.  This is often done in an
 * anthropomorphic way -- personifying the data into a
 * human-like entity/creature.
 *
 * Note in our discussions of the cout & cin streams:  the
 * boatmen delivering cargo on the electric stream; their
 * crew members -- inserters and extractors and other
 * functions; the ninja in the rafters; and even the monkies
 * on the rail waving their little flags about formatting
 * issues.  (Let's all try to forget the 'flush' metaphor,
 * shall we...)
 *
 * strings could use imagery, as well, but it would involve
 * beads and jewelry at least somewhere and that seems
 * weird.
 *
 * *********************************************************
 *
 * C++ realizes the OO paradigm via its 'class' mechanism.
 * A class describes the members of a group (a class of
 * things; like in classification) in as general of terms as
 * possible/desirable.
 *
 * It will describe to the compiler the physical attributes
 * which make this class' members distinct from other
 * objects in the world as well as the behaviors in which
 * this class' members can participate.  The physical
 * attributes are represented by data -- member variables.
 * And the behaviors are represented by member functions --
 * also known as methods.
 *
 * C++ then treats this description as a data type -- just
 * like its built-in types.  (Recall the string class from
 * the standard libraries and that cin/cout/et al are
 * objects of classes defined in the standard libraries.)  A
 * class you create will be treated no differently than
 * those from the standard libraries -- it will be a data
 * type of which you can declare variables (objects or
 * instances of the class type).  You'll also be able to
 * assign those variables to one another -- changing their
 * values to be alike.  And, of course, you'll be able to
 * both pass and return information to/from functions.
 *
 * When you define class functions (aka methods; functions
 * specifically for the class), they can be called with
 * respect to a particular object using the dot (.) operator
 * just as you've done with cin/cout/string objects you've
 * declared.
 *
 * You can also refer to parts of the class generally rather
 * than with respect to a particular object using the scope
 * resolution (::) operator.  We've seen this several times
 * with string member types and constants and with constants
 * from the class ios_base used in output formatting.
 *
 * *********************************************************
 *
 * A ~fairly~ simple example we should all be familiar with
 * is the concept of a die.  You know, like you roll for a
 * turn of a game.  Mostly you are familiar with 6-sided
 * dice, but there are other sizes and shapes -- both
 * smaller and larger.  There are even ones whose pip-counts
 * aren't contiguous but jump by 2s or 3s.  Sometimes we
 * even want to adjust the values by a consistent amount up
 * or down.  Also having the die be virtual like this makes
 * it easier to make weird shapes like percentile or
 * 3-sided.
 *
 * For instance, if you were interested in a die that only
 * ever came up 2, 4, or 6, we could start with a 3-sided
 * die and multiply every value it came up with by 2.  If,
 * on the other hand, we were interested in a die that only
 * ever came up with 1, 3, or 5, we could start out the same
 * way as before and then subtract 1 from every result.
 *
 * Perhaps my favorite (so far) is a die that comes up -1/3,
 * 0, or 1/3.  This can be created with the 3-sided die
 * multiplied by 1/3 and then having 2/3 subtracted from
 * each value.
 *
 * As a C++ class, this might look something like the
 * following:
 */

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Die
{
//private:  // default access state for class members
    long sides;
    double scale, adjustment;
    /*
     * So all Die-type objects will be composed of a long
     * integer and two doubles.  These members can be
     * discussed generally as Die::sides, Die::scale, etc.,
     * but will more usefully be discussed as object.sides,
     * object.scale, etc. -- with respect to a particular
     * object of type Die.  Such an object might look like
     * so:
     *
     *       code            |              memory image
     *  ---------------------+-------------------------------------
     *     Die my_die,       |           +-----------------------+
     *         trans_die;    |           |         +------+      |
     *                       |           | sides   |      |      |
     *                       |           |         +------+      |
     *                       |           |         +-----------+ |
     *                       | my_die    | scale   |           | |
     *                       |           |         +-----------+ |
     *                       |           |         +-----------+ |
     *                       |           | adjust. |           | |
     *                       |           |         +-----------+ |
     *                       |           +-----------------------+
     *                       |           +-----------------------+
     *                       |           |         +------+      |
     *                       |           | sides   |      |      |
     *                       |           |         +------+      |
     *                       |           |         +-----------+ |
     *                       | trans_die | scale   |           | |
     *                       |           |         +-----------+ |
     *                       |           |         +-----------+ |
     *                       |           | adjust. |           | |
     *                       |           |         +-----------+ |
     *                       |           +-----------------------+
     *
     * We might label such a memory diagram with member
     * variable names and/or types during discussions as
     * well to help us visualize which data member is which.
     */

public:
    void print(void);   // display on screen (aka print, output, write, etc.)
    bool read(void);    // input from keyboard; true returned upon successful
                        //     input (aka input, entry, etc.)
    /*
     * class member functions (methods) will have access to
     * the member data of the calling object while
     * executing.  This data can be read or even changed at
     * the function's whim.
     *
     * That is, to call this print function of the class Die
     * (aka Die::print), the main program will have to have
     * declared a Die-type object like so:
     *
     *     Die my_die;
     *
     * And then they can call the Die::print function like
     * this:
     *
     *     my_die.print();
     *
     * And thus the print function will be able to access
     * the sides, adjustment, and scale member variables
     * within the my_die class object.
     *
     * How does Die::print's calling object come to have
     * values in it?  Probably via an earlier call to
     * Die::read like so:
     *
     *     my_die.read()
     *
     * And, since this function has a bool result, it could
     * have been used not just alone on a statement like
     * Die::print, but also within an if or while to decide
     * what to do when the read operation didn't succeed:
     *
     *     while ( ! my_die.read() )
     *     {
     *         // do something about the problem...
     *     }
     *
     * You can always use a helper bool to store the value
     * of the read() result:
     *
     *     success = my_die.read();
     *     while ( ! success )
     *     {
     *         // do something about the problem...
     *         success = my_die.read();
     *     }
     *
     * But is the extra variable worth the extra memory?
     * Probably not in the long run...
     */

    double min(void);   // provide statistics about this die's values
    double avg(void);   // upon being rolled; values may change due to
    double max(void);   // alteration of the member variables (say by
                        // the object being re-read)

    bool can_be_smaller(Die d);       // compare two Die objects
    bool can_be_larger(Die d);        // to see their potential
    bool is_typically_smaller(Die d); // and typical relationship
    bool is_typically_larger(Die d);  // to one another on the
    bool isSame(const Die & d);       // number line

    double roll(void);   // provide a typical roll of this Die

    // some functions are arithmetic in style -- not
    // altering the calling object but returning a new
    // object representing what would become of the calling
    // object under the specified operation; see, for
    // instance, to___er() from cctype
    Die scale_by(double applied_scale);
    Die translate(double applied_adjustment);
    Die change_shape(long new_sides);
};

/*
 * Remember -- at all times -- that a variable of a class
 * type (an object) is an individual member of that group.
 * When I have a Die whose member variables are sides=6,
 * scale=1.0, and adjustment=0.0, I've chosen a particular
 * die from the bag or box where I keep my dice.  (This is
 * also refered to as an instance of the class, but that
 * doesn't make sense to as many people as saying that 'Fifi
 * the poodle' is an individual dog from the group of all
 * dogs.)
 *
 * In a program, we might use the Die class like this:
 */

inline void stat_block(Die d)
{
    cout << "\nWhen you roll ";
    d.print();
    cout << " you might get " << d.roll() << ".\n"
            "Whatever it is, it will always be between " << d.min()
         << " and " << d.max() << "\nand be centered around "
         << d.avg() << ".\n";
    return;
}

int main(void)
{
    Die my_die, trans_die, scaled_die, both_adj_die, shaped_die;
    double offset, scaling_factor;
    long size;

    srand(static_cast<unsigned>(time(nullptr)));

    //my_die.sides = 4;         // can't access private members from outside class
    //if (my_die.scale <= 4.2)
    //cout << my_die.adjustment;

    cout << "What are the parameters of your die (dS~M+A)?  ";
    my_die.read();
    while ( cin.fail() )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\n\aInvalid parameter set!  Please try again!\n";
        cout << "What are the parameters of your die (dS~M+A)?  ";
        my_die.read();
    }
    /*
     * But this loop doesn't account for the Die's own
     * interpretation of events.  It only accounts for cin's
     * interpretation.  cin would just as happily read
     * "&S-M@A" rather than the requested notation.  cin
     * only cares that the numbers came in successfully!  To
     * take the notation into account, we'd have to inspect
     * the bool result of the Die::read function like so:
        cout << "What are the parameters of your die (dS~M+A)?  ";
        while ( ! my_die.read() )  // validate this, too; with a more OO approach
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\n\aInvalid parameter set!  Please try again!\n";
            cout << "What are the parameters of your die (dS~M+A)?  ";
        }
     */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    stat_block(my_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nHow far would you like to move the die's range?  ";
    cin >> offset;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    trans_die = my_die.translate(offset);

    stat_block(trans_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nBy how much would you like to scale the die's values?  ";
    cin >> scaling_factor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    scaled_die = my_die.scale_by(scaling_factor);

    both_adj_die = trans_die.scale_by(scaling_factor);

    cout << "\nWith only the scaling of the original:\n";
    stat_block(scaled_die);

    cout << "\nWith both scaling and translation of the original:\n";
    stat_block(both_adj_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nWhat new shape would you like to give this die?  ";
    cin >> size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    shaped_die = my_die.change_shape(size);

    cout << "\nWith only the shape affected:\n";
    stat_block(shaped_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if ( my_die.is_typically_smaller(trans_die) )
    {
        cerr << "\n\aTranslation was non-negative!\n";
        if ( trans_die.is_typically_larger(my_die) )
        {
            cerr << "\n\aStraight translation was definitely to the right...\n";
        }
        else
        {
            cerr << "\n\aTranslation didn't actually move!\n";
        }
    }
    else if ( my_die.isSame(trans_die) )
    {
        cerr << "\n\aTranslation was nil!\n";
    }
    else
    {
        cerr << "\n\aTranslation was negative!\n";
    }
    if ( my_die.can_be_smaller(trans_die) )
    {
        cerr << "\n\aTranslation was non-negative!\n";
        if ( trans_die.can_be_larger(my_die) )
        {
            cerr << "\n\aStraight translation was definitely to the right...\n";
        }
        else
        {
            cerr << "\n\aTranslation didn't actually move!\n";
        }
    }
    else if ( my_die.isSame(trans_die) )
    {
        cerr << "\n\aTranslation was nil!\n";
    }
    else
    {
        cerr << "\n\aTranslation was negative!\n";
    }

    return 0;
}

void Die::print(void)
{
    cout << 'd' << sides << '~' << scale << (adjustment >= 0.0 ? "+" : "")
         << adjustment;
    return;
}






bool Die::read(void)
{
    char t; //, t2, t3;
                      // t2            t3
    cin >> t >> sides >> t >> scale >> t >> adjustment;
    if ( t == '-' )   // t3
    {
        adjustment = -adjustment;
    }
    return !cin.fail(); // && t == 'd' && t2 == '~' && (t3 == '+' || t3 == '-');
}















double Die::roll(void)
{
    return static_cast<double>(rand() % sides + 1) * scale + adjustment;
}

double Die::min(void)
{
    return scale + adjustment;
}

double Die::max(void)
{
    return static_cast<double>(sides) * scale + adjustment;
}

double Die::avg(void)
{
    return (min() + max()) / 2;
}

Die Die::scale_by(double applied_scale)
{
    Die sd;
    sd.sides = sides;
    sd.adjustment = adjustment;
    sd.scale = scale * applied_scale;  // what if they scale by 0.0?!
    return sd;
}

Die Die::translate(double applied_adjustment)
{
    Die td;
    td.sides = sides;
    td.scale = scale;
    td.adjustment = adjustment + applied_adjustment;
    return td;
}

Die Die::change_shape(long new_sides)
{
    Die cd;
    cd.scale = scale;
    cd.adjustment = adjustment;
    cd.sides = new_sides;             // what if this is 0 or negative?!
    return cd;
}

bool Die::is_typically_smaller(Die d)
{
    return avg() < d.avg();
}

bool Die::can_be_smaller(Die d)
{
    return min() < d.min();
}

bool Die::is_typically_larger(Die d)
{
    return avg() > d.avg();
}

bool Die::can_be_larger(Die d)
{
    return max() > d.max();
}

bool Die::isSame(const Die & d)
{
    return sides == d.sides &&
           fabs(scale - d.scale) <= 1e-6 &&
           fabs(adjustment - d.adjustment) <= 1e-6;
}
