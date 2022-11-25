// 显式特例化求两个值中的较大值的函数模板

#include <cstring>
#include <iostream>

using namespace std;

//--- 求a和b中的较大值 ---//
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

//--- 求a和b中的较大值（const char*型的特例化）---//
template <> const char* maxof<const char*>(const char* a, const char* b)
{
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	int a, b;
	char s[64], t[64];

	cout << "整数a：";	  cin >> a;
	cout << "整数b：";	  cin >> b;
	cout << "字符串s：";  cin >> s;
	cout << "字符串t：";  cin >> t;

	cout << "a和b中的较大值为" <<       maxof(a, b)                  << "。\n";
	cout << "s和t中的较大值为" <<       maxof<const char*>(s, t)     << "。\n";
	cout << "s和\"ABC\"中的较大值为" << maxof<const char*>(s, "ABC") << "。\n";
}
