// 显示左下侧为直角的等腰直角三角形

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "显示左下侧为直角的等腰直角三角形。\n";
	cout << "行数：";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)	// 显示i个'*'
			cout << '*';
		cout << '\n';
	}
}
