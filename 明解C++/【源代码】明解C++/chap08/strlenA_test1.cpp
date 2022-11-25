// strlen函数的使用例程

#include <cstring>
#include <iostream>

using namespace std;

//--- strlen的实现例程A ---//

#include <cstddef>

size_t strlen(const char* s)
{
	size_t len = 0;		// 长度

	while (*s++)
		len++;
	return len;
}

int main(void)
{
	char str[100];

	cout << "请输入字符串：";
	cin >> str;

	cout << "字符串\"" << str << "\"的长度为" << strlen(str) << "。\n";
}
