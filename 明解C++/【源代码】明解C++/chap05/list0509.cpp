// 复制并显示数组的所有元素

#include <iostream>

using namespace std;

int main()
{
	const int n = 5;	// 数组a和b的元素个数
	int a[n];			// 原数组
	int b[n] = {0};		// 目标数组（将所有元素初始化为0）

	for (int i = 0; i < n; i++) {	// 向数组a的元素读入值
		cout << "a[" << i << "] : ";
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)		// 将数组a的所有元素复制至数组b
		b[i] = a[i];

	for (int i = 0; i < n; i++)		// 显示数组b的所有元素的值
		cout << "b[" << i << "] = " << b[i] << '\n';
}
