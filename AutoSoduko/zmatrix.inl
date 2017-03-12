
template<typename T>
inline ZMatrix<T>::ZMatrix(vector<T> data = vector<T>(), size_t row = 0, size_t col = 0)
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
}