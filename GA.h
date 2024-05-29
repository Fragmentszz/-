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
	int max_it;	//最大迭代次数
	int now_it; //当前迭代次数
	double p_crossing;	//交叉概率
	double p_variation;	//变异概率
	int num_choose;		//选择个体数
	int num_tot;		//总个体数
};