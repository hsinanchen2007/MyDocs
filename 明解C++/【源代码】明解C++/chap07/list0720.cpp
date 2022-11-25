// 循环动态创建数组对象（抑制异常发生）

#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
	cout << "循环创建元素个数为30000的double型数组。\n";

	while (true) {
		double* a = new(nothrow) double[30000];		// 创建（抑制异常发生）

		if (a == NULL) {
			cout << "数组创建失败，程序中断。\n";
			return 1;
		}
	}
}
