#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;


const int NUM_RANKS = 13;
const int NUM_SUITS = 4;
const int RANKS[] = { 0, 1,2, 3, 4, 5,
                        6, 7, 8, 9, 10,
                        11, 12 };
const int SUITS[] = { 0, 1, 2, 3 };
                    //"Clubs", "Diamonds", "Hearts", "Spades"
class card
{
public:
    void setValue(int value);
    void SetValue(int suit, int rank);
    int getValue();
    int returnValueRank();
    int returnValueSuit();
    void print();
private:
    int mCardValue;
    bool checkRange(int val, int min, int max);
};

#endif // CARD_H_INCLUDED
