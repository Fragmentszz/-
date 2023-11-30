#pragma once
#include"df.h"
#include"Search.h"

class DerivativeMethod
{
protected:
	int dim; //������ά��
	SearchFunc targetfunc;
	OneDimensionSearch& Search;
	ld eps;
	virtual void getDirection();
	void getNewFunc();
	ANS x0;
	ANS nowDerivative;				//��ǰ����
	ANS nowDirection;

public:
	DerivativeMethod(int _dim,OneDimensionSearch& _Search,ANS _x0, SearchFunc _target,ld _eps);
	//��ȷ��
	void search();
	ANS ans;
	ld fmin;
};
