#pragma once

#include "Image.h"

using namespace std;

class Layer
{
public:
	Layer();
	~Layer();

	void setImage(Image *novaImagem);
	void setUpdateRate(float newupdateRate);

	Image* getImage();
	float getUpdateRate();

private:

	Image *image;
	float movementSpeed;
};

