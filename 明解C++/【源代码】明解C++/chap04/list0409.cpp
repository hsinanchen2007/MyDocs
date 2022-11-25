// 显示关系运算符、相等运算符和逻辑非运算符返回的值

#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "整数a，b：";
	cin >> a >> b;

	cout << boolalpha;

	cout << "a <  b = " << (a <  b) << '\n';
	cout << "a <= b = " << (a <= b) << '\n';
	cout << "a >  b = " << (a >  b) << '\n';
	cout << "a >= b = " << (a >= b) << '\n';
	cout << "a == b = " << (a == b) << '\n';
	cout << "a != b = " << (a != b) << '\n';
	cout << "!a     = " << (!a)     << '\n';
	cout << "!b     = " << (!b)     << '\n';
}
