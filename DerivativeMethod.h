#pragma once
#include"df.h"
#include"Search.h"

class DerivativeMethod
{
	int dim; //������ά��
	SearchFunc targetfunc;
	OneDimensionSearch& Search;
	ANS x0;
public:
	DerivativeMethod(int _dim,OneDimensionSearch& _Search,ANS _x0, SearchFunc _target);
};