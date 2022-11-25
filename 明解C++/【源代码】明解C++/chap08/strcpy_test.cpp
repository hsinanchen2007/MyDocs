// strcpy函数和strncpy函数的使用例程

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char tmp[16];
	char s1[16], s2[16], s3[16];

	cout << "请输入字符串：";
	cin >> tmp;

	strcpy(s1, strcpy(s2, tmp));	// 把字符串复制到s1和s2

	cout << "字符串s1为\"" << s1 << "\"。\n";
	cout << "字符串s2为\"" << s2 << "\"。\n";
	cout << "字符串s3为\"" << strcpy(s3, tmp) << "\"。\n";

	char* x = "XXXXXXXXX";			// 9个'X'和1个空字符

	strcpy(s3, x); strncpy(s3, "12345", 3);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "12345", 5);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "12345", 7);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "1234567890", 9); cout << "s3 = " << s3 << '\n';
}
