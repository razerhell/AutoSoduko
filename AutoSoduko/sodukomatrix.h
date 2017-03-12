#pragma once

#include "zmatrix.h"
#include <cstring>

class SodukoMatrix : public ZMatrix<int>
{
public:
	SodukoMatrix();
	SodukoMatrix(const SodukoMatrix & other);
	virtual ~SodukoMatrix();
	bool readFile(string fileName);
};