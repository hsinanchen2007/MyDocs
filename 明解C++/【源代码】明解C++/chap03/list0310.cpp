// 计算从1加到n的结果

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "计算从1加到n的结果。\n";
	do {
		cout << "n的值：";
		cin >> n;
	} while (n <= 0);

	int sum = 0;		// 求和
	int i = 1;

	while (i <= n) {
		sum += i;		// 对sum加i
		i++;			// 递增i
	}
	cout << "从1加到" << n << "的结果是" << sum << "。\n";
}
