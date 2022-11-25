// 显示字符和字符编码
// 错误

#include <cctype>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cout << "该处理系统的字符和字符编码\n";

	for (char i = 0; i <= CHAR_MAX; i++) {
		switch (i) {
		 case '\a' : cout << "\\a";  break;
		 case '\b' : cout << "\\b";  break;
		 case '\f' : cout << "\\f";  break;
		 case '\n' : cout << "\\n";  break;
		 case '\r' : cout << "\\r";  break;
		 case '\t' : cout << "\\t";  break;
		 case '\v' : cout << "\\v";  break;
		 default   : cout << ' ' << (isprint(i) ? i : ' ');
		}

		// 用十六进制数显示转换为整型的数值
		cout << ' ' << hex << int(i) << '\n';
	}
}
