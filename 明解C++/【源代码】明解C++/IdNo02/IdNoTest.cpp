// 标识号类IdNo（第2版）的使用例程

#include <iostream>
#include "IdNo.h"

using namespace std;

int main()
{
	IdNo a;		// 第1个标识号
	IdNo b;		// 第2个标识号

	cout << "a的标识号：" << a.id() << '\n';
	cout << "b的标识号：" << b.id() << '\n';
	cout << "目前已经赋予的标识号的最大值：" << IdNo::get_max_id() << '\n';
}
