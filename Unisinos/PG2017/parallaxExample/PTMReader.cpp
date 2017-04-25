#include "PTMReader.h"
#include <iostream>
#include <cstring>
#include <cstdlib>


PTMReader::PTMReader()
{
}


PTMReader::~PTMReader()
{
}

Image* PTMReader::createImageFromPTM(string name)
{
	int tempWidth, tempHeight;

	ifstream arq;
	arq.open(name);
	char BUFFER[1024];

	arq >> BUFFER;

	if (arq.is_open())
	{
		//Checks for file type
		if (BUFFER[0] == 'P' && BUFFER[1] == '7')
		{
			arq >> BUFFER;

			//Checks for comments
			if (BUFFER[0] == '#')
			{
				arq.getline(BUFFER, 1024);
				arq >> tempWidth;
			}
			else
			{
				tempWidth = atoi(BUFFER);
			}
			arq >> tempHeight;

			Image *tempImage = new Image(tempWidth, tempHeight);

			//TODO change scale if maxValue is not 255
			int maxValue;

			arq >> maxValue;

			int a, r, g, b;

			for (int i = 0; i < tempHeight; i++)
			{
				for (int j = 0; j < tempWidth; j++)
				{
					arq >> a;
					arq >> r;
					arq >> g;
					arq >> b;

					tempImage->setPixelFromFourValues(a, r, g, b, j, tempHeight - i - 1);
				}
			}

			arq.close();
			return tempImage;
		}
	}

	arq.close();
	return NULL;
	//return Image(10, 10);
}
