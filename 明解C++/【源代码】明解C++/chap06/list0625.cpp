// 求两个值中的较大值、三个值中的最大值的函数（重载）

#include <iostream>

using namespace std;

//--- 返回a、b中的较大值 ---//
int max(int a, int b)
{
	return a > b ? a : b;
}

//--- 返回a、b、c中的最大值 ---//
int max(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main()
{
	int x, y, z;

	cout << "x的值：";
	cin >> x;

	cout << "y的值：";
	cin >> y;

	// 两个值中的较大值
	cout << "x和y中的较大值为" << max(x, y) << "。\n";

	cout << "z的值";
	cin >> z;

	// 三个值中的最大值
	cout << "x、y、z中的最大值为" << max(x, y, z) << "。\n";
}
