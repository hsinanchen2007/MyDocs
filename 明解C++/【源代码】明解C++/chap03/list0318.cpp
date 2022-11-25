// 读入整数并执行加法运算（在运算结果不超过1000的范围内执行）

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
		if (sum + t > 1000) {
			cout << "\a运算结果超过了1000。\n无视最后一个整数。\n";
			break;
		}
		sum += t;
	}
	cout << "运算结果是" << sum << "。\n";
}
