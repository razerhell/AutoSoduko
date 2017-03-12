#include "zmatrix.h"

template<typename T>
inline ZMatrix<T>::ZMatrix(size_t row = 0, size_t col = 0)
{
	mData.resize(row * col);
	mRowSize = row;
	mColSize = col;
}

template<typename T>
inline ZMatrix<T>::ZMatrix(vector<T> data, size_t row, size_t col)
{
	mData = data;
	mRowSize = row;
	mColSize = col;
}

template<typename T>
inline ZMatrix<T>::ZMatrix(const ZMatrix &other)
{
	*this = other;
}

template<typename T>
inline ZMatrix<T>::~ZMatrix()
{
}

template<typename T>
inline const vector<T>&	 ZMatrix<T>::getData() const
{
	return mData;
}

template<typename T>
inline vector<T> ZMatrix<T>::getData()
{
	return mData;
}

template<typename T>
inline ZMatrix<T>& ZMatrix<T>::operator = (const ZMatrix& other)
{
	mData = other.mData;
	mRowSize = other.mRowSize;
	mColSize = other.mColSize;

	return *this;
}

template<typename T>
inline bool ZMatrix<T>::at(size_t index, T & r) const
{
	if (index >= mData.count()) return false;
	r = mData[index];
	return true;
}


template<typename T>
inline bool ZMatrix<T>::at(size_t x, size_t y, T & r) const
{
	if (x >= mColSize || y >= mRowSize) return false;
	size_t index = y * mColSize + x;
	return at(index, r);
}

template<typename T>
inline bool ZMatrix<T>::set(size_t index, const T & v)
{
	if (index >= mData.count()) return false;
	mData[index] = v;
	return true;
}

template<typename T>
inline bool ZMatrix<T>::set(size_t x, size_t y, const T & v)
{
	if (x >= mColSize || y >= mRowSize) return false;
	size_t index = y * mColSize + x;
	return set(index, v);
}
