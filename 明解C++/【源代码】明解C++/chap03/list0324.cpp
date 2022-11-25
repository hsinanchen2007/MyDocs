// 使用控制符指定书写格式

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	cout << oct << 1234 << '\n';	// 八进制数
	cout << dec << 1234 << '\n';	// 十进制数
	cout << hex << 1234 << '\n';	// 十六进制数

	cout << showbase;
	cout << oct << 1234 << '\n';	// 八进制数
	cout << dec << 1234 << '\n';	// 十进制数
	cout << hex << 1234 << '\n';	// 十六进制数

	cout << setw(10) << internal << "abc\n";
	cout << setw(10) << left	 << "abc\n";
	cout << setw(10) << right	 << "abc\n";

	cout << setbase(10);
	cout << setw(10) << internal << -123 << '\n';
	cout << setw(10) << left	 << -123 << '\n';
	cout << setw(10) << right	 << -123 << '\n';

	cout << setfill('*');			// 将填充字符设为'*'
	cout << setw(10) << internal << -123 << '\n';
	cout << setw(10) << left	 << -123 << '\n';
	cout << setw(10) << right	 << -123 << '\n';
	cout << setfill(' ');			// 将填充字符还原为' '

	cout << fixed      << setw(10) << setprecision(2) << 123.5 << endl;
	cout << scientific << setw(10) << setprecision(2) << 123.5 << endl;
}
