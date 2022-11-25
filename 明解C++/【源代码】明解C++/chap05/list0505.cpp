// 将数组的各元素初始化为1、2、3、4、5并显示（通过计算求元素个数）

#include <iostream>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int a_size = sizeof(a) / sizeof(a[0]);	// 数组a的元素个数

	for (int i = 0; i < a_size; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
