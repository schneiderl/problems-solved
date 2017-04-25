#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(Image * image, int width, int height)
{
	int numberOfSprites = (image->getWidth() / width) * (image->getHeight() / height);
	int xIndex = 0;
	int yIndex = 0;

	Image **newImage;
	newImage = new Image *[numberOfSprites];

	for (int i = 0; i < numberOfSprites; i++){
		newImage[i] = new Image(width, height);

		for (int j = 0; j < height; j++){
			for (int k = 0; k < width; k++){
				newImage[i]->setPixel(image->getPixel(j + (image->getWidth() - (width * (yIndex + 1))), k + (image->getHeight() - (height * (xIndex + 1)))), j, k);
			}
		}

		yIndex++;
	}

	images = newImage;

	numberOfImages = numberOfSprites;
	imageIndex = 0;
}

SpriteSheet::~SpriteSheet(){
}

void SpriteSheet::incrementImageIndex(){
	imageIndex++;

	if (imageIndex >= numberOfImages){
		imageIndex = 0;
	}
}

void SpriteSheet::decrementImageIndex(){
	imageIndex--;

	if (imageIndex < 0){
		imageIndex = 6;
	}
}

Image** SpriteSheet::getImages(){
	return images;
}

Image * SpriteSheet::getCurrentImage(){
	return images[imageIndex];
}


int SpriteSheet::getImageIndex(){
	return imageIndex;
}
