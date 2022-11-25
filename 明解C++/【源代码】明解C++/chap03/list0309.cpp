// 读入正整数值并逆向显示

#include <iostream>

using namespace std;

int main()
{
	int x;

	cout << "逆向显示正整数值。\n";
	do {
		cout << "正整数值：";
		cin >> x;
	} while (x <= 0);

	cout << "逆向显示结果为";
	while (x > 0) {
		cout << x % 10;			// 显示x的最后一位数
		x /= 10;				// x除以10
	}
	cout << "。\n";
}
