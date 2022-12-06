#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "card.h" 
#include "deck.h" 
#include "player.h"
#include "game.h"

using namespace std;

int main()
{
    sf::Font font;
    if (!font.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening college.ttf file\n";
        exit(1);
    }

#pragma region Screen Size    
    // Screen Size
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Blackjack");

    //here is where all the cards are initiliazed
    sf::Texture cardTexture1;
    sf::Texture cardTexture2;
    sf::Texture cardTexture3;
    sf::Texture cardTexture4;
    sf::Texture cardTexture5;
    sf::Texture cardTexture6;
    sf::Texture cardTexture7;
    sf::Texture cardTexture8;
    sf::Texture cardTexture9;
    sf::Texture cardTexture10;
    sf::Texture cardTexture11;

    float pointX = resolution.x/7;
    float pointY = resolution.y/4;

    if (!cardTexture1.loadFromFile("cards.png"))
    {
        std::cout<<"Error opening file cards.png\n";
        exit(2);
    }
    cardTexture1.loadFromFile("cards.png"); //this is where you load in the image
    cardTexture2.loadFromFile("cards.png");
    cardTexture3.loadFromFile("cards.png");
    cardTexture4.loadFromFile("cards.png");
    cardTexture5.loadFromFile("cards.png");
    cardTexture6.loadFromFile("cards.png");
    cardTexture7.loadFromFile("cards.png");
    cardTexture8.loadFromFile("cards.png");
    cardTexture9.loadFromFile("cards.png"); 
    cardTexture10.loadFromFile("cards.png");
    cardTexture11.loadFromFile("cards.png");

    //in order to make every card a different texture each time or else they all
    //will be the same card as they share the same texture
    
    sf::RectangleShape card1(sf::Vector2f(resolution.x/7, resolution.y/4)); //sets size of card
    sf::RectangleShape card2(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card3(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card4(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card5(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card6(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card7(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card8(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card9(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card10(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape card11(sf::Vector2f(resolution.x/7, resolution.y/4));

    //all the cards
    card1.setTexture(&cardTexture1);
    card2.setTexture(&cardTexture2);
    card3.setTexture(&cardTexture3);
    card4.setTexture(&cardTexture4);
    card5.setTexture(&cardTexture5);
    card6.setTexture(&cardTexture6);
    card7.setTexture(&cardTexture7);
    card8.setTexture(&cardTexture8);
    card9.setTexture(&cardTexture9);
    card10.setTexture(&cardTexture10);
    card11.setTexture(&cardTexture11);
    //set positions
    card1.setPosition(0,pointY*3);
    card2.setPosition(pointX,pointY*3);
    card3.setPosition(pointX*2,pointY*3);
    card4.setPosition(pointX*3,pointY*3);
    card5.setPosition(pointX*4,pointY*3);
    card6.setPosition(pointX*5,pointY*3);
    card7.setPosition(0,pointY*2);
    card8.setPosition(pointX,pointY*2);
    card9.setPosition(pointX*2,pointY*2);
    card10.setPosition(pointX*3,pointY*2);
    card11.setPosition(pointX*4,pointY*2);

    Animation animation1(&cardTexture1, sf::Vector2u(14, 4), 0.3f);
    Animation animation2(&cardTexture2, sf::Vector2u(14, 4), 0.3f);
    Animation animation3(&cardTexture3, sf::Vector2u(14, 4), 0.3f);
    Animation animation4(&cardTexture4, sf::Vector2u(14, 4), 0.3f);
    Animation animation5(&cardTexture5, sf::Vector2u(14, 4), 0.3f);
    Animation animation6(&cardTexture6, sf::Vector2u(14, 4), 0.3f);
    Animation animation7(&cardTexture7, sf::Vector2u(14, 4), 0.3f);
    Animation animation8(&cardTexture8, sf::Vector2u(14, 4), 0.3f);
    Animation animation9(&cardTexture9, sf::Vector2u(14, 4), 0.3f);
    Animation animation10(&cardTexture10, sf::Vector2u(14, 4), 0.3f);
    Animation animation11(&cardTexture11, sf::Vector2u(14, 4), 0.3f);
    //animation code

    //bot code
    sf::Texture bot_cardTexture1;
    sf::Texture bot_cardTexture2;
    sf::Texture bot_cardTexture3;
    sf::Texture bot_cardTexture4;
    sf::Texture bot_cardTexture5;
    sf::Texture bot_cardTexture6;
    sf::Texture bot_cardTexture7;
    sf::Texture bot_cardTexture8;
    sf::Texture bot_cardTexture9;
    sf::Texture bot_cardTexture10;
    sf::Texture bot_cardTexture11;
    bot_cardTexture1.loadFromFile("cards.png"); //this is where you load in the image
    bot_cardTexture2.loadFromFile("cards.png");
    bot_cardTexture3.loadFromFile("cards.png");
    bot_cardTexture4.loadFromFile("cards.png");
    bot_cardTexture5.loadFromFile("cards.png");
    bot_cardTexture6.loadFromFile("cards.png");
    bot_cardTexture7.loadFromFile("cards.png");
    bot_cardTexture8.loadFromFile("cards.png");
    bot_cardTexture9.loadFromFile("cards.png"); 
    bot_cardTexture10.loadFromFile("cards.png");
    bot_cardTexture11.loadFromFile("cards.png");
    //yes this is important, no I don't like doing this
    //card creation
    
    sf::RectangleShape bot_card1(sf::Vector2f(resolution.x/7, resolution.y/4)); //sets size of card
    sf::RectangleShape bot_card2(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card3(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card4(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card5(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card6(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card7(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card8(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card9(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card10(sf::Vector2f(resolution.x/7, resolution.y/4));
    sf::RectangleShape bot_card11(sf::Vector2f(resolution.x/7, resolution.y/4));

    //all the cards
    bot_card1.setTexture(&bot_cardTexture1);
    bot_card2.setTexture(&bot_cardTexture2);
    bot_card3.setTexture(&bot_cardTexture3);
    bot_card4.setTexture(&bot_cardTexture4);
    bot_card5.setTexture(&bot_cardTexture5);
    bot_card6.setTexture(&bot_cardTexture6);
    bot_card7.setTexture(&bot_cardTexture7);
    bot_card8.setTexture(&bot_cardTexture8);
    bot_card9.setTexture(&bot_cardTexture9);
    bot_card10.setTexture(&bot_cardTexture10);
    bot_card11.setTexture(&bot_cardTexture11);
    //set positions
    bot_card1.setPosition(0,0);
    bot_card2.setPosition(pointX,0);
    bot_card3.setPosition(pointX*2,0);
    bot_card4.setPosition(pointX*3,0);
    bot_card5.setPosition(pointX*4,0);
    bot_card6.setPosition(pointX*5,0);
    bot_card7.setPosition(0,pointY);
    bot_card8.setPosition(pointX,pointY);
    bot_card9.setPosition(pointX*2,pointY);
    bot_card10.setPosition(pointX*3,pointY);
    bot_card11.setPosition(pointX*4,pointY);

    Animation bot_animation1(&cardTexture1, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation2(&cardTexture2, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation3(&cardTexture3, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation4(&cardTexture4, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation5(&cardTexture5, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation6(&cardTexture6, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation7(&cardTexture7, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation8(&cardTexture8, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation9(&cardTexture9, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation10(&cardTexture10, sf::Vector2u(14, 4), 0.3f);
    Animation bot_animation11(&cardTexture11, sf::Vector2u(14, 4), 0.3f);
    //animation code

    //player score
    sf::RectangleShape scoreBoard(sf::Vector2f(resolution.x/7, resolution.y/8));
    sf::Texture scoreBoardTexture;
    scoreBoardTexture.loadFromFile("button.png");
    scoreBoard.setTexture(&scoreBoardTexture);
    scoreBoard.setOrigin(scoreBoard.getGlobalBounds().width/2, scoreBoard.getGlobalBounds().height/2);
    scoreBoard.setPosition(pointX*6,pointY*3);
    sf::Text boardText;
    boardText.setFont(font);
    unsigned int BoardFontSize = scoreBoard.getGlobalBounds().height/3;
    boardText.setCharacterSize(BoardFontSize);
    boardText.setOrigin(boardText.getGlobalBounds().width/2, boardText.getGlobalBounds().height/2);
    boardText.setPosition(pointX*5.7,pointY*2.8);

    //house score
    sf::RectangleShape HouseBoard(sf::Vector2f(resolution.x/7, resolution.y/8));
    sf::Texture HouseBoardTexture;
    HouseBoardTexture.loadFromFile("button.png");
    HouseBoard.setTexture(&HouseBoardTexture);
    HouseBoard.setOrigin(HouseBoard.getGlobalBounds().width/2, HouseBoard.getGlobalBounds().height/2);
    HouseBoard.setPosition(pointX*6,pointY*1.5);
    sf::Text houseText;
    houseText.setFont(font);
    unsigned int HouseFontSize = HouseBoard.getGlobalBounds().height/3;
    houseText.setCharacterSize(HouseFontSize);
    houseText.setString("House: ?");
    houseText.setOrigin(houseText.getGlobalBounds().width/2, houseText.getGlobalBounds().height/2);
    houseText.setPosition(pointX*6,pointY*1.4);

    sf::RectangleShape vicBoard(sf::Vector2f(resolution.x/3, resolution.y/6));
    sf::Texture vicBoardTexture;
    vicBoardTexture.loadFromFile("button.png");
    vicBoard.setTexture(&vicBoardTexture);
    vicBoard.setOrigin(vicBoard.getGlobalBounds().width/2, vicBoard.getGlobalBounds().height/2);
    vicBoard.setPosition(pointX*3.5,pointY*2);
    sf::Text vicBoardText;
    vicBoardText.setFont(font);
    unsigned int vicBoardFontSize = vicBoard.getGlobalBounds().height/3;
    vicBoardText.setCharacterSize(vicBoardFontSize);
    vicBoardText.setString("error");
    vicBoardText.setOrigin(vicBoardText.getGlobalBounds().width/2, vicBoardText.getGlobalBounds().height/2);
    vicBoardText.setPosition(pointX*3,pointY*2);

    /**
     * @brief holy mother of Mosose
     * this is where the main gameplay starts
    */

    sf::Texture texture;
    if (!texture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file button.png\n";
        exit(3);
    }
    sf::Sprite button(texture);
    
    // first button
    sf::Vector2u imageSize=texture.getSize();
    button.setOrigin(imageSize.x/2, imageSize.y/2);
    button.setPosition(pointX*6,pointY/2);
    button.setColor(sf::Color(0, 0, 255));
    button.setScale(0.5,0.5);
    sf::Sprite button2(texture);
    sf::Vector2u imageSize2=texture.getSize();
    button2.setOrigin(imageSize2.x/2, imageSize2.y/2);
    button2.setPosition(pointX*6,pointY);
    button2.setColor(sf::Color(0, 0, 255));
    button2.setScale(0.5,0.5);
    sf::Text text;
    text.setFont(font);
    unsigned int fontSize = button.getGlobalBounds().height/2;
    text.setCharacterSize(fontSize);
    text.setString("Hit");
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    text.setPosition(pointX*6,pointY/2);
    sf::Color textNormal = sf::Color::Green;
    sf::Color textHover = sf::Color::Red;
    text.setFillColor(textNormal);
    //button 2
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(fontSize); //same size as button
    text2.setString("Stand");
    text2.setOrigin(text2.getGlobalBounds().width/2, text2.getGlobalBounds().height/2);
    text2.setPosition(pointX*6,pointY);
    sf::Color textNormal2 = sf::Color::Green;
    sf::Color textHover2 = sf::Color::Red;
    text2.setFillColor(textNormal2);

    //restart button and quit button
    sf::Sprite restartButton(texture);
    sf::Vector2u imageSize3=texture.getSize();
    restartButton.setOrigin(imageSize3.x/2, imageSize3.y/2);
    restartButton.setPosition(pointX*4.1,pointY*3);
    restartButton.setColor(sf::Color(0, 0, 255));
    restartButton.setScale(0.5,0.5);
    sf::Sprite quitButton(texture);
    sf::Vector2u imageSize4=texture.getSize();
    quitButton.setOrigin(imageSize4.x/2, imageSize4.y/2);
    quitButton.setPosition(pointX*2.9,pointY*3);
    quitButton.setColor(sf::Color(0, 0, 255));
    quitButton.setScale(0.5,0.5);
    sf::Text text3;
    text3.setFont(font);
    text3.setCharacterSize(fontSize);
    text3.setString("Play Again");
    text3.setOrigin(text3.getGlobalBounds().width/2, text3.getGlobalBounds().height/2);
    text3.setPosition(pointX*4.1,pointY*3);
    sf::Color textNormal3 = sf::Color::Green;
    sf::Color textHover3 = sf::Color::Red;
    text3.setFillColor(textNormal);
    //button restart button text
    sf::Text text4;
    text4.setFont(font);
    text4.setCharacterSize(fontSize); //same size as button
    text4.setString("Quit");
    text4.setOrigin(text4.getGlobalBounds().width/2, text4.getGlobalBounds().height/2);
    text4.setPosition(pointX*3,pointY*3);
    sf::Color textNormal4 = sf::Color::Green;
    sf::Color textHover4 = sf::Color::Red;
    text4.setFillColor(textNormal2);
#pragma endregion

    //re position this code to initilize and then reinitalize after game ends
    int condition = 0;
    Player player1;
    Player botPlayer;
    Deck myDeck;
    int score = 0;
    int botScore = 0;

    //Dealing two cards to each player
    for (int i = 0; i < 2; i++)
    {
        player1.newHand(myDeck);
        botPlayer.newHand(myDeck);
    }
    vector <int> playerScore(2,0);
    int turn = 0; // incriments by one per tern
    int bot_turn = 0;
    int reply = 0;
    bool gamePlay = true;
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            while(true)
            {
                // Hitme button
                if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    text.setFillColor(textHover);
                    
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        button.setRotation(180);
                        reply = 1;
                        sf::sleep(sf::milliseconds(570));
                        botScore = botPlayer.count();
                        string bot_string_score = to_string(botScore);
                        bot_string_score = "House: " + bot_string_score;
                        houseText.setString(bot_string_score);
                        continue;
                    }
                }
                else
                {
                    button.setRotation(0);
                    text.setFillColor(textNormal);
                }

                // Stand button
                if (button2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    text2.setFillColor(textHover2);

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        reply = 2;
                        button2.setRotation(180);
                        sf::sleep(sf::milliseconds(570));
                        botScore = botPlayer.count();
                        string bot_string_score = to_string(botScore);
                        bot_string_score = "House: " + bot_string_score;
                        houseText.setString(bot_string_score);
                        continue;
                    }
                }
                else
                {
                    button2.setRotation(0);
                    text2.setFillColor(textNormal2);
                }
                
                //game
                if(reply > 0)
                {
                    if (reply == 2) //stand
                    {
                        stay(myDeck, bot_turn, reply, player1, botPlayer, score, condition, playerScore[0], botScore);
                    }
                    else if (reply == 1)
                    {
                        hitMe(myDeck, turn, reply, player1, score, condition, playerScore[0]);
                    }
                }

                int suit=0;
                int rank=0;

                if(bot_turn == 0)
                {
                    bot_animation1.Update(0, true, 13);
                    bot_animation2.Update(0, true, 13);
                }
                else if(bot_turn == 1)
                {
                    suit = botPlayer.getSuit(0);
                    rank = botPlayer.getRank(0);
                    bot_animation1.Update(suit, true, rank);
                    suit = botPlayer.getSuit(1);
                    rank = botPlayer.getRank(1);
                    bot_animation2.Update(suit, true, rank);
                }
                if(bot_turn == 2)
                {
                    
                    suit = botPlayer.getSuit(0);
                    rank = botPlayer.getRank(0);
                    bot_animation1.Update(suit, true, rank);
                    suit = botPlayer.getSuit(1);
                    rank = botPlayer.getRank(1);
                    bot_animation2.Update(suit, true, rank);
                    suit = botPlayer.getSuit(2);
                    rank = botPlayer.getRank(2);
                    bot_animation3.Update(suit, true, rank);
                }
                else if(bot_turn == 3)
                {
                    suit = botPlayer.getSuit(3);
                    rank = botPlayer.getRank(3);
                    bot_animation4.Update(suit, true, rank);
                }
                else if(bot_turn == 4)
                {
                    suit = botPlayer.getSuit(4);
                    rank = botPlayer.getRank(4);
                    bot_animation5.Update(suit, true, rank);
                }
                else if(bot_turn == 5)
                {
                    suit = botPlayer.getSuit(5);
                    rank = botPlayer.getRank(5);
                    bot_animation6.Update(suit, true, rank);
                }
                else if(bot_turn == 6)
                {
                    suit = botPlayer.getSuit(6);
                    rank = botPlayer.getRank(6);
                    bot_animation7.Update(suit, true, rank);
                }
                else if(bot_turn == 7)
                {
                    suit = botPlayer.getSuit(7);
                    rank = botPlayer.getRank(7);
                    bot_animation8.Update(suit, true, rank);
                }
                else if(bot_turn == 8)
                {
                    suit = botPlayer.getSuit(8);
                    rank = botPlayer.getRank(8);
                    bot_animation9.Update(suit, true, rank);
                }
                else if(bot_turn == 9)
                {
                    suit = botPlayer.getSuit(9);
                    rank = botPlayer.getRank(9);
                    bot_animation10.Update(suit, true, rank);
                }
                else if(bot_turn == 10)
                {
                    suit = botPlayer.getSuit(10);
                    rank = botPlayer.getRank(10);
                    bot_animation11.Update(suit, true, rank);
                }

                
                bot_card1.setTextureRect(bot_animation1.uvRect);
                bot_card2.setTextureRect(bot_animation2.uvRect);
                bot_card3.setTextureRect(bot_animation3.uvRect);
                bot_card4.setTextureRect(bot_animation4.uvRect);
                bot_card5.setTextureRect(bot_animation5.uvRect);
                bot_card6.setTextureRect(bot_animation6.uvRect);
                bot_card7.setTextureRect(bot_animation7.uvRect);
                bot_card8.setTextureRect(bot_animation8.uvRect);
                bot_card9.setTextureRect(bot_animation9.uvRect);
                bot_card10.setTextureRect(bot_animation10.uvRect);
                bot_card11.setTextureRect(bot_animation11.uvRect);

                if(turn == 0)
                {
                    suit = player1.getSuit(0);
                    rank = player1.getRank(0);
                    animation1.Update(suit, true, rank);
                    suit = player1.getSuit(1);
                    rank = player1.getRank(1);
                    animation2.Update(suit, true, rank);
                }
                else if(turn == 1)
                {
                    suit = player1.getSuit(2);
                    rank = player1.getRank(2);
                    animation3.Update(suit, true, rank);
                }
                else if(turn == 2)
                {
                    suit = player1.getSuit(3);
                    rank = player1.getRank(3);
                    animation4.Update(suit, true, rank);
                }
                else if(turn == 3)
                {
                    suit = player1.getSuit(4);
                    rank = player1.getRank(4);
                    animation5.Update(suit, true, rank);
                }
                else if(turn == 4)
                {
                    suit = player1.getSuit(5);
                    rank = player1.getRank(5);
                    animation6.Update(suit, true, rank);
                }
                else if(turn == 5)
                {
                    suit = player1.getSuit(6);
                    rank = player1.getRank(6);
                    animation7.Update(suit, true, rank);
                }
                else if(turn == 6)
                {
                    suit = player1.getSuit(7);
                    rank = player1.getRank(7);
                    animation8.Update(suit, true, rank);
                }
                else if(turn == 7)
                {
                    suit = player1.getSuit(8);
                    rank = player1.getRank(8);
                    animation9.Update(suit, true, rank);
                }
                else if(turn == 8)
                {
                    suit = player1.getSuit(9);
                    rank = player1.getRank(9);
                    animation10.Update(suit, true, rank);
                }
                else if(turn == 9)
                {
                    suit = player1.getSuit(10);
                    rank = player1.getRank(10);
                    animation11.Update(suit, true, rank);
                }

                card1.setTextureRect(animation1.uvRect);
                card2.setTextureRect(animation2.uvRect);
                card3.setTextureRect(animation3.uvRect);
                card4.setTextureRect(animation4.uvRect);
                card5.setTextureRect(animation5.uvRect);
                card6.setTextureRect(animation6.uvRect);
                card7.setTextureRect(animation7.uvRect);
                card8.setTextureRect(animation8.uvRect);
                card9.setTextureRect(animation9.uvRect);
                card10.setTextureRect(animation10.uvRect);
                card11.setTextureRect(animation11.uvRect);

                window.clear();
                if (turn >= 0)
                {
                    //two cards are delt to both bot and player
                    window.draw(card1);
                    window.draw(card2);
                    window.draw(bot_card1);
                    window.draw(bot_card2);
                }
                if (turn >= 1)
                {window.draw(card3); }
                if (turn >= 2)
                {window.draw(card4); }
                if (turn >= 3)
                {window.draw(card5); }
                if (turn >= 4)
                {window.draw(card6); }
                if (turn >= 5)
                {window.draw(card7); }
                if (turn >= 6)
                {window.draw(card8); }
                if (turn >= 7)
                {window.draw(card9); }
                if (turn >= 8)
                {window.draw(card10); }
                if (turn >= 9)
                {window.draw(card11); }
                if (turn >= 10)
                
                //11 cards are drawn, the reason is because you can in fact draw 11 cards
                //it is just very unlikely, about 52^11 chance probobly to get that
                //but it is possible so there is that many cards for player and bot
                if (bot_turn >= 1)
                {
                    window.draw(bot_card1);
                    window.draw(bot_card2);
                }
                if (bot_turn >= 2)
                {window.draw(bot_card3); }
                if (bot_turn >= 3)
                {window.draw(bot_card4); }
                if (bot_turn >= 4)
                {window.draw(bot_card5); }
                if (bot_turn >= 5)
                {window.draw(bot_card6); }
                if (bot_turn >= 6)
                {window.draw(bot_card7); }
                if (bot_turn >= 7)
                {window.draw(bot_card8); }
                if (bot_turn >= 8)
                {window.draw(bot_card9); }
                if (bot_turn >= 9)
                {window.draw(bot_card10); }
                if (bot_turn >= 10)
                {window.draw(bot_card11); }

                // //yes the same possibilites for the bot
                // //11 cards, 52^11 chance to get that, I don't like it either
                score = player1.count();
                string string_score = to_string(score);
                string_score = "Score: " + string_score;
                boardText.setString(string_score);

                window.draw(button);
                window.draw(text);
                window.draw(button2);
                window.draw(text2);
                window.draw(scoreBoard);
                window.draw(boardText);
                window.draw(HouseBoard);
                window.draw(houseText);
                window.display();
                
                if (event.type == sf::Event::Closed)
                    window.close(); //I think I forgot to include the proper event for this

                while(condition > 0)
                {
                    if(condition == 1) //lose
                    {
                        vicBoardText.setString("You lose!");
                        sf::sleep(sf::milliseconds(1500));//wait for a second
                    }
                    if(condition == 2) //win
                    {
                        vicBoardText.setString("You win!");
                        sf::sleep(sf::milliseconds(1500));//wait for a second
                    }
                    if(condition == 3) //lose
                    {
                        vicBoardText.setString("You tied!");
                        sf::sleep(sf::milliseconds(1500));//wait for a second
                    }
                    window.draw(vicBoard);
                    window.draw(vicBoardText);
                    window.display();
                    condition = 0;
                    gamePlay = false;
                    sf::sleep(sf::milliseconds(2200));//wait for a second
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                while(gamePlay == false)
                {
                    // window.clear();
                    vicBoardText.setString("Play again?");
                    window.draw(vicBoard);
                    window.draw(vicBoardText);
                    window.draw(restartButton);
                    window.draw(text3);
                    window.draw(quitButton);
                    window.draw(text4);
                    window.display();
                    if (restartButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        text3.setFillColor(textHover3);
                        
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            restartButton.setRotation(180);
                            sf::sleep(sf::milliseconds(370));
                            gamePlay = true;
                            //reinitialize everything
                            window.clear(); //clear every image left
                            player1.reset(); //reset player
                            botPlayer.reset(); //reset bot
                            turn = 0;
                            bot_turn = 0;
                            condition = 0;
                            //giving new cards
                            for (int i = 0; i < 2; i++)
                            {
                                player1.newHand(myDeck);
                                botPlayer.newHand(myDeck);
                            }
                            houseText.setString("House: ?");
                            continue;
                        }
                    }
                    else
                    {
                        restartButton.setRotation(0);
                        text3.setFillColor(textNormal3);
                    }
                    //quit
                    if (quitButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        text4.setFillColor(textHover4);
                        
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            quitButton.setRotation(180);
                            sf::sleep(sf::milliseconds(120));//wait for a second
                            window.close();
                            return 0; //not sure if this is the best way to do this but it works
                        }
                    }
                    else
                    {
                        quitButton.setRotation(0);
                        text4.setFillColor(textNormal4); //kinda pointless, you'll never see it
                    }
                }
            }
        }

    }


    return 0;
}
