// strlen函数的使用例程（其一）

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char str[100];

	cout << "请输入字符串：";
	cin >> str;

	cout << "字符串\"" << str << "\"的长度为" << strlen(str) << "。\n";
}
