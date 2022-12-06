#include "game.h"
void hitMe(Deck &myDeck, int &turn, int &reply, Player &player1, int &score, int &condition, int &playerScore)
{
    turn++;
    reply = 0;
    player1.hitCard(myDeck);
    score = player1.count();
    if (score > 21)
    {
        //bust, went over 21
        condition = 1; //lose
    }
    else if (score ==21)
    {
        playerScore = score;
        //Blackjack
        condition = 2; //win
    } 
}

void stay(Deck &myDeck, int &bot_turn, int &reply, Player &player1, Player &bot, int &score, int &condition, int &playerScore, int &botScore)
{
    reply = 0;
    botScore = bot.count();
    score = player1.count();
    bot_turn++;
    if (score > botScore && botScore < 21)
    {
        bot.hitCard(myDeck);
        botScore = bot.count();
        bot_turn++;
    }
    // cout << "bot score = " << botScore << endl;
    // cout << "my score = " << score << endl; //for testing
    if (score > 21 || score < botScore)
    {
        //bust
        condition = 1;
    }
    else if (score ==21 || score > botScore)
    {
        playerScore = score;
        //Blackjack
        condition = 2; //win
    }
    else if (score == botScore)
    {
        //tie
        condition = 3;
    }
}

//I was originally going to set all these gaurds into functions
//as you can see I did not manage to. 3 guards though so it's not too important
// void checkText(sf::Text &font)
// {
//     if (!font.loadFromFile("college.ttf"))
//     {
//         std::cout<<"Error opening college.ttf file\n";
//         exit(1);
//     }
// }
// void checkImage1()
// void checkImage2()