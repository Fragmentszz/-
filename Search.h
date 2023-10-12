#pragma once
#include"df.h"

class ANS
{
public:
	std::vector<ld> ans;
	int dim;		//������ά��
	ANS(int _dim);
	ANS(int _dim, std::vector<ld>&);
	ANS(std::vector<ld>&);
	ANS(ANS&);
	/// @brief �������������Ա���
	/// @param k ����
	/// @return 
	ANS Numdot(ld k);
	ANS& operator=(const std::vector<ld>&);
	ANS& operator=(const ANS&);
	ANS operator+(const ANS&);
	ANS operator-(const ANS& b);
	friend ld dis(ANS&, ANS&);
	void print() const;
	
};

typedef ld(*SearchFunc)(const ANS&);



/// @brief ���㳤����ͬ��������ŷ�Ͼ���
/// @param a 
/// @param b 
/// @return ����
ld dis(ANS& a, ANS& b);







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



