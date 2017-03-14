#include "supportmatrix.h"
#include <set>

SupportMatrix::SupportMatrix() : ZMatrix(9, 9)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			int index = i * 9 + j;
			std::set<int> supportS;
			for (int i = 1; i <= 9; ++i)
				mData[index].insert(i);
		}
}

int SupportMatrix::converBySoduko(const SodukoMatrix & sdkM)
{
	int converedSets = 0;		// 被操作的集合的数量
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			int row = i;	// 将作为收缩条件的行（纵坐标）
			int col = j;	// 将作为收缩条件的列（横坐标）
			int gridRow, gridCol;	// 将作为收缩条件的区块坐标
			gridRow = row / 3;
			gridCol = col / 3;

		}

	return converedSets;
}

SupportMatrix::~SupportMatrix()
{
}
