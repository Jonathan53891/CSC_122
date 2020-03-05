/*
 * Object Oriented Programming in C++ -- Part III
 *
 * Fine tuning the class mechanism to work in a speedier,
 * leaner, more secure, and more elegant fashion is our next
 * goal.  Five steps are to be taken here:
 * 
 *   - member initialization lists for constructors
 *     (note the warnings you've gotten so far)
 *
 *   - inline'ing class methods when appropriate
 *     (it's easier than for normal functions!)
 *
 *   - RVO (or return value optimization;
 *     makes returning a class object by value from a
 *     function much more efficient -- see diagram)
 *
 *   - proper declaration of const-ness for class methods
 *
 *   - chaining method calls is considered quite
 *     object-oriented and elegant, too
 */

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// helper bool consts for the ctor below
const bool ALTERER_IS_FOR_SCALE = true,
           ALTERER_IS_FOR_ADJUST = false;

class Die
{
    long sides;
    double scale, adjustment;

public:

// input/output functions -- every class should have some
    void print(void) const;    // could be inline, but see 
                               /* using the const here will make sure that the 
                                  thing being called will not be changed */
    
    bool read(void);           // below for clarification

/*
 * To inline a class method, simply define it instead of
 * prototyping it within your class definition.  The
 * compiler takes the definition of a function within the
 * class definition as an automatic suggestion to inline the
 * function -- because you wouldn't possibly clutter your
 * class defn with a function defn if it weren't simple,
 * short, etc. like an inline function should be!  The
 * inline keyword is NOT required here.  (*bounce*)
 */

// accessors -- every class should have some
    long get_sides(void) const { return sides; }
    double get_scale(void) const { return scale; }
    double get_adjustment(void) const { return adjustment; }

// mutators -- every class should have some
    bool set_sides(long new_sides)
    {
        bool okay = false;
        if ( new_sides >= 1 )
        {
            sides = new_sides;
            okay = true;
        }
        return okay;
    }
    bool set_scale(double new_scale)
    {
        bool okay = false;
        if ( fabs(new_scale) > 1e-6 )
        {
            scale = new_scale;
            okay = true;
        }
        return okay;
    }
    bool set_adjustment(double new_adjustment)
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
 * Member initialization lists are a way for the programmer
 * to keep the compiler from being overly helpful.
 * Essentially, the compiler thinks classes are going to
 * initialize themselves really neatly -- unlike how the
 * built-in types do -- and tries to give a helping hand by
 * filling in all member variables with their 'origin'
 * values (0, 0L, 0.0, '\0', false, etc.).  Then, we come
 * along and fill in the values as we actually want them
 * filled in in the constructor body -- twice the time
 * necessary is spent initializing member variables!
 * Sometimes we are duplicating the compiler's efforts...
 * And sometimes the compiler is wasting our time...
 *
 * ----------------------------------------------------------
 * So basically initializing lists manually instead of having
 * the compiler guess what works best makes things way more 
 * efficient.
 *
 * Professor James will expect this to be used in future programs
 * with any utilization of a class
 * ----------------------------------------------------------
 *
 * The syntax is a colon followed by a comma-separated list
 * of parenthesized initializers -- one per member variable
 * -- in the original order of declaration.
 */
// constructors -- every class should have at least three (3)
    Die(void)
        : sides{6}, // ":" colon starts the initialization process
          scale{1.0}, // we have to list out and initialize all of our member variables
          adjustment{0.0} 
    {
    } 
    /* doing this weird code move above actually increases efficiency by a lot, since the 
     program doesn't zero the values about every time the above function is being used */
     
