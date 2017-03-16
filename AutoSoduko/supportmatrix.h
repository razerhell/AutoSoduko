#pragma once

#include "zmatrix.h"
#include <set>

class SudokuMatrix;

// ʹ��std::set<int> �����츨������
class SupportMatrix :public ZMatrix<set<int> >
{
protected:
	// �Դ����vector�����Ը���������(x, y)�ļ��Ͻ������������ر�ɾ����Ԫ������
	int converByVector(const int &x, const int &y, const vector<int> &converMatrialVector);

	// �Դ��������number��(x, y)�ϵļ��Ͻ������������ر�ɾ����Ԫ������
	int converSetByNumber(const int &x, const int &y, const int &number);

	// �Դ��������number�Ե�i���ϵ����м��Ͻ������������ر������ļ�������
	int converRowByNumber(const int &i, const int &number);
	
public:
	// Ĭ�Ϲ��캯����Ĭ�Ϲ������֮�������ÿһ��λ�õļ��϶���ȫ��
	SupportMatrix();
	SupportMatrix(const SupportMatrix &other);

	// ʹ�ô����soduko����Ը��������������������0��ʾû�м��ϱ�����
	int converBySoduko(const SudokuMatrix &sdkM);

	// ʹ�ô�������ֶԸ��������������������0��ʾû�м��ϱ�����
	int converByNumber(const int &x, const int &y, const int &number);

	// ��ѯ�Ƿ����ֻ����һ��Ԫ�صļ��ϣ����������䷵�أ����򷵻�ֵΪ0
	// ����ֵ��ʽΪx * 100 + y * 10 + number
	// ����numberΪ�ü�����Ψһ��Ԫ��
	int getTheOnlyNumber();

	virtual ~SupportMatrix();
};