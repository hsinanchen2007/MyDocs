// 自动存储期和静态存储期

#include <iostream>

using namespace std;

int fx;					// 静态存储期（初始化为0）

int main()
{
	static int sx;		// 静态存储期（初始化为0）
	int 	   ax;		// 自动存储期（初始化为不确定值）

	cout << "ax = " << ax << '\n';
	cout << "sx = " << sx << '\n';
	cout << "fx = " << fx << '\n';
}
