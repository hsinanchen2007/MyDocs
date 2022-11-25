// 把0赋给数组的所有元素（第2版）

#include <iostream>

using namespace std;

//--- 把0赋给数组p的前n个元素（第2版）---//
void fill_zero(int *p, int n)
{
	while (n-- > 0)
		*p++ = 0;
}

int main()
{
	int x[5] = {1, 2, 3, 4, 5};
	int x_size = sizeof(x) / sizeof(x[0]);		// 数组x的元素个数

	fill_zero(x, x_size);						// 把0赋给数组x的所有元素

	cout << "把0赋给了所有元素。\n";
	for (int i = 0; i < x_size; i++)
		cout << "x[" << i << "] = " << x[i] << '\n';	// 显示x[i]的值
}
