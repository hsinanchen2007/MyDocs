// 确认前置形式的++x是左值表达式，后置形式的x++是右值表达式

#include <iostream>

using namespace std;

int main()
{
	int x = 0;

	++x = 5;				// OK：前置形式可以放在左边
	cout << "x的值是" << x << "。\n";

	x++ = 10;				// 错误：后置形式不可以放在左边
	cout << "x的值是" << x << "。\n";
}
