// 读入两个实数值，执行加减乘除运算，并显示计算结果

#include <iostream>

using namespace std;

int main()
{
	double x;		// 加减乘除运算的操作数
	double y;		// 加减乘除运算的操作数

	cout << "对x和y执行加减乘除运算。\n";

	cout << "x的值：";		// 提示输入x的值
	cin >> x;				// 向x读入实数值

	cout << "y的值：";		// 提示输入y的值
	cin >> y;				// 向y读入实数值

	cout << "x + y是 << x + y << "。\n";	// 显示x + y的值
	cout << "x - y是" << x - y << "。\n";	// 显示x - y的值
	cout << "x * y是" << x * y << "。\n";	// 显示x * y的值
	cout << "x / y是" << x / y << "。\n";	// 显示x / y的值
}
