// 线性查找（第2版）

#include <iostream>

using namespace std;

//--- 从数组a的前n个元素中线性查找值key（第2版）---//
int seq_search(int* a, int n, int key)
{
	int* p = a;

	while (n-- > 0) {
		if (*p == key)			// 查找成功
			return p - a;
		else
			p++;
	}
	return -1;					// 查找失败
}

int main()
{
	int key, idx;
	int x[7];
	int x_size = sizeof(x) / sizeof(x[0]);		// 数组x的元素个数

	for (int i = 0; i < x_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x[i];
	}
	cout << "查找值：";
	cin >> key;

	if ((idx = seq_search(x, x_size, key)) != -1)
		cout << "具有该值的元素为x[" << idx << "]。\n";
	else
		cout << "没有找到。\n";
}
