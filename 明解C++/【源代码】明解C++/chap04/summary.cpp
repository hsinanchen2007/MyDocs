#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	cout << "15   / 2   = " << 15   / 2   << '\n';
	cout << "15.0 / 2.0 = " << 15.0 / 2.0 << '\n';
	cout << "15.0 / 2   = " << 15.0 / 2   << '\n';
	cout << "15   / 2.0 = " << 15   / 2.0 << '\n';

	int x, y;
	cout << "x的值：";	cin >> x;
	cout << "y的值：";	cin >> y;

	bool eq = (x == y);
	cout << "它们"
		 << (eq ? "相等。\n" : "不相等。\n");

	cout << "平均值为"
		 << static_cast<double>(x + y) / 2 << "。\n";

	cout << fixed << setprecision(6);
	for (int i = 0; i <= 1000; i++)
		cout << static_cast<float>(i) / 1000 << '\n'; 
}
