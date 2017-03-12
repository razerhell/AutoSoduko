#pragma once

#include "zmatrix.h"

class GridMatrix : public ZMatrix<int>
{
public:
	GridMatrix();
	GridMatrix(const GridMatrix & other);
	virtual ~GridMatrix();
};