#pragma once
#include"df.h"
#include"ANS.h"

class GA
{
private:
	std::vector<ANS> ans;
	ANS optimizest;
	void crossing();
	void choose();
	void variation();
	void adjust();
	std::vector<ANS> newpop;
	void jh();
public:
	void search();
	int pop_size;
	ANS global_opt;
	double global_fmax;
	int max_it;	//����������
	int now_it; //��ǰ��������
	double p_crossing;	//�������
	double p_variation;	//�������
	int num_choose;		//ѡ�������
	int num_tot;		//�ܸ�����
};