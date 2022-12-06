#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "animation.h"
#include "card.h" 
#include "deck.h" 
#include "player.h"

void hitMe(Deck &myDeck, int &turn, int &reply, Player &player1, int &score, int &condition, int &playerScore);
void stay(Deck &myDeck, int &bot_turn, int &reply, Player &player1, Player &bot, int &score, int &condition, int &playerScore, int &botScore);
// void checkText(sf::Text &font);
// void checkImage1();
// void checkImage2();

#endif // DECK_H_INCLUDED
