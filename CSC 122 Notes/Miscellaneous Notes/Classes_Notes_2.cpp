/*
 * Object Oriented Programming in C++ -- Part II
 *
 * The class design from Part I was perfectly fine, but not
 * as flexible as we'd like it to be.  There could be
 * situations which would prevent its easy re-use.  For
 * instance, the programmer might want to create an object
 * to represent a particular die to roll -- maybe the
 * origin.  The current class depends on the end-user for
 * input of die parameters -- not the programmer.
 *
 * Or the programmer might want to alter the parameters of
 * a die before display, but the only way to create a
 * die having different parameters would be to 'read' it
 * from the end-user or to calculate a scaling or translation
 * of a die originally entered by the end-user.
 *
 * Or the programmer might want to send the parameters of a
 * die to a graphical display device -- drawing the
 * die to be part of some kind of visual rolling.  We don't
 * have any such capability -- and I certainly don't plan to
 * put it in.  We need some way for our system to be
 * semi-transparent to the private data.  (We still don't
 * want to allow arbitrary change, but anyone should be able
 * to look at our privates, right?)
 *
 * Or the programmer might want to take mouse clicks from a
 * GUI and convert them to die parameters.  (Sliders or
 * drop-down selections or whatever...) Again, I'm not going
 * to code for that.  So we need a way for the programmer to
 * store reasonable values within a class object.
 *
 * To make our classes more re-usable, we will want to make
 * the following additions:
 *
 *    -- constructors
 *    -- accessors and mutators
 *
 * In addition to the programmer using the class gaining
 * flexibility, we as class implementers will be able to
 * make our code much more efficiently using these
 * facilities.  (Well, not the accessors, those are only for
 * the out-of-class programmers.)
 *
 * *******************************************************************
 *
 * Accessors allow the programmer to 'access' the data in
 * their objects by returning to them a copy of the member
 * variable values.  This is necessitated by the whole
 * private/public access specifier thing.  However, it also
 * has the advantage of allowing programmers to do things
 * with our class type that we haven't anticipated -- or
 * simply don't want to deal with.
 *
 * For instance, if the programmer wants to visualize a Die
 * on a graphics display, they can access the member
 * parameters with our accessors and send them on to the
 * graphics routines for displaying the Die's proper face
 * values.  We don't have to deal with graphics cards,
 * device drivers, kernel modules, window coordinate
 * systems, clipping, scaling, etc.
 *
 * *******************************************************************
 *
 * Mutators 'mutate' the values in a class object to those
 * the programmer who declared the object desires -- maybe.
 * Mutators are the very heart of the private/public access
 * specifier thing.  Without them, it would all break down
 * into chaos and mayhem pretty quickly!  These special
 * functions provide a centralized place to code error
 * checking, data validity assurance testing, and/or
 * anything else we want to enforce as far as the data goes.
 * Some even say it makes a programmer think twice before
 * making a change to the data because they must call a
 * function rather than use a simple assignment statement.
 * Maybe they'll think better of it or simply think more
 * clearly about what value they want to change it to.
 *
 * Although a die's adjustment doesn't really have much in
 * the way of error checks or validity tests we can perform,
 * the sides and scale can.  Other simple class types do,
 * too:
 *
 *    -- you wouldn't want the denominator of a rational
 *       number class to become zero (0)
 *    -- you wouldn't want to have a time-of-day be set to
 *       29:-41
 *    -- you wouldn't want to have an alarm set for -28945
 *       seconds in the future
 *
 * When a mutator cannot make a change validly, it should
 * just ignore the programmer making the attempted change or
 * return to them a false value to indicate the change
 * couldn't be made.  (Then it is their problem for not
 * checking the mutator return value, right?)
 *
 * Even though die adjustments don't allow for much in the
 * way of error checks, they do represent another aspect of
 * mutator use -- simply changing the member data in ways we
 * didn't anticipate (or don't want to deal with).  If the
 * programmer is dealing with a graphical interface and
 * receives mouse clicks which represent somehow the
 * parameters of a die, they can store those into a Die
 * object for holding or other uses (like averaging or
 * relative positioning on the number line or even
 * scaling!).
 *
 * *******************************************************************
 *
 * Constructors are special methods (functions inside the
 * class) that let the programmer creating an object of our
 * class type initialize it properly at declaration.  Recall
 * that string class objects can be initialized in several
 * ways:
 *
 *     string s;    // no special initial value -- defaults to empty
 *
 *     string t("Bob"),        // initialize to literal string value
 *            v = "Bob, too",  // initialize to literal string value
 *            m{"Also Bob"};   // initialize to literal string value
 *
 *     string u(42, '&');   // initialize as 42 ampersands
 *
 *     string q = u,    // initialize as a copy of u
 *            r(v),     // initialize as a copy of v
 *            n{m};     // initialize as a copy of m
 *
 * We can make our class objects behave in similar ways.
 * (Albeit appropriate to the class we are creating, of
 * course.  None of this string and char non-sense for a
 * die to be rolled.  *grin*)
 *
 * *******************************************************************
 *
 * We can even use a class name with a parentheses enclosed list of
 * comma-separated initializers to create an anonymous object:
 *
 *     string()         // a default object
 *     string("Bob")    // a string object containing Bob
 *     string(42, '&')  // a string object repeating & 42 times
 *     string(s)        // a string object exactly like the named object s
 *
 * The middle two forms are more prominent, of course.
 *
 * *******************************************************************
 *
 * Constructors are automatically called by the compiler
 * when an object is instantiated of our class (a variable
 * is declared of our type).  Which constructor to call
 * depends on what arguments are specified:
 *
 *     no arguments                                ==> default constructor
 *     a [const] reference to another class object ==> copy constructor
 *     other arguments                             ==> appropriate constructor overload
 *
 * So, as you can see, the types and number of arguments
 * passed to a constructor determine what kind of
 * constructor it is (default, copy, or otherwise).
 * Constructors must be overloaded to distinguish from one
 * another.  Why?  Because constructors must also be named
 * after the class they construct.  (All string class
 * constructors are named 'string', for instance.  And all
 * our Die class' constructors will be named 'Die'.)
 *
 */

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// helper bool consts for the ctor below
const bool CHANGE_SCALE = true,
           CHANGE_ADJUST = false;

