// 求两个整数值中的较大值（函数版）

#include <iostream>

using namespace std;

//--- 返回a、b中的较大值 ---//
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int a, b;

	cout << "整数a：";   cin >> a;
	cout << "整数b：";   cin >> b;

	cout << "较大值为" << max(a, b) << "。\n";
}
