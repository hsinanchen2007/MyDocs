// 指针到整数的类型转换

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "n的地址：" << hex << reinterpret_cast<unsigned long>(&n) << '\n';
}
