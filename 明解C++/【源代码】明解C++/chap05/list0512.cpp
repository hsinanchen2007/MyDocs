// 显示二维数组的元素个数和构成元素个数

#include <iostream>

using namespace std;

int main()
{
	int a[4][3];

	cout << "数组a为"	 << sizeof(a)    / sizeof(a[0])    << "行"
						 << sizeof(a[0]) / sizeof(a[0][0]) << "列。\n";

	cout << "构成元素有" << sizeof(a)    / sizeof(a[0][0]) << "个。\n";
}
