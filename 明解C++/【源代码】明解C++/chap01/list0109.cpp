// 显示两个变量x与y的和及平均值（显式地初始化变量）

#include <iostream>

using namespace std;

int main()
{
	int x = 63;		// x是int型变量（初始化为63）
	int y = 18;		// x是int型变量（初始化为18）

	cout << "x的值是" << x << "。\n";			// 显示x的值
	cout << "y的值是" << y << "。\n";			// 显示y的值
	cout << "和是" << x + y << "。\n";		// 显示x与y的和
	cout << "平均值是" << (x + y) / 2 << "。\n";	// 显示x与y的平均值
}