    Die(const Die & d)
        : sides{d.sides}, scale{d.scale}, adjustment{d.adjustment}
    {
    }
    Die(long new_sides)
        : Die{}
    {
        set_sides(new_sides);  // always call the mutator to validate
                               // data coming from the outside!
    }
    Die(long new_sides, double new_scale, double new_adjustment)
        : Die{}
    {
        set_sides(new_sides);
        set_scale(new_scale);
        set_adjustment(new_adjustment);
    }
    Die(long new_sides, double new_alterer, bool is_scaling)
        : Die{}
    {
        set_sides(new_sides);
        if ( is_scaling )
        {
            set_scale(new_alterer);
        }
        else
        {
            set_adjustment(new_alterer);
        }
    }
/*
 * You must list all member variables in your member
 * initialization list to avoid the heinous warnings from
 * the compiler, of course.  Worse, perhaps, is that you
 * must list them in the same order in which they were
 * originally declared or you get a different warning!
 *
 * **********************************************************
 *
 * One other catch:  if you have a member variable which is
 * of a class type (say a string):
 *
 *     class ClassName
 *     {
 *         string str_memb;
 *     ...
 *     };
 *
 * You ~must~ use just empty parentheses in your member
 * initialization list to default construct that member
 * (i.e. to call that member's default ctor):
 *
 *     ClassName( ... ) : ..., str_memb(), ... { ... }
 *
 * Normally you default construct by having nothing at all:
 *
 *     // some function body
 *     {
 *         string s;    // default constructs variable s
 *     }
 *
 * In fact, trying to default construct a normal variable
 * with empty parentheses is a hiding error -- it declares a
 * function named like your variable taking no arguments and
 * returning the proposed type of your variable:
 *
 *     string t();  // declares a function t with no args and
 *                  //   returning a string
 *
 * So watch out for that!
 */

// utility/helper functions specific to the class and its purpose
// "read only" --> referring to a "const"
// we like "const" references in classes are better than "by value" 
// types that are better reserved for doubles and whatnot.
    double min(void) const
        { return scale + adjustment; }
    double max(void) const
        { return static_cast<double>(sides) * scale + adjustment; }
    double avg(void) const
        { return (min() + max()) / 2; }

    bool can_be_smaller(const Die & d) const
        { return min() < d.min(); }
    bool can_be_larger(const Die & d) const
        { return max() > d.max(); }
    bool is_typically_smaller(const Die & d) const
        { return avg() < d.avg(); }
    bool is_typically_larger(const Die & d) const
        { return avg() > d.avg(); }
    bool isSame(const Die & d) const
        { return sides == d.sides &&
                 fabs(scale - d.scale) <= 1e-6 &&
                 fabs(adjustment - d.adjustment) <= 1e-6; }

    double roll(void) const
        { return static_cast<double>(rand() % sides + 1) * scale + adjustment; }

/*
 * The RVO (Return Value Optimization ...or
 * constructor-return optimization or returned construction
 * optimization or...) avoids copying the returned value
 * before destruction of the local variable and simply
 * passes along the temporary/anonymous object explicitly
 * constructed in the return expression back to the caller.
 */
    const Die scale_by(double applied_scale) const
        { return Die{sides, scale * applied_scale, adjustment}; }
    Die const translate(double applied_adjustment) const
        { return Die{sides, scale, adjustment + applied_adjustment}; }
    const Die change_shape(long new_sides) const
        { return Die{new_sides, scale, adjustment}; }

/*
 * Thus we go from:
 *
 *    -- create local memory
 *    -- fill local memory
 *    -- copy local memory to return area
 *    -- destroy local memory
 *    -- [return area is used by caller]
 *    -- destroy return area
 *
 * To:
 *
 *    -- fill return area
 *    -- [return area is used by caller]
 *    -- destroy return area
 *
 * With the RVO in place.
 */
};

