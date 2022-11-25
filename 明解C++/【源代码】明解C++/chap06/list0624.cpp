// 返回数组元素的引用的函数

#include <iostream>

using namespace std;

const int a_size = 5;		// 数组a的元素个数

//--- 返回a[idx]的引用 ---//
int& r(int idx)
{
	static int a[a_size];
	return a[idx];			// 返回a[idx]的引用
}

int main()
{
	for (int i = 0; i < a_size; i++)
		r(i) = i;

	for (int i = 0; i < a_size; i++)
		cout << "r(" << i << ") = " << r(i) << '\n';
}
