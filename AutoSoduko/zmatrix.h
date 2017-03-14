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
	ZMatrix(size_t row = 0, size_t col = 0);
	ZMatrix(vector<T> data, size_t row, size_t col);
	ZMatrix(const ZMatrix &other);
	virtual ~ZMatrix();

	const vector<T>&	getData() const;
	vector<T>			getData();

	// 重载 = 操作符
	virtual ZMatrix<T>& operator = (const ZMatrix& other);

	bool at(size_t index, T & r) const ;
	bool at(size_t x, size_t y, T & r) const ;
	bool set(size_t index, const T& v);
	bool set(size_t x, size_t y, const T& v);

	// 取得第i列的数据
	bool getCol(const int& index, vector<T>& r);
	// 取得第i行的数据
	bool getRow(const int& index, vector<T>& r);
};

#include "zmatrix.inl"

#endif
