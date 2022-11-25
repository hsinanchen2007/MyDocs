// 整数数组类IntArray（第2版）的使用例程

#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
	int n;

	cout << "请输入元素个数：";
	cin >> n;

	IntArray x(n);	// 元素个数为n的数组

	for (int i = 0; i < x.size(); i++)					// 对各个元素赋值
		x[i] = i;

	for (int i = 0; i < x.size(); i++)					// 显示各个元素的值
		cout << "x[" << i << "] = " << x[i] << '\n';
}
