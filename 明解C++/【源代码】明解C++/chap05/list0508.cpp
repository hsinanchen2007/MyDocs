// 将数组元素逆序排列并显示

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	const int n = 7;		// 数组a的元素个数
	int a[n];

	srand(time(NULL));		// 初始化随机数种子
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		cout << "a[" << i << "] = " << a[i] << '\n';
	}

	for (int i = 0; i < n / 2; i++) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}

	cout << "将元素逆序排列。\n";
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
