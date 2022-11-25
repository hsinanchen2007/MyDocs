// 布尔值类Boolean的使用例程

#include <iostream>
#include "Boolean.h"

using namespace std;

//--- 两个整数x和y是否相等 ---//
Boolean int_eq(int x, int y)
{
	return x == y;
}

int main()
{
	int n;
	Boolean a;			// a <- False：默认构造函数
	Boolean b = a;		// b <- False：复制构造函数
	Boolean c = 100;	// c <- True：转换构造函数
	Boolean x[8];		// x[0]~x[7]：默认构造函数

	cout << "整数值：";
	cin >> n;
	x[0] = int_eq(n, 5);		// x[0]
	x[1] = (n != 3);			// x[1] <- Boolean(n != 3)
	x[2] = Boolean::False;		// x[2] <- False
	x[3] = 1000;				// x[3] <- True：Boolean(1000)
	x[4] = c == Boolean::True;	// x[4] <- Boolean(c == True)

	cout << "a的值：" << int(a) << '\n';
	cout << "b的值：" << static_cast<const char*>(b) << '\n';

	for (int i = 0; i < 8; i++)
		cout << "x[" << i << "] = " << x[i] << '\n';
}
