// 将数组的各元素初始化为1、2、3、4、5并显示

#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};	// 元素类型为int型且元素个数为5的数组

	for (int i = 0; i < 5; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
