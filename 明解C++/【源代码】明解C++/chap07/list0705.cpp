// 由函数计算两个整数值的和与积

#include <iostream>

using namespace std;

//--- 把x与y的和与积赋给*sum和*mul ---//
void sum_mul(int x, int y, int* sum, int* mul)
{
	*sum = x + y;		// 把x与y的和赋给*sum
	*mul = x * y;		// 把x与y的积赋给*mul
}

int main()
{
	int a, b;
	int he = 0, ji = 0;

	cout << "整数a：";   cin >> a;
	cout << "整数b：";   cin >> b;

	sum_mul(a, b, &he, &ji);		// 计算a与b的和与积

	cout << "和为" << he   << "。\n";
	cout << "积为" << ji << "。\n";
}
