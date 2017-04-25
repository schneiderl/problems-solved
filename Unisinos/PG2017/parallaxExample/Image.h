#pragma once
#include <iostream>
#include <string>


using namespace std;

class Image {
public:
	Image(int w, int h);
	~Image();

	void setPixel(int rgb, int x, int y);
	void setPixelFromThreeValues(int r, int g, int b, int x, int y);
	void setPixelFromFourValues(int a, int r, int g, int b, int x, int y);

	void makeImageTransparent();

	void combineImages(Image *otherImage);
	void copyImage(Image *otherImage);
	void plotImage(Image *otherImage, int xOffset, int yOffset);
	void subImage(Image *otherImage, int xOffset, int yOffset, int w, int h);

	int getPixel(int x, int y);
	int* getPixels();

	int getWidth();
	int getHeight();

private:
	int *pixels; // alternativamente char *pixels – 1 byte por canal
				 // neste caso, pixels = new char[w*h*3];
	int width, height;
};
