#pragma once
#include "Image.h"

using namespace std;

class SpriteSheetCutter
{
public:
	SpriteSheetCutter();
	~SpriteSheetCutter();

	Image** CutSpriteSheet(Image *spriteSheet, int width, int height);
};

