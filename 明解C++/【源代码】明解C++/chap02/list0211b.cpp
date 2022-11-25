// 显示读入的两个整数值的差

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "整数a：";   cin >> a;
	cout << "整数b：";   cin >> b;

	cout << "差为" << (a < b ? b - a : a - b) << "。\n";
}
