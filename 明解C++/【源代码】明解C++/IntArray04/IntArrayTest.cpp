// 整数数组类IntArray（第4版）的使用例程

#include <new>
#include <iostream>
#include "IntArray.h"

using namespace std;

//--- 对元素个数为size的数组的前num个数据赋值并显示 --//
void f(int size, int num)
{
	try {
		IntArray x(size);
		for (int i = 0; i < num; i++) {
			x[i] = i;
			cout << "x[" << i << "] = " << x[i] << '\n';
		}
	}

	catch (IntArray::IdxRngErr& x) {
		cout << "下标溢出：" << x.index() << '\n';
		return;
	}

	catch (bad_alloc) {
		cout << "内存分配失败。\n";
		exit(1);				// 强制结束
	}
}

int main()
{
	int size, num;

	cout << "元素个数：";
	cin >> size;

	cout << "数据个数：";
	cin >> num;

	f(size, num);

	cout << "main函数结束。\n";
}
