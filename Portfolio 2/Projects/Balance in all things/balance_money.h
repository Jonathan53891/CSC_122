// This is the HEADER FILE balance_money.h.  This is the INTERFACE for the class
// Money.  Values of this type are amounts of money in U.S. currency.

#ifndef BALANCE_MONEY_H
#define BALANCE_MONEY_H

#include <iostream>

class Money
{
	long cents;   // Cents
	long dollars;

public:

	// Initializes the object to $0.00.
	Money(void) : cents(0), dollars(0) {}

	// Initializes the object with a dollar value
	Money(long i_dollars) : cents(0), dollars(i_dollars) {}

	// Initializes the object with a dollar and cent value.
	Money(long i_dollars, short i_cents) : cents(i_cents), dollars(i_dollars) {}


	// Accessor for cents
	long get_cents() const { return cents; }
	// Accessor for dollars
	long get_dollars()  const { return dollars; }
	// Postcondition:  return value is sum of calling object and amount.
	//                 neither amount nor calling object are changed.
	Money add(const Money & amount) const;

	// Postcondition:  return value is difference of calling object and amount.
	//                 neither amount nor calling object are changed.
	Money subtract(const Money & amount) const;

	// Postcondition:  return value is arithmetic negation of calling object.
	//                 calling object is not changed.
	Money negate(void) const;

	// Returns true if the calling object equals the amount, false otherwise.
	bool equals(const Money & amount) const;

	// Returns true if the calling object is less than the amount,
	// false otherwise.
	bool less(const Money & amount) const;

	// Postcondition:  calling object's value is read from the stream
	//                 in normal U.S. format:  $ddd.cc.
	void input(std::istream & ins);

	// Postcondition:  calling object's value is printed on the stream
	//                 in normal U.S. format:  $ddd.cc.  (calling object
	//                 is not changed)
	void output(std::ostream & outs) const;

	// Returns amount of money in decimal format.
	double get_value(void) const;
};

#endif

