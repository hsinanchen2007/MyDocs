// 显示数组及其元素的类型

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5];
	double b[7];

	cout << "数组a的类型：" << typeid(a).name()    << '\n';	// int数组
	cout << "a的元素类型：" << typeid(a[0]).name() << '\n';	// 它的元素

	cout << "数组b的类型：" << typeid(b).name()    << '\n';	// double数组
	cout << "b的元素类型：" << typeid(b[0]).name() << '\n';	// 它的元素
}
