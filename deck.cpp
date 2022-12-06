#include "deck.h"

    Deck::Deck() // --- default class constructor
    {
        srand(time(NULL));
        for (int i = 0; i < 52; i++)
        {
            card newCard;
            newCard.setValue(i);
            mUndealt.push_back(newCard);
        }
    }

    // void Deck::printUndealtDeck()
    // {
    //     int size = mUndealt.size();
    //     if (isEmpty())
    //     {
    //         cout << "Empty deck!\n";
    //     }
    //     else
    //     {
    //         for (int i = 0; i < size; i++)
    //         {
    //             mUndealt[i].print();
    //         }
    //     }

    // }

    // void Deck::printDealtDeck()
    // {
    //     int size = mDealt.size();
    //     if (isEmpty())
    //     {
    //         cout << "Empty deck! How did you manage this?\n";
    //     }
    //     else
    //     {
    //         for (int i = 0; i < size; i++)
    //         {
    //             mDealt[i].print();
    //         }
    //     }

    // }

    bool Deck::isEmpty()
    {
        return mUndealt.empty();
    }
// bool isEmpty() const --- return true if there are no cards left to deal, false otherwise

    void Deck::reset()
    {
        while (!mDealt.empty())
        {
            int lastIndex = mDealt.size()-1;
            mUndealt.push_back(mDealt[lastIndex]);
            mDealt.pop_back();
        }
    }

    card Deck::dealCard()
    {
        int size = mUndealt.size();
        //   1. get a random card through an random index
        int randIndex = rand()%size;
        //   2. swap the last card in the undealt deck with the random card in the undealt deck
        card temp = mUndealt[randIndex];
        mUndealt[randIndex] = mUndealt[size-1];
        mUndealt[size-1] = temp;
        mDealt.push_back(temp);
        mUndealt.pop_back();
        return temp;
    }
