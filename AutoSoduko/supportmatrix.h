#pragma once

#include "gridmatrix.h"
#include "zmatrix.h"
#include "sodukomatrix.h"
#include <set>

// ʹ��std::set<int> �����츨������
class SupportMatrix :public ZMatrix<set<int> >
{
public:
	SupportMatrix();
	// ʹ�ô����soduko����Ը���������������������ļ�������
	int converBySoduko(const SodukoMatrix& sdkM);
	virtual ~SupportMatrix();
};