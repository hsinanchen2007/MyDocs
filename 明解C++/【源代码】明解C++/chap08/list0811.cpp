// 字符数组和字符串指针

#include <iostream>

using namespace std;

int main()
{
	char a[][5] = {"LISP", "C", "Ada"};		// 字符数组的数组
	char* p[]   = {"PAUL", "X", "MAC"};		// 字符串指针的数组

	for (int i = 0; i < 3; i++)
		cout << "a[" << i << "] = \"" << a[i] << "\"\n";

	for (int i = 0; i < 3; i++)
		cout << "p[" << i << "] = \"" << p[i] << "\"\n";
}
