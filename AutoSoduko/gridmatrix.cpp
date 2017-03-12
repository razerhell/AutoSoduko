#include "gridmatrix.h"

GridMatrix::GridMatrix() : ZMatrix<int>(3, 3)
{

}

GridMatrix::GridMatrix(const GridMatrix & other)
{
	*this = other;
}

GridMatrix::~GridMatrix()
{
}
