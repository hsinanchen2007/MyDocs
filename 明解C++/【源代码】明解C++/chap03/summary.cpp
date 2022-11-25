#include <iostream>

using namespace std;

int main()
{
	int x;
	do {
		cout << "正整数值：";
		cin >> x;
	} while (x <= 0);

	int y = x;
	int z = x;
	while (y >= 0)
		cout << y-- << " " << ++z << '\n';

	cout << "长和宽为整数且面积为\"" << x
		 << "\"的长方形的边长：\n";
	for (int i = 1; i < x; i++) {
		if (i * i > x) break;		// break语句
		if (x % i != 0) continue;	// continue语句
		cout << i << " * " << x / i << '\n';
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 7; j++)
			cout << '\'';
		cout << '\n';
	}
}
