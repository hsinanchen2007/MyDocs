// 2行3列的数组的加法

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int b[2][3] = { {6, 3, 4}, {5, 1, 2} };
	int c[2][3];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];

	cout << "数组a\n";					// 显示数组a的构成元素的值
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << a[i][j];
		cout << '\n';
	}

	cout << "数组b\n";					// 显示数组b的构成元素的值
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << b[i][j];
		cout << '\n';
	}

	cout << "数组c\n";					// 显示数组c的构成元素的值
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << c[i][j];
		cout << '\n';
	}
}
