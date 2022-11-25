// 求三个整数值中的最大值（增加函数声明）

#include <iostream>

using namespace std;

int max(int a, int b, int c);

int main()
{
	int a, b, c;

	cout << "整数a：";   cin >> a;
	cout << "整数b：";   cin >> b;
	cout << "整数c：";   cin >> c;

	cout << "最大值为" << max(a, b, c) << "。\n";
}

//--- 返回a、b、c中的最大值 ---//
int max(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}
