// 用于验证的标识号类VerId的使用例程

#include <iostream>
#include "VerId.h"

using namespace std;

int main()
{
	VerId a;		// 第1个标识号
	VerId b;		// 第2个标识号

	cout << "a的标识号：" << a.id() << '\n';
	cout << "b的标识号：" << b.id() << '\n';
	cout << "创建的对象的个数：" << VerId::counter << '\n';
	cout << "创建的对象的个数：" << a.counter << '\n';
	cout << "创建的对象的个数：" << b.counter << '\n';
}
