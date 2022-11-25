// 在数组中存放字符串并显示（赋值）

#include <iostream>

using namespace std;

int main()
{
	char s[4];		// 存放字符串的数组

	s[0] = 'A';		// 赋值
	s[1] = 'B';		// 赋值
	s[2] = 'C';		// 赋值
	s[3] = '\0';	// 赋值

	cout << "赋给数组s的字符串为\"" << s << "\"。\n";		// 显示
}
