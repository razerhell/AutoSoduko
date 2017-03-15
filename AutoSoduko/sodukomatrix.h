#pragma once

#include "zmatrix.h"
#include <cstring>

class SodukoMatrix : public ZMatrix<int>
{


public:
	SodukoMatrix();
	SodukoMatrix(const SodukoMatrix & other);
	virtual ~SodukoMatrix();
	
	int solveSodukoBySupportMatrix();

	bool readFile(string fileName);
	bool getGrid(const int &x, const int &y, vector<int> gridVector) const;
};