class Die
{
    long sides;
    double scale, adjustment;

public:

// constructors -- every class should have at least three (3)
    Die(void);                    // default ctor
    Die(const Die & d);           // copy ctor
    // other ctors don't have special names but just
    // overload the call signature
    Die(long new_sides);
    Die(long new_sides, double new_scale, double new_adjustment);
    Die(long new_sides, double new_alterer, bool is_scaling);
    // this one needs help since constructing with either
    // sides and scale or with sides and adjustment would
    // both be "long,double" signatures; so we combine them
    // with a helping bool argument to tell them apart; also
    // note the constants above to help the caller specify
    // their intent clearly













// accessors -- every class should have some
    long get_sides(void);
    double get_scale(void);
    double get_adjustment(void);
    /*
     * Named get_ and member variable to indicate that the
     * programmer who owns the class object is trying to get
     * a copy of the member variable's value.  (This is only
     * a typical pattern and not a hard-and-fast rule, but
     * it does make them easier to spot.)
     */












// mutators -- every class should have some
    bool set_sides(long new_sides);
    bool set_scale(double new_scale);
    bool set_adjustment(double new_adjustment);
    /*
     * Named set_ and member variable to indicate that the
     * programmer who owns the class object is trying to set
     * a new value into the member variable.  (This is only
     * a typical pattern and not a hard-and-fast rule, but
     * it does make them easier to spot.)
     */








// input/output functions -- every class should have some
    void print(void);   // display on screen (aka print, output, write, etc.)
    bool read(void);    // input from keyboard; true returned upon successful
                        //     input (aka input, entry, etc.)

// utility/helper functions specific to the class and its purpose
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

