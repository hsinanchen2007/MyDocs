// 动态创建整数对象

#include <iostream>

using namespace std;

int main()
{
	int* x = new int;			// 创建（分配存储空间）

	cout << "整数：";
	cin >> *x;

	cout << "*x = " << *x << '\n';

	delete x;					// 销毁（释放存储空间）
}
