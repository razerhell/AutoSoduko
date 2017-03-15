#include "sodukomatrix.h"
#include <fstream>
#include "supportmatrix.h"

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

// 采用赋值同时修改辅助矩阵的方式
int SodukoMatrix::solveSodukoBySupportMatrix()
{
	SupportMatrix supM;
	supM.converBySoduko(*this);

	//=============

	//=============
	return 0;
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

bool SodukoMatrix::getGrid(const int & x, const int & y, vector<int> gridVector) const
{
	// 下标非法不允许则认为无法找到指定的区块
	if (x < 0 || x > 2 || y < 0 || y > 2) return false;
	int sx = x * 3;
	int sy = y * 3;
	gridVector.clear();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int index = (sy + i) * 9 + sx + j;
			gridVector.push_back(mData[index]);
		}
	}
	return true;
}
