// 在数组中存放字符串并显示（初始化）

#include <iostream>

using namespace std;

int main()
{
	char s1[] = {'A', 'B', 'C', '\0'};
	char s2[] = {"ABC"};
	char s3[] = "ABC";

	cout << "字符串\"" << s1 << "\"存放在数组s1中。\n";
	cout << "字符串\"" << s2 << "\"存放在数组s2中。\n";
	cout << "字符串\"" << s3 << "\"存放在数组s3中。\n";
}
