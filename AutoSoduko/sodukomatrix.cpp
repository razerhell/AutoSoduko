#include "sodukomatrix.h"
#include <fstream>

SodukoMatrix::SodukoMatrix() : ZMatrix<int>(9, 9)
{
}

SodukoMatrix::SodukoMatrix(const SodukoMatrix & other)
{
	*this = other;
}

SodukoMatrix::~SodukoMatrix()
{
}

bool SodukoMatrix::readFile(string fileName)
{
	ifstream in("fileName");
	if (!in.is_open()) return false;
	int i = 0;
	while (!in.eof())
		in >> mData[i++];
	return true;
}
