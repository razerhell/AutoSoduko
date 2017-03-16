#include "sudokumatrix.h"
#include "gridmatrix.h"



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

	sdkM.solveSudokuBySupportMatrix(true);

	system("pause");
	return 0;
}