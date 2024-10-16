// 求数组的最大值（函数模板版）

#include <iostream>

using namespace std;

//--- 返回元素个数为n的Type型数组x的最大值的函数模板 ---//
template <class Type>
Type maxof(const Type x[], int n)
{
	Type max = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] > max)
			max = x[i];
	return max;
}

int main()
{
	const int isize = 8;	// 数组ix的元素个数
	int ix[isize];			// int型数组

	// 整数数组的最大值
	cout << "请输入" << isize << "个整数。\n";
	for (int i = 0; i < isize; i++) {
		cout << i + 1 << "：";
		cin >> ix[i];
	}
	cout << "最大值为" << maxof(ix, isize) << "。\n\n";

	const int dsize = 5;	// 数组dx的元素个数
	double dx[dsize];		// double型数组

	// 实数数组的最大值
	cout << "请输入" << dsize << "个实数。\n";
	for (int i = 0; i < dsize; i++) {
		cout << i + 1 << "：";
		cin >> dx[i];
	}
	cout << "最大值为" << maxof(dx, dsize) << "。\n";
}
