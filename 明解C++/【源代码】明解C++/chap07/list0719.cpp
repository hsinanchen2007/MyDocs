// 循环动态创建数组对象（异常处理）

#include <new>
#include <iostream>

using namespace std;

int main()
{
	cout << "循环创建元素个数为30000的double型数组。\n";

	while (true) {
		try {
			double* a = new double[30000];	// 创建
		}
		catch (bad_alloc) {
			cout << "数组创建失败，程序中断。\n";
			return 1;
		}
	}
}
