#pragma once

#include "SpriteSheet.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void setSprite(SpriteSheet *newSprite);
	void setImage(Image *newImage);
	void setPosX(int newPosX);
	void setPosY(int newPosY);

	void incrementSpriteIndex();

	void addToPosX(int plusX);
	void addToPosY(int plusY);
	
	void checkOutOfBounds();

	int getPosX();
	int getPosY();
	int getSpriteIndex();

	SpriteSheet *getSprite();

	Image *getCurrentImageFromSprite();
	Image *getImage();

private:
	
	SpriteSheet *sprite;
	Image *image;

	int posX, posY;
	int currentSpriteIndex;
};