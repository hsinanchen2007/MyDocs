// 显示右下侧为直角的等腰直角三角形（函数版）

#include <iostream>

using namespace std;

//--- 连续显示n个字符c ---//
void put_nchar(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

//--- 连续显示n个'*' ---//
void put_stars(int n)
{
	put_nchar('*', n);		// 将处理委托给put_nchar
}

int main()
{
	int n;

	cout << "显示右下侧为直角的等腰直角三角形。\n";
	cout << "行数：";
	cin >> n;

	for (int i = 1; i <= n; i++) {	// 共n行
		put_nchar(' ', n - i);		// 显示n-i个' '
		put_stars(i);				// 显示i个'*'
		cout << '\n';				// 换行
	}
}
