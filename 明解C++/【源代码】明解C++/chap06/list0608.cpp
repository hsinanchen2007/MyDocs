// 显示左下侧为直角的等腰直角三角形（函数版）

#include <iostream>

using namespace std;

//--- 连续显示n个'*' ---//
void put_stars(int n)
{
	while (n-- > 0)
		cout << '*';
}

int main()
{
	int n;

	cout << "显示左下侧为直角的等腰直角三角形。\n";
	cout << "行数：";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		put_stars(i);
		cout << '\n';
	}
}
