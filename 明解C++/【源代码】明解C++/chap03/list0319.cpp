// 读入整数并执行加法运算（不计算负数）

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
		cout << "整数：";
		cin >> t;
		if (t < 0) {
			cout << "\a不计算负数。\n";
			continue;
		}
		sum += t;
	}
	cout << "运算结果是" << sum << "。\n";
}
