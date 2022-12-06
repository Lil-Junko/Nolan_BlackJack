#include "animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);   // We make this a float since it's a unsigned int
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

/**
 * @brief modified the code, card now displays a position in the deck
 *  starting from 0 to 51 (there are 52 cards but in a 0 base array)
 * 
 * @param row 
 * @param deltaTime (removed) useless
 * @param faceRight 
 * @param card 
 */

void Animation::Update(int row, bool faceRight, int card)
{
    currentImage.y = row;
    //totalTime += deltaTime;

    //currentImage.y = row;
    //totalTime += deltaTime;

    //if (totalTime >= switchTime)
    //{
        //totalTime -= switchTime;
        currentImage.x = card; //sets image to desired position

        // if (currentImage.x >= imageCount.x)
        // {
        //     currentImage.x = 3;
        // }
    //}

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}