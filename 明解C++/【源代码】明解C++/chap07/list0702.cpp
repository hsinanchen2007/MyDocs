// 指针的基础（取址运算符和解引用运算符）

#include <iostream>

using namespace std;

int main()
{
	int n = 135;
	cout << "n   ：" <<  n << '\n';
	cout << "&n  ：" << &n << "地址\n";

	int* ptr = &n;		// ptr指向n
	cout << "ptr ：" <<  ptr << "地址\n";
	cout << "*ptr：" << *ptr << '\n';
}
