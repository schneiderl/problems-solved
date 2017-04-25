#pragma once
#include "Image.h"
#include <fstream>
#include <sstream>

using namespace std;

class PTMReader
{
public:
	PTMReader();
	~PTMReader();

	Image* createImageFromPTM(string name);
};

