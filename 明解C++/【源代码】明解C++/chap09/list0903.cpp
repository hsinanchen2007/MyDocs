// 显式实例化求两个值中的较大值的函数模板

#include <iostream>

using namespace std;

//--- 求a和b中的较大值 ---//
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b;
	double x;

	cout << "整数a：";	  cin >> a;
	cout << "整数b：";	  cin >> b;
	cout << "实数x：";	  cin >> x;

	cout << "a和b中的较大值为" << maxof(a, b)         << "。\n";
	cout << "a和x中的较大值为" << maxof<double>(a, x) << "。\n";
}
