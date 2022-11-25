// 读入数值，并交叉显示相应个数的+和-
// 判断n次奇偶

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "显示多少个字符：";
	cin >> n;

	if (n > 0) {
		int i = 1;
		while (i <= n) {
			if (i % 2)		// 奇数
				cout << '+';
			else			// 偶数
				cout << '-';
			i++;
		}
		cout << '\n';
	}
}
