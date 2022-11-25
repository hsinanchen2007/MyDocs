// 读入整数值并显示该值的所有约数

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "整数值：";
	cin >> n;

	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			cout << i << '\n';
}
