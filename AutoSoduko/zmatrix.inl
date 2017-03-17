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
	if (index >= mData.size()) return false;
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
	if (index >= mData.size()) return false;
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

template<typename T>
inline bool ZMatrix<T>::getCol(const size_t& index, vector<T>& r) const
{
	if (index >= mColSize || 0 == mRowSize) return false;
	r.clear();
	r.resize(mRowSize);
	for (size_t i = 0; i < mRowSize; ++i)
		at(index, i, r[i]);
	return true;
}

template<typename T>
inline bool ZMatrix<T>::getCol(const size_t & index, std::set<T>& r, bool isInit = true) const
{
	if (index >= mColSize || 0 == mRowSize) return false;
	if (isInit) r.clear();
	int n;

	for (size_t i = 0; i < mRowSize; ++i)
		r.insert(mData[i * mColSize + index]);

	return true;
}

template<typename T>
inline bool ZMatrix<T>::getRow(const size_t & index, vector<T>& r) const
{
	if (index >= mRowSize || 0 == mColSize) return false;
	r.clear();
	r.resize(mColSize);
	for (size_t i = 0; i < mRowSize; ++i)
		at(i, index, r[i]);
	return true;
}

template<typename T>
inline bool ZMatrix<T>::getRow(const size_t & index, std::set<T>& r, bool isInit = true) const
{
	if (index >= mRowSize || 0 == mColSize) return false;
	if (isInit) r.clear();
	int n;
	for (size_t i = 0; i < mColSize; ++i)
			r.insert(mData[index * mColSize + i]);
	return true;
}

template<typename T>
inline bool ZMatrix<T>::getGrid(const size_t & x, const size_t & y, vector<T> &gridVector) const
{
	if (mRowSize != 9 || mColSize != 9) return false;
	// 下标非法不允许则认为无法找到指定的区块
	if (x < 0 || x > 2 || y < 0 || y > 2) return false;
	int sx = x * 3;
	int sy = y * 3;
	gridVector.clear();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int index = (sy + i) * 9 + sx + j;
			gridVector.push_back(mData[index]);
		}
	}
	return true;
}

template<typename T>
inline bool ZMatrix<T>::getGrid(const size_t & x, const size_t & y, std::set<T> &gridSet, bool isInit) const
{
	if (mRowSize != 9 || mColSize != 9) return false;
	// 下标非法不允许则认为无法找到指定的区块
	if (x < 0 || x > 2 || y < 0 || y > 2) return false;
	int sx = x * 3;
	int sy = y * 3;
	if (isInit) gridSet.clear();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int index = (sy + i) * 9 + sx + j;
			gridSet.insert(mData[index]);
		}
	}
	return true;
}
