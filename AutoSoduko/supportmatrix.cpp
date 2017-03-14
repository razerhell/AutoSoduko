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
	int converedSets = 0;		// �������ļ��ϵ�����
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			int row = i;	// ����Ϊ�����������У������꣩
			int col = j;	// ����Ϊ�����������У������꣩
			int gridRow, gridCol;	// ����Ϊ������������������
			gridRow = row / 3;
			gridCol = col / 3;

		}

	return converedSets;
}

SupportMatrix::~SupportMatrix()
{
}
