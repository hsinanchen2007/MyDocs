// 交换两个参数值的函数（错误）

#include <iostream>

using namespace std;

//--- 交换参数x和y的值（错误）---//
void swap(int x, int y)
{
	int t = x;
	x = y;
	y = t;
}

int main()
{
	int a, b;

	cout << "变量a：";   cin >> a;
	cout << "变量b：";   cin >> b;

	swap(a, b);			// 交换a和b？

	cout << "交换变量a和b的值。\n";
	cout << "变量a的值为" << a << "。\n";
	cout << "变量b的值为" << b << "。\n";
}
