#include "supportmatrix.h"
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

int SupportMatrix::converBySoduko(const SudokuMatrix & sdkM)
{
	int converedSets = 0;		// �������ļ��ϵ�����
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			int row = i;	// ����Ϊ�����������У������꣩
			int col = j;	// ����Ϊ�����������У������꣩
			int gridRow, gridCol;	// ����Ϊ������������������
			gridRow = row / 3;
			gridCol = col / 3;

			// ����λ�����������֣���Ӧֱ����ո�λ��set�����ٽ�������
			int numberTest;
			if (sdkM.at(col, row, numberTest) && numberTest != 0)
			{
				mData[i * 9 + j].clear();
				continue ;
			}

			// ���н�������
			vector<int> converMatrialVector;
			if (sdkM.getRow(row, converMatrialVector))
				converedSets += converByVector(j, i, converMatrialVector) > 0 ? 1 : 0;

			// ���н�������
			if (sdkM.getCol(col, converMatrialVector))
				converedSets += converByVector(j, i, converMatrialVector) > 0 ? 1 : 0;

			// �������������
			if (sdkM.getGrid(gridCol, gridRow, converMatrialVector))
				converedSets += converByVector(j, i, converMatrialVector) > 0 ? 1 : 0;
		}

	return converedSets;
}

int SupportMatrix::converByNumber(const int & x, const int & y, const int & number)
{
	int converedSets = 0;
	int gridX = x / 3;
	int gridY = y / 3;

	// ��Ԫ���������ϵļ��Ͻ�������
	for (int i = 0; i < 9; ++i)
		converedSets += converSetByNumber(i, y, number);
	
	// ��Ԫ���������ϵļ��Ͻ�������
	for (int i = 0; i < 9; ++i)
		converedSets += converSetByNumber(x, i, number);

	// ��Ԫ�����������ϵļ��Ͻ�������
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

SupportMatrix::~SupportMatrix()
{
}
