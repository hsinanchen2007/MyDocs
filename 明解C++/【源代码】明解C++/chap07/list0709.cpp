// 将数组元素逆序排列（函数版）

#include <iostream>

using namespace std;

//--- 将元素个数为n的数组a逆序排列 ---//
void reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

int main()
{
	const int n = 5;				// 数组c的元素个数
	int c[n];

	for (int i = 0; i < n; i++) {	// 对各元素读入值
		cout << "c[" << i << "] : ";
		cin >> c[i];
	}
	reverse(c, n);					// 将数组c的元素逆序排列

	cout << "将元素逆序排列。\n";
	for (int i = 0; i < n; i++)		// 显示数组c
		cout << "c[" << i << "] = " << c[i] << '\n';
}
