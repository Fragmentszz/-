#pragma once
#include"ANS.h"




class OneDimensionSearch
{
protected:
	int dim; //������ά��
	SearchFunc targetfunc;
	int max_iteroation;		//����������
	int now_iteration;		//��ǰ��������
	ANS a, b;				//��ǰ��Χ
	ANS x1, x2;
	ld fx1, fx2;
	ANS ans;
	ld fmin;
public:
	OneDimensionSearch(int _dim);
	/// @brief ��ʼ��һά����
	/// @param _a :������ʼ������
	/// @param _b :������ʼ������
	/// @param _target :������Ŀ�꺯��
	/// @ret void
	virtual void init(ANS& _a, ANS& _b, SearchFunc _target);
	/// @brief ��������������
	/// @param _maxit ����������
	virtual void setIteroation(int _maxit);
	/// @brief ��ʼ����
	virtual void search() = 0;
};



