// 计数器类Counter（第2版）的使用例程

#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
	int no;
	Counter x;
	Counter y;

	cout << "向上计数次数：";
	cin >> no;

	for (int i = 0; i < no; i++)		// 向上计数（x为后置而y为前置）
		cout << x++ << ' ' << ++y << '\n';

	cout << "向下计数次数：";
	cin >> no;

	for (int i = 0; i < no; i++)		// 向下计数（x为后置而y为前置）
		cout << x-- << ' ' << --y << '\n';

	if (!x)								// 由逻辑非运算符判断
		cout << "x为0。\n";
	else 
		cout << "x不为0。\n";
}
