#include <iostream>

using namespace std;

//--- 用""包围字符串s并显示 ---//
void put_str(const char* s)
{
	cout << '\"';
	while (*s)
		cout << *s++;
	cout << '\"';
}

int main()
{
	char a[] = "CIA";	// 字符数组
	char* p  = "FBI";	// 字符串指针
	char a2[][5] = {"LISP", "C", "Ada"};	// 字符数组的数组
	char* p2[]   = {"PAUL", "X", "MAC"};	// 字符串指针的数组

	cout << "a = ";  put_str(a);  cout << '\n';
	cout << "p = ";  put_str(p);  cout << '\n';

	for (int i = 0; i < sizeof(a2) / sizeof(a2[0]); i++) {
		cout << "a2[" << i << "] = ";   put_str(a2[i]);   cout << '\n';
	}

	for (int i = 0; i < sizeof(p2) / sizeof(p2[0]); i++) {
		cout << "p2[" << i << "] = ";   put_str(p2[i]);   cout << '\n';
	}
}
