// 复数类Complex的使用例程

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	double re, im;

	cout << "a的实部：";  cin >> re;
	cout << "a的虚部：";  cin >> im;
	Complex a(re, im);

	cout << "b的实部：";  cin >> re;
	cout << "b的虚部：";  cin >> im;
	Complex b(re, im);

	Complex c = -a + b;

	b += 2.0;						// b加上(2.0,0.0)
	c -= Complex(1.0, 1.0);			// c减去(1.0,1.0)
	Complex d(b.imag(), c.real());	// 赋予d（b的实部, c的虚部）

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	cout << "c = " << c << '\n';
	cout << "d = " << d << '\n';
}
