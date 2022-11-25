// 显示各种整型及其变量的大小

#include <iostream>

using namespace std;

int main()
{
	char c;
	cout << "char型的大小：" << sizeof(char) << '\n';
	cout << "变量c的大小：" << sizeof(c)    << '\n';

	short h;
	cout << "short型的大小：" << sizeof(short) << '\n';
	cout << "变量h的大小：" << sizeof(h)     << '\n';

	int i;
	cout << "int型的大小：" << sizeof(int) << '\n';
	cout << "变量i的大小：" << sizeof(i)   << '\n';

	long l;
	cout << "long型的大小：" << sizeof(long) << '\n';
	cout << "变量l的大小：" << sizeof(l)    << '\n';
}
