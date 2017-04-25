#include "SpriteSheetCutter.h"

SpriteSheetCutter::SpriteSheetCutter()
{
}


SpriteSheetCutter::~SpriteSheetCutter()
{
}

Image** SpriteSheetCutter::CutSpriteSheet(Image * spriteSheet, int width, int height)
{
	int numberOfSprites = (spriteSheet->getWidth() / width) * (spriteSheet->getHeight() / height);
	int xIndex = 0;
	int yIndex = 0;

	Image **newImage;
	newImage = new Image *[numberOfSprites];

	for (int i = 0; i < numberOfSprites; i++){
		newImage[i] = new Image(width, height);
		for (int j = 0; j < height; j++){
			for (int k = 0; k < width; k++){
				newImage[i]->setPixel(spriteSheet->getPixel(j + (spriteSheet->getWidth() - (width)), k + (spriteSheet->getHeight() - (height))), j, k);
			}
		}

	}

	return newImage;
}
