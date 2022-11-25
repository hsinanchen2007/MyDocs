// 异常的抛出和捕获

#include <new>
#include <iostream>

using namespace std;

//=== 溢出类 ===//
class OverFlow { };

//--- 返回x的2倍 ---//
int f(int x)
{
	if (x < 0)
		throw "奇怪。值为负。\n";
	else if (x > 30000)
		throw OverFlow();
	else
		return 2 * x;
}

int main()
{
	int a;
	cout << "整数：";
	cin >> a;

	try {
		int b = f(a);
		cout << "该数的2倍为" << b << "。\n";
	}
	catch (const char* str) {		// 捕获字符串的异常
		cout << "发生异常：" << str;
	}
	catch (OverFlow) {				// 这里捕获OverFlow型的异常
		cout << "程序溢出，结束程序。\n";
		return 1;
	}
}
