#ifndef ZMATRIX_H
#define ZMATRIX_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class ZMatrix
{
private:
	size_t		mRowSize;
	size_t		mColSize;
protected:
	vector<T>	mData;

public:
	// 提供三种形式的构造函数：无参，全参，拷贝构造函数
	ZMatrix(vector<T> data = vector<T>(), size_t row = 0, size_t col = 0);
	ZMatrix(const ZMatrix &other);

	const vector<T>&	getData() const;
	vector<T>			getData();

	// 重载 = 操作符
	ZMatrix<T>& operator = (const ZMatrix& other);
};

#include "zmatrix.inl"

#endif