    Die scale_by(double applied_scale);
    Die translate(double applied_adjustment);
    Die change_shape(long new_sides);
};

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
    /*
     * Other constructions might look like these:
     *
     *     Die obj1{42},     // create a 42-sided die
     *         obj2{3,.5,2}, // create a 3-sided die with scale .5 and offset 2
     *         obj3{8,2,CHANGE_ADJUST};  // create an 8-sided die with default
     *                                   // scale and adjustment 2
     */
    double offset, scaling_factor;
    long size;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "What are the parameters of your die (dS~M+A)?  ";
    while ( ! my_die.read() )  // validate input with an OO approach
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\n\aInvalid parameter set!  Please try again!\n";
        cout << "What are the parameters of your die (dS~M+A)?  ";
    }
    /*
     * Or, if you really can't stand the Die::read call in
     * the while head, you could make a helper bool:
     *
        bool valid;
        cout << "What are the parameters of your die (dS~M+A)?  ";
        valid = my_die.read();
        while ( ! valid )  // validate input with a less elegant,
        {                  // but still OO approach
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\n\aInvalid parameter set!  Please try again!\n";
            cout << "What are the parameters of your die (dS~M+A)?  ";
            valid = my_die.read();
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

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if ( my_die.set_sides( my_die.get_sides() - 2 ) )
    {
        cout << "\nReduced sides by 2...\n";
    }
    else
    {
        if ( my_die.set_sides( my_die.get_sides() + 2 ) )
        {
            cout << "\nIncreased sides by 2...\n";
        }
        else
        {
            cout << "\nWhat kind of freaky die did you make here?!\n";
        }
    }
    stat_block(my_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*
     * note that Die::scale_by(a) is akin to
     * Die::set_scale(Die::get_scale()*a)
     * even though one is a sub/superset of the other, we
     * should test them both since they are not implemented
     * to call on one another; we won't be able to do that
     * until next semester...
     */

    if ( my_die.set_scale( 1.0/3 ) )
    {
        cout << "\nSet scale to thirds...\n";
    }
    else
    {
        cerr << "\n\aCould not change scale to thirds!!!\n";
    }
    if ( my_die.set_scale( 0.0 ) )
    {
        cerr << "\n\aSet scale to zero!!!\n";
    }
    else
    {
        cout << "\nCould not change scale to zero...\n";
    }
    stat_block(my_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*
     * similarly for Die::translate(a) and
     * Die::set_adjustment(Die::get_adjustment()+a)...
     */
    if ( my_die.set_adjustment( static_cast<double>(-my_die.get_sides())/2.0/3 ) )
    {
        cout << "\nSet adjustment to be [just under] half negative...\n";
    }
    else
    {
        cerr << "\n\aCould not change adjustment!!!\n";
    }
    stat_block(my_die);

    cout << "Press Enter to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}

void Die::print(void)
{
    cout << 'd' << sides << '~' << scale << (adjustment >= 0.0 ? "+" : "")
         << adjustment;
    return;
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
    //Die sd;
    /*sd.sides = sides;
    sd.adjustment = adjustment;
    sd.scale = scale * applied_scale;*//*
    sd.set_sides(sides);
    sd.set_adjustment(adjustment);
    sd.set_scale(scale * applied_scale);*/
    Die sd(sides, scale * applied_scale, adjustment);
    return sd;
}

Die Die::translate(double applied_adjustment)
{
    Die td(sides, scale, adjustment + applied_adjustment);
    return td;
}

Die Die::change_shape(long new_sides)
{
    Die cd(new_sides, scale, adjustment);
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





/*
 * CONSTRUCTORS!!!
 *
 * Here is our default constructor (ctor).  It fills in the
 * member variables when no data was provided by the
 * declaring programmer.
 */
Die::Die(void)
{
    sides = 6;
    scale = 1.0;
    adjustment = 0.0;
}
/*
 * Notice the lack of a return type or statement!  This is
 * because all constructors automatically return [a
 * reference to] the object being constructed.  (This object
 * is considered our calling object, btw.)  To maintain
 * consistency and avoid mistakes, this behavior was deigned
 * best provided automatically by the compiler rather than
 * individual programmers.  (Programmers tend to get
 * 'creative' and do things 'cleverly' when you least expect
 * it...)
 */





/*
 * The copy ctor is called whenever an object is created as
 * a copy of another object that already exists:
 *
 *     Die     P;
 *     . . .
 *     Die     Q = P,  // Q is created as a copy of P
 *             R(P),   // R is created as a copy of P
 *             S{P};   // S is created as a copy of P
 *
 * The three syntaxes (syntaces?) are mere conveniences and
 * work the same way -- all call the same copy ctor.
 *
 * Although this is not often coded as above (it can happen,
 * but isn't prevalent), there are two other places where
 * the compiler needs to make copies of objects
 * automatically for us:  pass by value arguments and return
 * [by value] results.  That is, the returned value is
 * created as a copy of the return expression's value.  For
 * instance, the Die::scale_by function returns its result
 * by value and thus must make a copy of the local object
 * (sd) to give back to the caller since sd will shortly be
 * destroyed as the function ceases to exist!
 *
 * Similarly, the formal argument is created as a copy of
 * the actual argument during a pass by value.  This is done
 * from time to time, but we usually try to pass class
 * objects by constant reference instead of by value.  This
 * avoids the extra memory and the time taken to make the
 * copy.  Now that we have a name for all of that, we can
 * say that it avoids calling the copy constructor!
 */
Die::Die(const Die & d)
{
    sides = d.sides;
    scale = d.scale;
    adjustment = d.adjustment;
}

/*
 * Both of the above ctors showed that trusted values don't
 * have to be mutated.  But now we start receiving values
 * from outside the class -- data that cannot be trusted.
 * This data should always be mutated to ensure our safety!
 */
Die::Die(long new_sides)
{
    sides = 6;               // ensures object has valid data even if new_sides is crap
    set_sides(new_sides);
    scale = 1.0;
    adjustment = 0.0;
}

Die::Die(long new_sides, double new_alterer, bool is_scaling)
{
    sides = 6;
    scale = 1.0;
    adjustment = 0.0;
    if (set_sides(new_sides))
    {
        if ( is_scaling )
        {
            set_scale(new_alterer);
        }
        else
        {
            set_adjustment(new_alterer);
        }
    }
}

Die::Die(long new_sides, double new_scale, double new_adjustment)
{
    sides = 6;
    scale = 1.0;
    adjustment = 0.0;
    set_sides(new_sides) &&
    set_scale(new_scale) &&
    set_adjustment(new_adjustment);
}

/*
 * Keep in mind that constructors are special in that there
 * can be no return statement since the object being
 * constructed (the calling object) is automatically
 * returned from the constructor by the compiler.
 */






/*
 * ACCESSORS!
 *
 * Again, accessors are rarely used from inside the class --
 * only by programmers outside the class.  We can get to the
 * private data inside the class whenever we want, after
 * all.
 */
long Die::get_sides(void)
{
    return sides;
}

double Die::get_scale(void)
{
    return scale;
}

double Die::get_adjustment(void)
{
    return adjustment;
}





/* 
 * MUTATOR design:
 *
 *     bool okay = false;
 *     if (   argument data is valid   )
 *     {
 *         member = argument;
 *         okay = true;
 *     }
 *     return okay;
 */
bool Die::set_sides(long new_sides)
{
    bool okay = false;
    if ( new_sides >= 1 )
    {
        sides = new_sides;
        okay = true;
    }
    return okay;
}

/*
 * The adjustment has no bad values -- except a few values
 * for the double type itself (inf, -inf, NaN).  These can
 * be difficult to check for depending on your compiler and
 * library version/implementation:
 *
 * TODO:  code for testing infinities and NaN...
 *
 * cmath now has functions isinf and isnan that check for
 * infinity and NaN values:
 *
 *    if ( ! isinf(new_adjustment) && ! isnan(new_adjustment) )
 *    {
 *        adjustment = new_adjustment;
 *        okay = true;
 *    }
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * The infinities are tricky, but NaN has a CPU-based way to
 * check.  Only the NaN bit-pattern is unequal to itself!
 *
 *   // only NaN is not equal to itself
 *   if (new_adjustment == new_adjustment)
 *   {
 *       adjustment = new_adjustment;
 *       okay = true;
 *   }
 *
 * But the compiler doesn't like to do == (or !=) on
 * floating-point data.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * To tell the compiler to shut up about this warning for
 * this specific code, we could use a pragma:
 *
 * #pragma SOMETHING HERE TO TURN DOUBLE== WARNING OFF
 *    if (new_adjustment == new_adjustment)  // only NaN is not equal to itself
 *    {
 *        adjustment = new_adjustment;
 *        okay = true;
 *    }
 * #pragma SOMETHING HERE TO TURN DOUBLE== WARNING BACK ON
 *
 * But the SOMETHING will vary from compiler to compiler and
 * sometimes even from version to version of the same
 * compiler.  (Sometimes it is hard to find even with Google
 * and knowing the basic form of what you are looking for!)
 *
 */
bool Die::set_scale(double new_scale)
{
    bool okay = false;
    if ( fabs(new_scale) > 1e-6 &&   // new_scale != 0.0
         ! isinf(new_scale) && ! isnan(new_scale) )  // not crap, either
    {
        scale = new_scale;
        okay = true;
    }
    return okay;
}

bool Die::set_adjustment(double new_adjustment)
{
    bool okay = false;
    if ( ! isinf(new_adjustment) && ! isnan(new_adjustment) )
    {
        adjustment = new_adjustment;
        okay = true;
    }
    return okay;
}

/*
 *
 * But not to worry, even though we can't do error checking
 * here, this isn't all that unusual.  We often have data we
 * cannot validate at all!  Peoples names, for instance,
 * cannot be validated.  Are you seriously going to tell
 * them that that isn't their name or that they've spelled
 * it wrong or something?  *phbbt*  Good luck!
 *
 * So the base pattern in these situations is this:
 *
 *     member = argument;
 *     return true;
 *
 * We keep the overall bool return pattern for consistency
 * of design and use -- even though it isn't useful here.
 */
/*
 * Some data types call for grouped mutation schemes rather
 * than individual mutators for each data member.  For
 * instance look at a Rational number class.  It has a
 * numerator and a denominator linked in an implicit
 * division relationship.  There is also the common and
 * programmatically sensible idea of keeping a fraction in
 * 'lowest terms' -- cancelling out any common divisors
 * between the numerator and denominator.  Let's say that
 * such a rational number object is currently 4/15 and the
 * programmer wants it to be 3/7 instead.  If we coded
 * separate set_numer and set_denom functions, they'd end up
 * with 1/7 instead:
 *
 *     obj.set_numer(3);  // 3 cancels with 15 to form 1/5
 *     obj.set_denom(7);  // no cancellation, now 1/7
 *
 * In order to make this work out correctly, we really need
 * to mutate these two members at the same time.  Any change
 * to one, after all, will change the other because of the
 * cancellation effect:
 *
 *     obj.set(3,7);    // okay, all set together:  3/7
 *
 * If the caller doesn't need one of them to change
 * specifically, they can always call like this:
 *
 *     obj.set(numer, obj.get_denom());
 */

/*
 * Note that the input function is the most egregious place
 * to forget to mutate!  If we don't trust data coming from
 * another programmer in a ctor, we certainly don't trust
 * data coming from a L-user!
 */
bool Die::read(void)
{
    char d, s, a;
    long sds;
    double scl, adj;
    cin >> d >> sds >> s >> scl >> a >> adj;
    if ( a == '-' )
    {
        adj = -adj;
    }
    return !cin.fail() &&
           d == 'd' && s == '~' && (a == '+' || a == '-') &&
           set_sides(sds) && set_scale(scl) && set_adjustment(adj);
}

/*
 * The result of the above &&'d set_* calls is that we'll
 * have a partially valid object at times.  We'd rather have
 * a consistent object at all times -- all valid or all
 * invalid.
 *
 * For instance, if sds, scl, and adj are all fine, the
 * class is in a consistently valid state and we are happy.
 * Even if sds fails to initialize -- returning false, we'll
 * end up in a consistently invalid state since neither of
 * scl nor adj will even be attempted to mutate.  But
 * consistent is good so we are still happy.
 *
 * But if adj were invalid, the class would be only 2/3
 * valid -- making us unhappy.  Worse yet, if scl is invalid
 * we'll fail to even test adj and end up with a 2/3 invalid
 * object.  Of the 8 possible scenarios -- each value can be
 * validly or invalidly entered -- we have only two
 * consistent states and 6 inconsistent ones.  (In fact,
 * there will always be only two consistent states and 2^n - 2
 * inconsistent ones where there are n member variables in
 * the class.  The only good situation for us is when there
 * is only one member variable such that there are no
 * inconsistent states!  But this happens quite rarely
 * so...)
 *
 * But having that consistency would mean a whole new layer
 * of function abstraction -- decoupling the validity tests
 * and the setting of member variables' values -- and
 * therefore lots of more complicated code.  Maybe another
 * semester...
 */
