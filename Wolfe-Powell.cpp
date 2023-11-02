#include"Wolfe-Powell.h"
#include"XlsxWriter.h"
WolfePowell::WolfePowell(int _dim):OneDimensionSearch(_dim),fp0(_dim),direction(_dim)
{

}
void WolfePowell::init(ANS& _a, ANS& _direction, ld _right, SearchFunc _target, ld _alpha, ld _miu, ld _sigma)
{
	left = 0, right = _right;
	direction = _direction;
	ANS tmp = _a + direction.Numdot(right);
	OneDimensionSearch::init(_a, tmp, _target);
	alpha = _alpha;
	f0 = targetfunc(a);
	fp0 = derivative(targetfunc, a) * direction;
	miu = _miu, sigma = _sigma;
}

bool WolfePowell::lowerBound()
{
	ANS tmp = (a + direction.Numdot(alpha));
	ld fp1 = derivative(targetfunc, tmp) * direction;
	using namespace std;
	cout << alpha << " " << fp0 << " " << fp1 << endl;
	if (fp1 >= fp0 * sigma)	return 1;
	return 0;
}

bool WolfePowell::upperBound()
{
	ANS tmp = (a + direction.Numdot(alpha));
	ld f1 = targetfunc(tmp);
	using namespace std;
	cout << alpha << " " << f0 << " " << f1 << " " << fp0 << endl;
	if (f0 - f1 >= -fp0 * miu * alpha)	return 1;
	return 0;
}


void WolfePowell::search()
{
	XlsxWriter xl("./baogao/third/ans.xlsx", "WolfePowell");
	xl.nextRow();
	xl.write(f0); xl.write(fp0);
	while (1)
	{
		ANS tmp = (a + direction.Numdot(alpha));
		ld f1 = targetfunc(tmp);
		ld fp1 = derivative(targetfunc, tmp) * direction;
		xl.nextRow();
		xl.write(alpha); xl.writeAns(tmp); xl.write(f1); xl.write(fp1);
		if (!upperBound()) {						//判断式1
			right = alpha;
			alpha = 0.5 * (left + right);
			continue;
		}
		else if (!lowerBound()) {					//判断式2
			left = alpha;
			alpha = std::min(0.5 * (left + right), 2 * left);
			continue;
		}
		break;
	}
	printf("%.6Lf\n", alpha);
	xl.nextRow();
	ans = a + direction.Numdot(alpha);
	fmin = targetfunc(ans);
	printf("fmin = %.6Lf, ",fmin); ans.print();
	xl.write(alpha); xl.writeAns(ans); xl.write(fmin);
}


void WP::solve(SearchFunc F)
{
	//auto Rosenbroke = [](const ANS& x) -> ld {
	//	if (x.dim != 2)
	//	{
	//		printf("输入向量长度不为2!\n");
	//		return 0;
	//	}
	//	return 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]) + (1 - x[0]) * (1 - x[0]);
	//};

	//std::vector<ld> left = { 0.0L,0.0L }, direction = { 1.0L,0.0L };
	//WolfePowell wp(2);
	//ANS l(left), d(direction);
	//wp.init(l, d, INF, Rosenbroke, 1, 0.1L, 0.5L);
	//wp.search();
	std::vector<ld> left = { 0.0L}, direction = {1.0L};
	WolfePowell wp(1);
	ANS l(left), d(direction);
	wp.init(l, d, INF, F, 1, 0.3L, 0.4L);
	wp.search();


}