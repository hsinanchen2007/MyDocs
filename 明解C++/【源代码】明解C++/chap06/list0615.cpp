// 显示各整型的位数

#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << "char 型的位数：" << numeric_limits<unsigned char>::digits  << '\n';
	cout << "short型的位数：" << numeric_limits<unsigned short>::digits << '\n';
	cout << "int  型的位数：" << numeric_limits<unsigned int>::digits   << '\n';
	cout << "long 型的位数：" << numeric_limits<unsigned long>::digits  << '\n';
}
