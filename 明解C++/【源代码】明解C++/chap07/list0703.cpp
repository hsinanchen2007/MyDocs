// 取址运算符和解引用运算符

#include <iostream>

using namespace std;

int main()
{
	int x = 123, y = 567, sw;

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';

	cout << "修改值的变量：";
	cin >> sw;

	int* ptr;
	if (sw == 0)
		ptr = &x;	// ptr指向x
	else
		ptr = &y;	// ptr指向y

	*ptr = 999;		// 对ptr所指的对象赋值

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
}