inline void stat_block(const Die & d)
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
    Die my_die, trans_die, scaled_die, both_adj_die;
    double offset, scaling_factor;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "What are the parameters of your die (dS~M+A)?  ";
    while ( ! my_die.read() )  // validate input with an OO approach
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\n\aInvalid parameter set!  Please try again!\n";
        cout << "What are the parameters of your die (dS~M+A)?  ";
    }
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
    // If I hadn't already stored trans_die, though, I could
    // have achieved this same result by:
    //    both_adj_die = my_die.translate(offset).scale_by(scaling_factor);
    // Or, if you prefer:
    //    both_adj_die = my_die.translate(offset)
    //                         .scale_by(scaling_factor);
    // Or even:
    //    both_adj_die = (my_die.translate(offset)).scale_by(scaling_factor);
    // (The extra parentheses clearly not necessary, but
    // some people like them...)
    //
    // This is known as chaining -- using the result of one
    // function that is a class object to then call another
    // class method.  It is all the rage and considered
    // quite elegant.
    //
    // If I weren't sending it to the stat_block shortly, I
    // could even continue like so:
    //    my_die.translate(offset)
    //                            .scale_by(scaling_factor)
    //                                                     .print();
    // (All spacing here is excessive and for elucidation
    // only!)

    /*
     * As noted below, anonymous objects are NOT protected
     * against such non-sense as this:
     *
     *    my_die . scale_by ( scaling_factor ) . read();
     *
     * instead of .print() ...easy enough to do.  But
     * luckily this is protected against by our const return
     * type.  (Unfortunately, it is not normal practice to
     * put const on return types...)
     *
     * So please try not to do such strange and idiotic
     * things, 'kay?
     *
     * You think it'll be easy to avoid, eh?  Look at this
     * 'code':
     */

    Die().read();

    /*
     * That compiles cleanly and runs 'just fine'.  It is
     * totally worthless.  After all, it constructs an
     * anonymous object as an unscaled, untranslated 6-sider
     * and then pauses the program to make the user type a
     * set of die parameters -- prompt-less -- and stores
     * that data in the same anonymous object and finally
     * throws away not only the bool result of the read
     * function but also the anonymous object itself!
     *
     * And worst of all:  there's no way to protect us from
     * this one!
     */

    cout << "\nWith only the scaling of the original:\n";
    stat_block(scaled_die);

    cout << "\nWith both scaling and translation of the original:\n";
    stat_block(both_adj_die);

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
        my_die.set_sides( my_die.get_sides() + 2 );
        cout << "\nIncreased sides by 2...\n";
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

/*
 * Placing the keyword const after the function's head (both
 * prototype and definition) has several effects:
 *
 *    -- we are promising not to alter the calling object's
 *       member variables during the call
 *    -- therefore the compiler will check up on us and
 *       verify that promise
 *    -- once the calling object is known to remain const,
 *       the compiler may be able to make some efficiency
 *       adjustments to the binary codes (depending on
 *       platform specifics)
 *           -- every bit of efficiency counts
 *    -- if an object is const (somehow), the compiler will
 *       only allow the programmer to call methods which
 *       have been marked as const upon that object
 *    -- once the calling object is known to remain const,
 *       you may be able to make some efficiency adjust-
 *       ments to the class in some way (see const& argu-
 *       ment for can_be_smaller(), for instance)
 *           -- we can get a lot of good benefits from placing a const after the function's head
 *    -- finally, the const-ness of a method is considered
 *       in determining its overloadability/overloaded-ness
 *       (this effect only applies to methods of a class, of
 *       course, since non-class functions don't have
 *       calling objects to keep const...)
 *           -- whether it can be overloaded in other functions or not
 *
 * But what should be const, then?  Accessors, most
 * behavioral functions, and printing.
 *
 * Then what should not be const?  Mutators, constructors,
 * and reading.
 *
 * The const-ness of a method [IMHO] should, but apparently
 * doesn't, affect the ability to call a method against a
 * temporary/anonymous object.  So be careful!  (Don't go
 * reading or mutating function results unless you truly
 * know what you are doing.)
 *
 * To protect some of these, you can mark your return type
 * const so that the returned object is not changable.  But
 * there are other types of anonymous/temporary objects, of
 * course.
 */
void Die::print(void) const
{
    cout << 'd' << sides << '~' << scale << (adjustment >= 0.0 ? "+" : "")
         << adjustment;
    return;
}

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
