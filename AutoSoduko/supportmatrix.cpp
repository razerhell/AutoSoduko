#include "supportmatrix.h"
#include "sudokumatrix.h"
#include <set>

int SupportMatrix::converByVector(const int &x, const int &y, const vector<int>& converMatrialVector)
{
	int converedElements = 0;
	int index = y * 9 + x;
	for (size_t i = 0; i < converMatrialVector.size(); ++i)
		converedElements += converSetByNumber(x, y, converMatrialVector[i]);
	return converedElements;
}

int SupportMatrix::converSetByNumber(const int & x, const int & y, const int & number)
{
	int index = y * 9 + x;
	std::set<int>::iterator fm = mData[index].find(number);
	if (fm == mData[index].end()) return 0;
	mData[index].erase(fm);
	return 1;
}

int SupportMatrix::converRowByNumber(const int & i, const int & number)
{
	int converedSets = 0;
	for (int j = 0; j < 9; ++j)
		converedSets += converSetByNumber(j, i, number);
	return converedSets;
}

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

SupportMatrix::SupportMatrix(const SupportMatrix & other)
{	
	*this = other;
}

SupportMatrix::~SupportMatrix()
{
}

int SupportMatrix::converBySoduko(const SudokuMatrix &sdkM)
{
	int converedSets = 0;		// 被操作的集合的数量
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			int y = i;	// 将作为收缩条件的行（纵坐标）
			int x = j;	// 将作为收缩条件的列（横坐标）
			int gridY, gridX;	// 将作为收缩条件的区块坐标
			gridY = y / 3;
			gridX = x / 3;

			// 若该位置上已填数字，则应直接清空该位置set无需再进行收缩
			int numberTest;
			if (sdkM.at(x, y, numberTest) && numberTest != 0)
			{
				mData[y * 9 + x].clear();
				continue ;
			}

			// 以行进行收缩
			vector<int> converMatrialVector;
			if (sdkM.getRow(y, converMatrialVector))
				converedSets += converByVector(x, y, converMatrialVector) > 0 ? 1 : 0;

			// 以列进行收缩
			if (sdkM.getCol(x, converMatrialVector))
				converedSets += converByVector(x, y, converMatrialVector) > 0 ? 1 : 0;

			// 以区块进行收缩
			if (sdkM.getGrid(gridX, gridY, converMatrialVector))
				converedSets += converByVector(x, y, converMatrialVector) > 0 ? 1 : 0;
		}

	return converedSets;
}

int SupportMatrix::converByNumber(const int & x, const int & y, const int & number)
{
	int converedSets = 0;
	int gridX = x / 3;
	int gridY = y / 3;

	// 对元素所在行上的集合进行收缩
	for (int i = 0; i < 9; ++i)
		converedSets += converSetByNumber(i, y, number);
	
	// 对元素所在列上的集合进行收缩
	for (int i = 0; i < 9; ++i)
		converedSets += converSetByNumber(x, i, number);

	// 对元素所在区块上的集合进行收缩
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			converedSets += converSetByNumber(gridX * 3 + i, gridY * 3 + j, number);
	return converedSets;
}

int SupportMatrix::getTheOnlyNumber()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			std::set<int> tempS = mData[j * 9 + i];
			if (tempS.size() != 1) continue;
			int number = *(tempS.begin());
			return i * 100 + j * 10 + number;
		}
	return 0;
}

