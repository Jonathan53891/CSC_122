#include "balance_money.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
using namespace std;

Money Money::add(const Money & amount) const
{
	long new_cents = cents + amount.get_cents();
	long new_dollars = dollars + amount.get_dollars();
	// checks if has excess cents in calculations
	if (new_cents > 99)
	{
		new_dollars++;
		new_cents = new_cents - 100;
	}
	return Money(new_dollars, new_cents);
}

Money Money::subtract(const Money & amount) const
{
	long new_cents = cents - amount.get_cents();
	long new_dollars = dollars - amount.get_dollars();
	// checks if does not have enough cents in calculations
	if (new_cents < 0)
	{
		new_dollars--;
		new_cents = new_cents + 100;
	}
	return Money(new_dollars, new_cents);
}


Money Money::negate() const
{
	return Money(-1 * dollars, cents);
}

bool Money::equals(const Money & amount) const
{
	bool rv = false;
	if (cents == amount.get_cents() && dollars == amount.get_dollars())
	{
		rv = true;
	}
	return rv;
}

bool Money::less(const Money & amount) const
{
	bool rv = false;
	if ((dollars+ .01*cents) < (amount.get_dollars() + .01* amount.get_cents()))
	{
		rv = true;
	}
	return rv;
}
void Money::input(std::istream & ins)
{
	char dummy;
	ins >> dummy >> dollars >> dummy >> cents;


}

void Money::output(std::ostream & outs) const
{
	outs << '$' << dollars << '.' << setfill('0') << setw(2) << cents;


}

double Money::get_value(void) const
{

	return  (dollars + cents*.01);
}
