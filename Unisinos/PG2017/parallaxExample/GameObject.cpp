#include "GameObject.h"



GameObject::GameObject()
{
	posX = 0;
	posY = 0;

	currentSpriteIndex = 0;
}


GameObject::~GameObject()
{
}

void GameObject::setSprite(SpriteSheet * newSprite)
{
	sprite = newSprite;
}

void GameObject::setImage(Image * newImage)
{
	image = newImage;
}

void GameObject::setPosX(int newPosX)
{
	posX = newPosX;
}

void GameObject::setPosY(int newPosY)
{
	posY = newPosY;
}

void GameObject::incrementSpriteIndex()
{
	currentSpriteIndex++;

	//TODO use number of sprites here
	if (currentSpriteIndex >= 6)
	{
		currentSpriteIndex = 0;
	}

}

void GameObject::addToPosX(int plusX)
{
	posX += plusX;
}

void GameObject::addToPosY(int plusY)
{
	posY += plusY;
}

void GameObject::checkOutOfBounds()
{
	if (posX < 0)
	{
		posX = 665;
	}
}

int GameObject::getPosX()
{
	return posX;
}

int GameObject::getPosY()
{
	return posY;
}

int GameObject::getSpriteIndex()
{
	return currentSpriteIndex;
}

SpriteSheet * GameObject::getSprite()
{
	return sprite;
}

Image * GameObject::getCurrentImageFromSprite()
{
	//cout << currentSpriteIndex << endl;
	return sprite->getImages()[currentSpriteIndex];
}

Image * GameObject::getImage()
{
	return image;
}
