// 确认构造函数初始化器的调用顺序

#include <iostream>

using namespace std;

class Int {
	int v;	// 值
public:
	Int(int val) : v(val) { cout << v << '\n'; }
};

class Abc {
	Int a;
	Int b;
	Int c;

public:
	Abc(int aa, int bb, int cc) : c(cc), b(bb), a(aa) { }	// 构造函数
};

int main()
{
	Abc x(1, 2, 3);
}
