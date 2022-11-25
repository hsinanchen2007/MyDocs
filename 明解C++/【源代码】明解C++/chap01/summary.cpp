/*
	示例程序
*/

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int a;			// a是int型变量
	a = 1;			// 赋值（在创建变量后赋值）
	int b = 5;		// 初始化（在创建变量时赋值）

	srand(time(NULL));			// 设置随机数种子
	int lucky = rand() % 10;	// 0~9的随机数
	cout << "今天的幸运数字是" << lucky << "。\n";
	cout << "除以2的商是" <<   lucky / 2 << "。\n";
	cout << "除以2的余数是" << lucky % 2 << "。\n";

	// 常量对象（不可以修改值的变量）
	const double PI = 3.14;
	double r;
	cout << "半径：";
	cin >> r;
	cout << "半径" << r << "的圆的面积是"
		 << (PI * r * r) << "。\n";

	string name;	// 姓名

	cout << "姓名：";	// 提示输入姓名
	cin >> name;			// 读入（跳过空格）

	cout << "\a你"  "好，" << name << "。\n";
}
