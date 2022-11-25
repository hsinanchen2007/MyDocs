// 两个命名空间

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
	cout << "English::x = " << English::x << '\n';
	English::print_x();
	English::hello();

	cout << "Chinese::x = " << Chinese::x << '\n';
	Japanese::print_x();
	Japanese::hello();
}
