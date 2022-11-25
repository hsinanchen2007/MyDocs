// 自动存储期和静态存储期

#include <iostream>

using namespace std;

int a[7];

void func()
{
	static int b[7];
	int        c[7];

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
		cout << "b[" << i << "] = " << b[i] << '\n';
}

int main()
{
	func();
}
