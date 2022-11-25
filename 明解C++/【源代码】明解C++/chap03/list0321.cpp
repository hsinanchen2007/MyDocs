// 列举面积为n且长和宽为整数的长方形的边长

#include <iostream>

using namespace std;

int main()
{
	int n;			// 面积
	cout << "面积";
	cin >> n;

	for (int i = 1; i < n; i++) {
		if (i * i > n) break;
		if (n % i != 0) continue;
		cout << i << "*" << n / i << '\n';
	}
}
