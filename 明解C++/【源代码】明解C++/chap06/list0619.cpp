// 按升序排列三个整数值

#include <iostream>

using namespace std;

//--- 交换参数x和y的值 ---//
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

//--- 按升序排列参数a、b、c ---//
void sort(int& a, int& b, int& c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main()
{
	int a, b, c;

	cout << "变量a：";   cin >> a;
	cout << "变量b：";   cin >> b;
	cout << "变量c：";   cin >> c;

	sort(a, b, c);			// 按升序排列a、b、c

	cout << "按升序重新排列变量a、b、c。\n";
	cout << "变量a的值为" << a << "。\n";
	cout << "变量b的值为" << b << "。\n";
	cout << "变量c的值为" << c << "。\n";
}
