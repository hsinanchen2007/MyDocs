// 标识号类IdNo（第1版）的使用例程

#include <iostream>
#include "IdNo.h"

using namespace std;

int main()
{
	IdNo a;		// 第1个标识号
	IdNo b;		// 第2个标识号
	IdNo c[4];	// 第3~6个标识号

	cout << "a的标识号：" << a.id() << '\n';
	cout << "b的标识号：" << b.id() << '\n';
	for (int i = 0; i < 4; i++)
		cout << "c[" << i << "]的标识号：" << c[i].id() << '\n';
}
