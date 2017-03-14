#pragma once

#include "gridmatrix.h"
#include "zmatrix.h"
#include "sodukomatrix.h"
#include <set>

// 使用std::set<int> 来构造辅助矩阵
class SupportMatrix :public ZMatrix<set<int> >
{
public:
	SupportMatrix();
	// 使用传入的soduko矩阵对辅助矩阵进行收缩被操作的集合数量
	int converBySoduko(const SodukoMatrix& sdkM);
	virtual ~SupportMatrix();
};