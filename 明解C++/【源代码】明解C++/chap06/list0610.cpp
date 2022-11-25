// 显示正方形和长方形

#include <iostream>

using namespace std;

//--- 连续显示n个字符c ---//
void put_nchar(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

//--- 排列字符c，并显示边长为n的正方形 ---//
void put_square(int n, char c)
{
	for (int i = 1; i <= n; i++) {		// 共n行
		put_nchar(c, n);				// 显示n个字符c
		cout << '\n';					// 换行
	}
}

//--- 排列字符c，并显示高为h且宽为w的长方形 ---//
void put_rectangle(int h, int w, char c)
{
	for (int i = 1; i <= h; i++) {		// 共h行
		put_nchar(c, w);				// 显示w个字符c
		cout << '\n';					// 换行
	}
}

int main()
{
	int n, h, w;

	cout << "显示正方形。\n";
	cout << "边长：";   cin >> n;

	put_square(n, '*');			// 用'*'显示边长为n的正方形

	cout << "显示长方形。\n";
	cout << "高：";   cin >> h;
	cout << "宽：";   cin >> w;

	put_rectangle(h, w, '+');	// 用'+'显示高为h且宽为w的长方形
}
