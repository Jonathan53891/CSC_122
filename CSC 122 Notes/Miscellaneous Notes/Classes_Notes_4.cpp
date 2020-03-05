/*
 * Object Oriented Programming in C++ -- Part IV
 *
 * Composition is the process of having one class have
 * members of another class type (the one class is composed
 * of members of another class, you see...).  The class
 * composed of the other tends to rely on the original class
 * in many ways -- calling many of its methods, for
 * instance.
 *
 * In this example we'll see:
 *
 *    -- ...how to place a class into a library!
 *
 *    -- ...what composition is and means to us.
 *
 *    -- ...an interesting lee-way granted by the compiler
 *          when compiling a class.
 *
 * In addition, we see that there could be more
 * opportunities for chaining of method calls.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "input.h"
#include "die.h"

using namespace std;

class DiceGroup //group of dice all being rolled together --> add up the values presented after rolling
{
    Die base_die;  // use library supplied class to compose
                   // new class
    long count, adjust;
    /*
     * In future versions, we might want to let the user
     * label their group of dice...
     */
    // string label;

public:
    // constructors
    DiceGroup(const Die & new_base, long new_count = 1, long new_adjust = 0)
        : DiceGroup{}
        { set_base(new_base); set_count(new_count); set_adjust(new_adjust); }
    DiceGroup(const DiceGroup & dg)
        : base_die{dg.base_die}, count{dg.count}, adjust{dg.adjust}
        { }
    DiceGroup(void)
        : base_die{}, count{0}, adjust{0}
        { }

    // input/output
        // NOTE:  our count and adjustment are optional, but
        //        the scale and adjustment of the base die
        //        are required!
    bool read(void)
    {
        bool read_okay;
        Die d;
        long c = 1, a = 0;
        char t;
        cin >> ws;
        if (isdigit(cin.peek()))
        {
            cin >> c;
        }
        read_okay = !cin.fail() &&
                    d.read();
        if (peek_ahead() != '\n')
        {
            cin >> t >> a;
            if (t == '-')
            {
                a = -a;
            }
            read_okay = read_okay && !cin.fail();
        }
        return read_okay &&
               set_count(c) && set_base(d) && set_adjust(a);
    }

    void print(void) const
    {
        if (count != 1)
        {
            cout << count;
        }
        base_die.print();
        if (adjust != 0)
        {
            if (adjust > 0)
            {
                cout << '+';
            }
            cout << adjust;
        }
        return;
    }

    // accessors
    const Die get_base(void) const { return base_die; }

    long get_count(void) const { return count; }

    long get_adjust(void) const { return adjust; }

    // meta- or pseudo- accessors -- accessing information derived from/about
    // our class' core data
    double get_max(void) const
    {
        return static_cast<double>(count) * base_die.max() +
               static_cast<double>(adjust);
    }

    double get_avg(void) const
    {
        return (get_max() + get_min()) / 2;
    }

    double get_min(void) const
    {
        return static_cast<double>(count) * base_die.min() +
               static_cast<double>(adjust);
    }

    // mutators
    bool set_base(const Die & new_base)
    {
        base_die = new_base;
        return true;
    }

    bool set_count(long new_count)
    {
        bool okay = false;
        if (new_count >= 0)
        {
            count = new_count;
            okay = true;
        }
        return okay;
    }

    bool set_adjust(long new_adjust)
    {
        adjust = new_adjust;
        return true;
    }

    // helpers, behaviors, etc.
    double roll(void) const
    {
        double sum = static_cast<double>(adjust);
        for (long d = 1; d <= count; ++d)
        {
            sum += base_die.roll();
        }
        return sum;
    }

    const DiceGroup merge(const DiceGroup & dg) const
        { return base_die.isSame(dg.base_die)
               ? DiceGroup{base_die, count+dg.count, adjust+dg.adjust}
               : DiceGroup{}; } // don't use an exception here
};

inline void stat_block(const DiceGroup & dg)
{
    cout << "\nWhen you roll ";
    dg.print();
    cout << " you might get " << dg.roll() << ".\n"
            "Whatever it is, it will always be between " << dg.get_min()
         << " and " << dg.get_max() << "\nand be centered around "
         << dg.get_avg() << ".\n";
    return;
}

int main(void)
{
    DiceGroup one, two;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "What is the first set of dice?  ";
    while (!one.read())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\n\aInvalid set of dice!  Please try again!\n";
        cout << "\nWhat is the set of dice?  ";
    }

    cout << "\nStatistics for your first set of dice:\n";
    stat_block(one);

    cout << string(70,'*') << '\n';

    cout << "\nNow enter a compatible set of dice for merging:  ";
    while (!two.read() || one.merge(two).get_count()==0) /* Using this "while" statement here allows 
                                                            you to reuse the merge later on in the code.
                                                            
                                                            The "merge" is annoying for programmers but
                                                            helps a lot with the efficiency of the code. */
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\n\aInvalid set of dice!  Please try again!\n";
        cout << "\nNow enter a compatible set of dice for merging:  ";
    }

    cout << "\nStatistics for your second set of dice:\n";
    stat_block(two);

    cout << string(70,'*') << '\n';

    cout << "\nWhen merged together, they'll look like this:\n";
    stat_block(one.merge(two));

    return 0;
}
