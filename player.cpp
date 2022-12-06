#include "player.h"
#include "deck.h"

void Player::hitCard(Deck &deck)
{
    card newCard = deck.dealCard();
    mHand.push_back(newCard);
}
void Player::reset()
{
    mHand.clear();
}
void Player::newHand(Deck &deck)
{
    reset();
    for (int i = 0; i< INITIAL_NUM_CARDS; i++)
    {
        hitCard(deck);
    }
}
int Player::count() const
{
    int size = mHand.size();
    int count = 0;
    int total_ace = 0;
    for (int i = 0; i<size; i++)
    {
        card myCard = mHand[i];
        int points = myCard.getValue();
        points = points + 1;
        while (points > 13)
        {
            if(points > 13)
            {
                points = points - 13;
            }
        }
        if (points ==1)
            {total_ace++;}
        else if (points>10)
            {points = 10;}
        count+=points;
    }
    for (int j = 0; j < total_ace; j++)
    {
        if ((count + 10) <= 21)
        {
            count += 10;
        }
    }
    return count;
}
//test function to see the deck, useless in the game
//I'm leaving this here incase you want to see the inner workings of the deck
void Player::print() const
{
    for (int i = 0; i < static_cast<int>(mHand.size()); i++)
    {
        card myCard = mHand[i];
        cout << myCard.getValue() << " "; //shows the card type
        myCard.print();
        cout << endl;
    }
}
int Player::getRank(int i)
{
    card myCard = mHand[i]; //returns the rank of the card
    return myCard.returnValueRank(); //used for displaying card
}

int Player::getSuit(int i)
{
    card myCard = mHand[i]; //returns the suit of the card
    return myCard.returnValueSuit(); //used for displaying card
}
