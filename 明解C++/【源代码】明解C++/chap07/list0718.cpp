// 动态创建整数数组对象

#include <iostream>

using namespace std;

int main()
{
	int asize;					// 数组元素个数
	cout << "元素个数：";
	cin >> asize;

	int* a = new int[asize];	// 创建

	for (int i = 0; i < asize; i++)
		a[i] = i;

	for (int i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	delete[] a;					// 销毁
}
