// 求两个整数值中的较小值和较大值并显示（使用逗号运算符）

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "整数a：";   cin >> a;
	cout << "整数b：";   cin >> b;

	int min, max;		// 较小值、较大值

	if (a < b)
		min = a, max = b;
	else
		min = b, max = a;

	cout << "较小值为" << min << "。\n";
	cout << "较大值为" << max << "。\n";
}
