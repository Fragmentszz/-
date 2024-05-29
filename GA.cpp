#include"GA.h"
#include<ctime>
#include<algorithm>
#include<OpenXLSX/OpenXLSX.hpp>
int ANS::len = N;

void GA::adjust()
{
	;//for (int i = 0; i < ans.size(); i++)	ans[i]->adjust();
}

int randseed = time(0);
void GA::search()
{

	using namespace OpenXLSX;
	XLDocument doc = XLDocument();
	doc.open("./script/pro.xlsx");
	auto wb = doc.workbook();
	auto ws = wb.worksheet("Sheet1");
	srand(randseed);
	ans.clear();
	global_fmax = -1e9 - 7;
	for (int i = 0; i < pop_size; i++) {
		ANS nowans;
		for (int i = 0; i < N; i++)
		{
			int t = (int)(rand() * 1.0 / (1 + RAND_MAX)*2);
			randseed = (rand() + randseed) % (998444353);
			nowans.individual[i] = t;
		}
		nowans.cacu();
		ans.push_back(nowans);
		//printf("%.6lf\n", ans[i].ys());
	}
	srand(randseed);
	for (int i = 0; i < max_it; i++)
	{
		jh();
		double syd = -1e9 - 7;
		int minpos = -1;
		for (int j = 0; j < ans.size(); j++)
		{
			if (syd < ans[j].adapting)
			{
				syd = ans[j].adapting;
				minpos = j;
			}
			//printf("%.6lf\n", ans[j].ys());
		}
		optimizest = ans[minpos];
		if (global_fmax < optimizest.adapting)
		{
			global_fmax = optimizest.adapting;
			global_opt = optimizest;
		}
		ws.cell(i + 1, 1).value() = i + 1;
		ws.cell(i + 1, 2).value() = optimizest.adapting;
		//printf("%d次迭代，最优值为:%.6lf\n", i + 1, optimizest.adapting);
		//getchar();
	}
	doc.save();
	doc.close();
	//printf("全局最优值:%.6lf, x = %.6lf\n",  global_opt.adapting,global_opt.ys());
}

void GA::jh()
{
	newpop.clear();
	crossing();
	//for (auto nans : ans)
	//{
	//	printf("%.6lf\n", nans.ys());
	//}
	variation();
	choose();
	ans.resize(pop_size);
}


void GA::variation()
{
	for (int i = 0; i < pop_size; i++)
	{
		double rd = rand() * 1.0 / (1 + RAND_MAX);
		if (rd < p_variation)
		{
			ANS nowpop = ans[i];
			int pos = (int)(rand() * 1.0 / (1 + RAND_MAX) * N);
			nowpop.individual[pos] = ~nowpop.individual[pos];
			nowpop.cacu();
			ans.push_back(nowpop);
		}
	}
}

void GA::crossing()
{	
	for (int i = 0; i < pop_size; i++)
	{
		for (int j = i+1; j < pop_size && j < i+2 ; j++)
		{
			double rd = rand() * 1.0 / (1 + RAND_MAX);
			if (rd < p_crossing)			//交叉
			{
				int pos = (rand() * 1.0 / (1 + RAND_MAX)) * (1 + N);
				bs nowpop;
				for (int k = 0; k < pos; k++)
				{
					nowpop[k] = ans[i].individual[k];
				}
				for (int k = pos; k < N; k++)
				{
					nowpop[k] = ans[i].individual[k];
				}
				ANS nowindiv;
				nowindiv.individual = nowpop;
				nowindiv.cacu();
				ans.push_back(nowindiv);
			}
		}
	}
}

bool cmp(const ANS& a,const ANS& b)
{
	return a.adapting > b.adapting;
}

void GA::choose()
{
	sort(ans.begin(), ans.end(),cmp);
	std::vector<double> lp;
	std::vector<double> syd;
	double sum = 0;
	std::vector<ANS> npop;
	double minv = 1e9;
	for (int i = 0; i < ans.size(); i++)
	{
		syd.push_back(ans[i].adapting);
		minv = std::min(minv, ans[i].adapting);
	}
	minv -= 0.01;
	for (int i = 0; i < syd.size(); i++)
	{
		syd[i] -= minv;
		sum += syd[i];
	}
	syd[0] = syd[0] / sum;
	for (int i = 1; i < ans.size(); i++)
	{
		syd[i] = syd[i - 1] + syd[i] / sum;
	}
	for (int i = 0; i < pop_size; i++)
	{
		lp.push_back(rand() * 1.0 / (1 + RAND_MAX));
	}
	sort(lp.begin(),lp.end());
	int pointer = 0;
	for (int i = 0; i < pop_size; i++)
	{
		while (syd[pointer] < lp[i])	pointer++;
		npop.push_back(ans[pointer]);
	}
	ans = npop;
}