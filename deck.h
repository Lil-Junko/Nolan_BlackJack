#ifndef DECK_H
#define DECK_H

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "card.h"

class Deck
{
public:
    Deck();
    void reset();
    // void printUndealtDeck();
    // void printDealtDeck();
    bool isEmpty();
    card dealCard();
private:
    vector<card> mUndealt;
    vector<card> mDealt;
};

#endif // DECK_H_INCLUDED
