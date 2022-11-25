// 整数的平方和浮点数的平方（函数式宏）

#include <iostream>

using namespace std;

#define sqr(x)  ((x) * (x))

int main()
{
	int    n;
	double x;

	cout << "请输入整数：";  cin >> n;
	cout << "该数的平方为" << sqr(n) << "。\n";

	cout << "请输入实数：";  cin >> x;
	cout << "该数的平方为" << sqr(x) << "。\n";
}
