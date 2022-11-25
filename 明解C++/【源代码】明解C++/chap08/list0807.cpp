// 把接收的字符串中的小写字母转换为大写字母并显示

#include <cctype>
#include <iostream>

using namespace std;

//--- 显示字符串s（把小写字母转换为大写字母）---//
void put_upper(const char s[])
{
	for (int i = 0; s[i]; i++)
		cout << static_cast<char>(toupper(s[i]));
}

int main()
{
	char str[36];

	cout << "字符串：";
	cin >> str;

	put_upper(str);
	cout << '\n';
}
