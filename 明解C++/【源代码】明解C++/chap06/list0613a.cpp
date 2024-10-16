// 对无符号整数进行按位与、按位或、按位异或和按位取反运算，并显示运算结果
// 使用numeric_limits<unsigned>::digits

#include <limits>
#include <iostream>

using namespace std;

//--- 显示unsigned型的所有位 ---//
void print_bits(unsigned x)
{
	for (int i = numeric_limits<unsigned>::digits - 1; i >= 0; i--)
		cout << ((x >> i) & 1U ? '1' : '0');
}

int main()
{
	unsigned a, b;

	cout << "请输入两个非负整数。\n";
	cout << "a : ";	  cin >> a;
	cout << "b : ";	  cin >> b;

	cout << "a     = ";  print_bits(a);		cout << '\n';
	cout << "b     = ";  print_bits(b);		cout << '\n';
	cout << "a & b = ";  print_bits(a & b);	cout << '\n';	// 按位与
	cout << "a | b = ";  print_bits(a | b);	cout << '\n';	// 按位或
	cout << "a ^ b = ";  print_bits(a ^ b);	cout << '\n';	// 按位异或
	cout << "~a    = ";  print_bits(~a);	cout << '\n';	// 按位取反
	cout << "~b    = ";  print_bits(~b);	cout << '\n';	// 按位取反
}
