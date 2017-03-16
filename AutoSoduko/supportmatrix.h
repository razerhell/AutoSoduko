#pragma once

#include "zmatrix.h"
#include <set>

class SudokuMatrix;

// 使用std::set<int> 来构造辅助矩阵
class SupportMatrix :public ZMatrix<set<int> >
{
protected:
	// 以传入的vector向量对辅助矩阵中(x, y)的集合进行收缩，返回被删减的元素数量
	int converByVector(const int &x, const int &y, const vector<int> &converMatrialVector);

	// 以传入的数字number对(x, y)上的集合进行收缩，返回被删减的元素数量
	int converSetByNumber(const int &x, const int &y, const int &number);

	// 以传入的数字number对第i行上的所有集合进行收缩，返回被收缩的集合数量
	int converRowByNumber(const int &i, const int &number);
	
public:
	// 默认构造函数，默认构造完成之后矩阵中每一个位置的集合都是全集
	SupportMatrix();
	SupportMatrix(const SupportMatrix &other);

	// 使用传入的soduko矩阵对辅助矩阵进行收缩，返回0表示没有集合被操作
	int converBySoduko(const SudokuMatrix &sdkM);

	// 使用传入的数字对辅助矩阵进行收缩，返回0表示没有集合被操作
	int converByNumber(const int &x, const int &y, const int &number);

	// 查询是否存在只含有一个元素的集合，若存在则将其返回，否则返回值为0
	// 返回值形式为x * 100 + y * 10 + number
	// 其中number为该集合中唯一的元素
	int getTheOnlyNumber();

	virtual ~SupportMatrix();
};