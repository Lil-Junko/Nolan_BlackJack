#include "card.h"

// Code implementation of the Card member functions goes here

// int getValue() --- Get card value
// - return the value of the mCardValue member variable
int card::getValue()
{
	return mCardValue;
}

// void setValue(int value) --- Set card value (0 to 51). Check to make sure value is valid. If invalid, set value to -1.
// - set the value of the mCardValue member variable

bool card::checkRange(int val, int min, int max)
{
	if (val<min || val > max)
		return false;
	else
		return true;
}

void card::SetValue(int suit, int rank)
{
	if (checkRange(suit, 0, 3) && checkRange(rank, 0, 12))
		mCardValue = suit * NUM_RANKS + rank;
	else
		mCardValue = -1;
}

void card::setValue(int value)
{
	if (value >= 0 && value <= 51) //checks if value is bad
		mCardValue = value;
	else
		mCardValue = -1;
}

int card::returnValueRank()
{
	int rank = mCardValue % NUM_RANKS;
	return RANKS[rank];
}
int card::returnValueSuit()
{
	int suit = mCardValue / NUM_RANKS;
	return SUITS[suit];
}

void card::print()
{
	int rank = mCardValue % NUM_RANKS;
	int suit = mCardValue / NUM_RANKS;
	cout << RANKS[rank] << " of " << SUITS[suit] << endl;
}