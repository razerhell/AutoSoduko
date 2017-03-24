#include "sudokumatrix.h"
#include "supportmatrix.h"
#include "gridmatrix.h"
#include <fstream>

// �Ƶ��հ״�Ӧ�������
int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay = false);
int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay = false);
int recursiveSolve(SudokuMatrix &sdkM, SupportMatrix &supM);
int solveSudoku(string fileName);
int loadFileToVector(string fileName, vector<int> &data);


int main(int argc, char * argv[])
{
	string fileName = "data2.txt";
	if (argc > 1) fileName = argv[1];
	solveSudoku(fileName);

	system("pause");
	return 0;
}

int solveSudoku(string fileName)
{
	//vector<int> data;
	//if (!loadFileToVector(fileName, data))
	//{
	//	printf("\nload file error\n");
	//	system("pause"); 
	//	return 1;
	//}

	//SudokuMatrix sdkM(data.data());

	SudokuMatrix sdkM;
	sdkM.readFile(fileName);
	sdkM.printToScreen();

	// ������ں����������
	solveSudokuBySupportMatrix(sdkM, true);
	sdkM.printToScreen();
	return 0;
}

int loadFileToVector(string fileName, vector<int> &data)
{
	data.resize(81);
	ifstream in(fileName);
	if (!in.is_open()) return 0;
	int i = 0;
	while (i < 81 && !in.eof())
		in >> data[i++];
	return 1;
}

int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay)
{
	SupportMatrix supM;
	supM.converBySoduko(sdkM);

	while (!recursiveSolve(sdkM, supM))
	{	
		sdkM.printToScreen();
		supM.converBySoduko(sdkM);
		system("pause");
	}
	return 1;
}

int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay)
{
	int spaceCount = 0;
	int number;
	int step = 0;

	// ��ѯ�����������Ƿ����ֻ��һ��Ԫ�صļ��ϲ����䷵��
	while (number = supM.getTheOnlyNumber())
	{
		if (number < 0)
			return spaceCount;	// û�н���ֻ��һ��Ԫ�صļ��Ͽɹ�ѡ��
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
		//sdkM.printToScreen();
		return 0;
	}
	// �ó�һ��Ԫ�����ٵķǿռ���
	std::set<int> tempS;
	int index = supM.getMinSet(tempS);
	if (index < 0) 
		return 0;
	int x = index / 10;
	int y = index % 10;
	// �����øü����е�Ԫ�ؽ�����ղ��ݹ�
	std::set<int>::iterator intIte;
	SudokuMatrix tempM = sdkM;
	SupportMatrix tempSM = supM;
	tempSM.set(x, y, std::set<int>());
	for (intIte = tempS.begin(); intIte != tempS.end(); ++intIte)
	{
		int number = *intIte;
		tempM.set(x, y, number);
		tempSM.converByNumber(x, y, number);
		if (1 != recursiveSolve(tempM, tempSM)) continue ;
		sdkM = tempM;
		supM = tempSM;
		return 1;
	}
	return 0;
}