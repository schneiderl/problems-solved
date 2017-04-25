#include "Layer.h"



Layer::Layer()
{
}


Layer::~Layer()
{
}

void Layer::setImage(Image  *novaImagem)
{
	//cout << newImage->getWidth() << endl;
	//image = new Image(novaImagem->getWidth(), novaImagem->getHeight());
	//image = new Image(10, 20);
	image = novaImagem;
}

void Layer::setUpdateRate(float newUpdateRate)
{
	movementSpeed = newUpdateRate;
}

Image * Layer::getImage()
{
	return image;
}

float Layer::getUpdateRate()
{
	return movementSpeed;
}
