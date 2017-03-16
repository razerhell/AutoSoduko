#include "sudokumatrix.h"
#include "supportmatrix.h"
#include "gridmatrix.h"

// 推导空白处应填的数字
int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay = false);
int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay = false);

int main(int argc, char * argv[])
{
	SudokuMatrix sdkM;

	if (!sdkM.readFile("data.txt"))
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

int tryReasonSpace(SudokuMatrix &m, SupportMatrix &supM, bool isDisplay)
{
	int spaceCount = 0;
	int number;
	int step = 0;

	// 查询辅助矩阵中是否存在只有一个元素的集合并将其返回
	while (number = supM.getTheOnlyNumber())
	{
		int x = number / 100;	number %= 100;
		int y = number / 10;	number %= 10;
		// 是否需要检查是否冲突？
		if (m.isConflict(x, y, number)) return spaceCount;	// 检验是否冲突，若冲突则返回1
		m.set(x, y, number);
		supM.converByNumber(x, y, number);
		++spaceCount;

		if (!isDisplay) continue;
		// 输出单次求解结果
		++step;
		printf("\n\n%d\t==============\n", step);
		m.printToScreen();
	}

	return spaceCount;
}

int solveSudokuBySupportMatrix(SudokuMatrix &sdkM, bool isDisplay)
{
	SupportMatrix supM;
	supM.converBySoduko(sdkM);
	int spaceCount = 0;
	int temp;

	while (temp = tryReasonSpace(sdkM, supM))
		spaceCount += temp;

	return spaceCount;
}