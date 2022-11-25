// 整数数组类IntArray（第3版）的使用例程

#include <iomanip>
#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
	int n;
	cout << "a的元素个数：";
	cin >> n;

	IntArray a(n);		// 元素个数为n的数组

	for (int i = 0; i < a.size(); i++)
		a[i] = i;

	IntArray b(128);	// 元素个数为128的数组
	IntArray c(256);	// 元素个数为256的数组

	cout << "b和c的元素个数从" << b.size() << "和" << c.size();
	c = b = a;					// 赋值
	cout << "变为" << b.size() << "和" << c.size() << "。\n";

	IntArray d = b;				// 初始化

	cout << "    a    b    c    d\n";
	cout << "---------------------\n";
	for (int i = 0; i < n; i++) {
		cout << setw(5) << a[i] << setw(5) << b[i]
			 << setw(5) << c[i] << setw(5) << d[i] << '\n';
	}
}
