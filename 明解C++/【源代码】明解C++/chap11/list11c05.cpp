// 使用#if指令注释程序

#include <iostream>

using namespace std;

#define DEBUG	0

int main()
{
	int a = 5;
	int x = 7;

#if DEBUG == 1
	a = x;				// 把x赋给a
#endif

	cout << "a的值为" << a << "。\n";
}
