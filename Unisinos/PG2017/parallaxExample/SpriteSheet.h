#pragma once
#include "Image.h"

using namespace std;

class SpriteSheet
{
public:
	SpriteSheet(Image *image, int width, int height);
	~SpriteSheet();

	void incrementImageIndex();
	void decrementImageIndex();

	Image** getImages();
	Image* getCurrentImage();

	int getImageIndex();

private:
		
	Image **images;

	int imageIndex;
	int numberOfImages;
};

