// 将数组各元素赋值为1、2、3、4、5并显示（for语句）

#include <iostream>

using namespace std;

int main()
{
	int a[5];		// int[5]型的数组（元素类型为int型且元素个数为5的数组）

	for (int i = 0; i < 5; i++)
		a[i] = i + 1;

	for (int i = 0; i < 5; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
