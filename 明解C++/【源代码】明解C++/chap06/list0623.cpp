// 返回引用的函数

#include <iostream>

using namespace std;

//--- 返回x的引用 ---//
int& ref()
{
	static int x;	// 静态存储期
	return x;
}

int main()
{
	ref() = 5;									// 对ref()赋值
	cout << "ref() = " << ref() << '\n';		// 显示ref()的值
}
