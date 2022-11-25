// 动态创建整数对象（初始化）

#include <iostream>

using namespace std;

int main()
{
	int* x = new int(5);		// 创建：添加初始值

	cout << "*x = " << *x << '\n';

	delete x;					// 销毁
}
