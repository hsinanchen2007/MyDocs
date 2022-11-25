// 利用递归调用计算阶乘

#include <iostream>

using namespace std;

//--- 递归计算n的阶乘 ---//
int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main()
{
	int x;

	cout << "整数值：";
	cin >> x;

	cout << x << "的阶乘为" << factorial(x) << "。\n";
}
