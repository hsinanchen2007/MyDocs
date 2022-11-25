// 读入整数值并显示小于等于该值的奇数

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "整数值：";
	cin >> n;

	for (int i = 1; i <= n; i += 2)
		cout << i << '\n';
}
