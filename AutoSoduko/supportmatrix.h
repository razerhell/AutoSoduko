#pragma once

#include "gridmatrix.h"
#include "zmatrix.h"
#include "sodukomatrix.h"
#include <set>

// ʹ��std::set<int> �����츨������
class SupportMatrix :public ZMatrix<set<int> >
{
protected:
	// �Դ����vector�����Ը���������(x, y)�ļ��Ͻ������������ر�ɾ����Ԫ������
	int converByVector(const int &x, const int &y, const vector<int> & converMatrialVector);

	// �Դ��������number��(x, y)�ϵļ��Ͻ������������ر�ɾ����Ԫ������
	int converSetByNumber(const int &x, const int &y, const int &number);

	// �Դ��������number�Ե�i���ϵ����м��Ͻ������������ر������ļ�������
	int converRowByNumber(const int &i, const int &number);
	
public:
	// Ĭ�Ϲ��캯����Ĭ�Ϲ������֮�������ÿһ��λ�õļ��϶���ȫ��
	SupportMatrix();

	// ʹ�ô����soduko����Ը�������������������ر������ļ�������
	int converBySoduko(const SodukoMatrix& sdkM);

	// ʹ�ô�������ֶԸ�������������������ر������ļ�������
	int converByNumber(const int & x, const int & y, const int & number);

	virtual ~SupportMatrix();
};