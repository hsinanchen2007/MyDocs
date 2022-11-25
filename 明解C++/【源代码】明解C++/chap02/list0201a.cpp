// 读入的整数值是正值吗？（使用空语句）

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "整数值：";
	cin >> n;

	if (n > 0)
		cout << "这个值为正。\n";
	else
		;							// 空语句：当n不为正时什么也不做
}
