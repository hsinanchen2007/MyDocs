// 分开调用求两个值中的较大值的函数模板和函数

#include <iostream>

using namespace std;

//--- 普通函数（注意：为了验证的行为，返回较小值）---//
int maxof(int a, int b) { return a < b ? a : b; }

//--- 函数模板 ---//
template <class Type> Type maxof(Type a, Type b) { return a > b ? a : b; }

int main()
{
	int a, b;

	cout << "整数a：";	  cin >> a;
	cout << "整数b：";	  cin >> b;

	cout << "较大值为" << maxof(a, b)      << "。\n";
	cout << "较大值为" << maxof<int>(a, b) << "。\n";
	cout << "较大值为" << maxof<>(a, b)    << "。\n";
}
