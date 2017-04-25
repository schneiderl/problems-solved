#include "Image.h"

Image::Image(int w, int h)
{
	width = w; height = h;
	pixels = new int[w*h];
}


Image::~Image()
{

}

void Image::setPixel(int rgb, int x, int y) 
{
	pixels[x + y*width] = rgb;
}

int Image::getPixel(int x, int y) 
{
	return pixels[x + y * width];
}

int* Image::getPixels()
{
	return pixels;
}

int Image::getWidth() 
{ 
	return width; 
}

int Image::getHeight() 
{ 
	return height; 
}

void Image::setPixelFromThreeValues(int r, int g, int b, int x, int y)
{
	pixels[x + y*width] = (r << 16) | (g << 8) | b;
}

void Image::setPixelFromFourValues(int a, int r, int g, int b, int x, int y)
{
	pixels[x + y*width] = (a << 24) | (r << 16) | (g << 8) | b;
}

void Image::makeImageTransparent()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			pixels[i + j*width] = (0 << 24) ;
		}
	}
}

//Removes blue background and plots images
void Image::combineImages(Image *otherImage)
{

	for (int i = 0; i < otherImage->getHeight(); i++)
	{
		for (int j = 0; j < otherImage->getWidth(); j++)
		{
			//if ( (pixels[j, i] >> 24) & 0xff)
			int otherImagePixel = otherImage->getPixel(j, i);

			if ( ((otherImagePixel) & 0xff) > ((otherImagePixel >> 16) & 0xff) && ((otherImagePixel) & 0xff) > ((otherImagePixel >> 8) & 0xff))
			{

			}
			else
			{
				setPixel(otherImage->getPixel(j, i), j, i);

			}
		}
	}
}

void Image::copyImage(Image * otherImage)
{
	for (int j = 0; j < otherImage->getHeight(); j++)
	{
		for (int i = 0; i < otherImage->getWidth(); i++)
		{
			setPixel(otherImage->getPixel(i, j), i, j);
		}
	}
}

void Image::plotImage(Image * otherImage, int xOffset, int yOffset)
{
	for (int i = 0; i < otherImage->getHeight() + 0; i++)
	{
		for (int j = 0; j < otherImage->getWidth() + 0; j++)
		{
			int otherImagePixel = otherImage->getPixel(j, i);

			if (j + xOffset < width && i + yOffset < height && j + xOffset > 0 && i + yOffset > 0)
			{
				int myPixel = getPixel(j + xOffset, i + yOffset);

				if (((otherImagePixel >> 24) & 0xff) < 255)
				{
					int a, r, g, b;

					a = ((otherImagePixel >> 24) & 0xff);

					float secondColorPercentage = ((float)a / 255);

					r = ((((otherImagePixel >> 16) & 0xff) * secondColorPercentage) + ((((myPixel >> 16) & 0xff)) * (1 - secondColorPercentage)));
					g = ((((otherImagePixel >> 8) & 0xff) * secondColorPercentage) + ((((myPixel >> 8) & 0xff)) * (1 - secondColorPercentage)));
					b = ((((otherImagePixel)& 0xff) * secondColorPercentage) + ((((myPixel)& 0xff)) * (1 - secondColorPercentage)));

					setPixelFromThreeValues(r, g, b, j + xOffset, i + yOffset);
				}
				else
				{
					pixels[(j + xOffset) + (i + yOffset)*width] = otherImage->getPixel(j, i);
				}
			}
		}
	}
}

void Image::subImage(Image * otherImage, int xOffset, int yOffset, int w, int h){
	if (xOffset < width + w && yOffset < height + h){
		for (int j = 0; j < h; j++){
			for (int i = 0; i < w; i++){
				setPixel(otherImage->getPixel(i + xOffset, j + yOffset), i + xOffset, j + yOffset);
			}
		}
	}

}
