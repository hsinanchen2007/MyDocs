// 幂运算

#include <iostream>

using namespace std;

//--- 返回x的n次方 ---//
double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 1; i <= n; i++)
		tmp *= x;	// tmp乘以x
	return tmp;
}

int main()
{
	double a;
	int    b;

	cout << "计算a的b次方。\n";
	cout << "实数a：";	cin >> a;
	cout << "整数b：";	cin >> b;
	cout << a << "的" << b << "次方为" << power(a, b) << "。\n";
}
