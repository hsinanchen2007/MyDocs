// 显示各种变量或常量的类型信息

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	char c;
	short h;
	int i;
	long l;

	cout << "变量c的类型：" << typeid(c).name() << '\n';
	cout << "变量h的类型：" << typeid(h).name() << '\n';
	cout << "变量i的类型：" << typeid(i).name() << '\n';
	cout << "变量l的类型：" << typeid(l).name() << '\n';

	cout << "字符字面量'A'的类型："   << typeid('A').name()   << '\n';
	cout << "整数字面量100的类型："   << typeid(100).name()   << '\n';
	cout << "整数字面量100U的类型："  << typeid(100U).name()  << '\n';
	cout << "整数字面量100L的类型："  << typeid(100L).name()  << '\n';
	cout << "整数字面量100UL的类型：" << typeid(100UL).name() << '\n';
}
