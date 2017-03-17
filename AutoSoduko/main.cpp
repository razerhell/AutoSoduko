#include "sudokumatrix.h"
#include "supportmatrix.h"
#include "gridmatrix.h"

// �Ƶ��հ״�Ӧ�������
int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay = false);
int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay = false);
int recursiveSolve(SudokuMatrix &sdkM, SupportMatrix &supM);

int main(int argc, char * argv[])
{
	SudokuMatrix sdkM;

	if (!sdkM.readFile("data1.txt"))
	{
		printf("\nload file error\n");
		system("pause");
		return 1;
	}
	sdkM.printToScreen();

	solveSudokuBySupportMatrix(sdkM, true);
	sdkM.printToScreen();

	system("pause");
	return 0;
}

int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay)
{
	SupportMatrix supM;
	supM.converBySoduko(sdkM);

	return recursiveSolve(sdkM, supM);
}

int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay)
{
	int spaceCount = 0;
	int number;
	int step = 0;

	// ��ѯ�����������Ƿ����ֻ��һ��Ԫ�صļ��ϲ����䷵��
	while (number = supM.getTheOnlyNumber())
	{
		int x = number / 100;	number = number % 100;
		int y = number / 10;	number = number % 10;
		// �Ƿ���Ҫ����Ƿ��ͻ��
		if (m.isConflict(x, y, number)) 
			return -1;	// �����Ƿ��ͻ������ͻ�򷵻�-1
		m.set(x, y, number);
		supM.converByNumber(x, y, number);
		++spaceCount;

		if (!isDisplay) continue;
		// ������������
		++step;
		printf("\n\n%d\t==============\n", step);
		m.printToScreen();
	}
	return spaceCount;
}

int recursiveSolve(SudokuMatrix &sdkM, SupportMatrix &supM)
{

	// �������������
	int temp = tryReasonSpace(sdkM, supM);
	if (sdkM.getSpaceCount() == 0) 
		return 1;
	if (temp < 0)
	{
		sdkM.printToScreen();
		return 0;
	}
	// �ó�һ��Ԫ�����ٵķǿռ���
	std::set<int> tempS;
	int index = supM.getMinSet(tempS);
	if (index < 0) 
		return 0;
	int x = index / 10;
	int y = index % 10;
	std::set<int>::iterator intIte;
	SudokuMatrix tempM = sdkM;
	SupportMatrix tempSM = supM;
	tempSM.set(x, y, std::set<int>());
	for (intIte = tempS.begin(); intIte != tempS.end(); ++intIte)
	{
		int number = *intIte;
		tempM.set(x, y, number);
		tempSM.converByNumber(x, y, number);
		if (!recursiveSolve(tempM, tempSM)) continue ;
		sdkM = tempM;
		return 1;
	}
	return 0;
}