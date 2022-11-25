// 显示将无符号整数值左移和右移后的值

#include <iostream>

using namespace std;

//--- 计算整数x中“1”的位数 ---//
int count_bits(unsigned x)
{
	int bits = 0;
	while (x) {
		if (x & 1U) bits++;
		x >>= 1;
	}
	return bits;
}

//--- 计算int型或unsigned型的位数 ---//
int int_bits()
{
	return count_bits(~0U);
}

//--- 显示unsigned型的所有位 ---//
void print_bits(unsigned x)
{
	for (int i = int_bits() - 1; i >= 0; i--)
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
