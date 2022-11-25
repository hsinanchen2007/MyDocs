// 读入整数并执行加法运算（输入0则结束）

#include <iostream>

using namespace std;

int main()
{
	int n;			// 要相加的整数的个数
	cout << "对整数执行加法运算。\n";
	cout << "要相加的整数的个数：";
	cin >> n;

	int sum = 0;	// 运算结果
	for (int i = 0; i < n; i++) {
		int t;
		cout << "整数（为0则结束）：";
		cin >> t;
		if (t == 0) break;		// 从for语句退出
		sum += t;
	}
	cout << "运算结果是" << sum << "。\n";
}
