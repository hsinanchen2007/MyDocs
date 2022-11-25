// 显示将无符号整数值左移和右移后的值
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
	unsigned x, n;

	cout << "非负整数：";			cin >> x;
	cout << "要移动的位数：";	        cin >> n;

	cout << "整数   = ";  print_bits(x);		 cout << '\n';
	cout << "左移   = ";  print_bits(x << n);	 cout << '\n';
	cout << "右移   = ";  print_bits(x >> n);	 cout << '\n';
}
