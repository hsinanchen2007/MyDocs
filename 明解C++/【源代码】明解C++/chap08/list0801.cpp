// 显示字符串字面量的类型和大小

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	cout << "字符串字面量\"ABC\"\n";
	cout << "  类型："     << typeid("ABC").name()
		 << "  大小：" << sizeof("ABC") << "\n\n";

	cout << "字符串字面量\"\"\n";
	cout << "  类型："     << typeid("").name()
		 << "  大小：" << sizeof("") << "\n\n";

	cout << "字符串字面量\"ABC\\0DEF\"\n";
	cout << "  类型："     << typeid("ABC\0DEF").name()
		 << "  大小：" << sizeof("ABC\0DEF") << "\n";
}
