// \'和\"的示例程序

#include <iostream>

using namespace std;

int main()
{
	cout << "关于字符串字面量和字符字面量。\n";

	cout << "用双引号";
	cout << '"';											// 也可以表示为\"
	cout << "包围的\"ABC\"是字符串字面量。\n";							// 不可以表示为" 

	cout << "用单引号";
	cout << '\'';											// 不可以表示为'
	cout << "包围的'A'是字符字面量\n";								// 也可以表示为\'
}
