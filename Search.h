#pragma once
#include"ANS.h"
#include"SearchArea.h"
#include"Solver.h"


class OneDimensionSearch
{
protected:
	int dim; //������ά��
	OneDimensionSearchFunc targetfunc;
	int max_iteroation;		//����������
	int now_iteration;		//��ǰ��������
	ld a, b;				//��ǰ��Χ
	ld x1, x2;
	ld fx1, fx2;
	ld alpha;
	ANS Ans;
	Solver solver;
public:
	OneDimensionSearch(int _dim);
	/// @brief ��ʼ��һά����
	/// @param _a :������ʼ������
	/// @param _b :������ʼ������
	/// @param _target :������Ŀ�꺯��
	/// @ret void
	//virtual void init(ld _a, ld _b, OneDimensionSearchFunc _target);
	virtual void reSet(ANS _x0, ANS direction, SearchFunc _target);
	/// @brief ��������������
	/// @param _maxit ����������
	virtual void setIteroation(int _maxit);
	ld getAlpha();
	ANS getAns();
	/// @brief ��ʼ����
	virtual void search() = 0;
	ld fmin;
};



