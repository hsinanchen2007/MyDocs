// 两个命名空间和using声明

#include <iostream>

using namespace std;

namespace English {

	int x = 1;

	void print_x()
	{
		cout << "The value of x is " << x << ".\n";
	}

	void hello()
	{
		cout << "Hello!\n";
	}
}

namespace Chinese {

	int x = 2;

	void print_x()
	{
		cout << "变量x的值为" << x << "。\n";
	}

	void hello()
	{
		cout << "你好！\n";
	}
}

int main()
{
	using Chinese::hello;	// 声明Chinese命名空间的使用

	cout << "English::x = " << English::x << '\n';
	cout << "Chinese::x = " << Chinese::x << '\n';

	English::hello();
	hello();				// 不需要Chinese::
}
