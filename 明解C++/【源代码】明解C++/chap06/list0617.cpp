// 引用对象

#include <iostream>

using namespace std;

int main()
{
	int  x = 1;
	int  y = 2;
	int& a = x;					// 用x初始化a（a引用x）

	cout << "a = " << a << '\n';
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';

	a = 5;						// 把5赋给a

	cout << "a = " << a << '\n';
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
}
