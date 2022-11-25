// 显示多维数组及其元素的类型

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5][3];		// 二维数组
	double b[4][2][3];	// 三维数组

	cout << "数组a的类型：" << typeid(a).name()    << '\n';
	cout << "a的元素类型：" << typeid(a[0]).name() << '\n';
	cout << "数组b的类型：" << typeid(b).name()    << '\n';
	cout << "b的元素类型：" << typeid(b[0]).name() << '\n';
}
