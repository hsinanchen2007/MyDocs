// 幂运算

#include <iostream>

using namespace std;

//--- 返回x的n次方 ---//
double power(double x, int n);

int main()
{
	double a;
	int    b;

	cout << "计算a的b次方。\n";
	cout << "实数a：";	cin >> a;
	cout << "整数b：";	cin >> b;
	cout << a << "的" << b << "次方为" <<
			power(a, b) << "。\n";
}
