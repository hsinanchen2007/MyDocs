// 计算两个整数值的实数平均值（其二：静态类型转换运算符）

#include <iostream>

using namespace std;

int main()
{
	int x, y;

	cout << "计算两个整数值x和y的平均值。\n";
	cout << "x的值：";	cin >> x;	// 向x读入整数值
	cout << "y的值：";	cin >> y;	// 向y读入整数值

	double ave = static_cast<double>(x + y) / 2;	// 计算实数平均值
	cout << "x和y的平均值为" << ave << "。\n";	// 显示平均值
}
