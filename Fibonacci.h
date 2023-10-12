#pragma once
#include"Search.h"
/// @brief ʹ��Fibonacci�����һά��������С��min
class FibonacciSearch
	:public OneDimensionSearch
{
	int nowk;
	long long fn, fn2, fn1;
public:
	FibonacciSearch(int _dim);
	/// @brief ��ʼ��һά����
	/// @param _a :������ʼ������
	/// @param _b :������ʼ������
	/// @param _target :������Ŀ�꺯��
	/// @param eps :����������󳤶�
	/// @ret void
	void init(ANS& _a, ANS& _b, SearchFunc _target,ld eps);
	void setIteration(ld eps);

	void search();
};