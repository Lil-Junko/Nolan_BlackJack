#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "card.h"
#include "deck.h"
#include <vector>
#include <iostream>
using namespace std;

const int INITIAL_NUM_CARDS=2;

class Player
{
public:
    void setName(string name);
    string getName() const;
    void hitCard(Deck &deck);
    void newHand(Deck &deck);
    void reset();
    int count() const;
    void print() const;
    int getRank(int i);
    int getSuit(int i);
    int getCardValue();
private:
    string mName;
    vector<card> mHand;
};

#endif // PLAYER_H_INCLUDED
