// 验证引用对象的引用源

#include <iostream>

using namespace std;

int main()
{
	double     d = 1.0;		// d为double型（值为1.0）
	const int& p = 5;		// p引用常量？
	const int& q = d;		// q引用double型？

	const_cast<int&>(q) = 3.14;		// 把3.14赋给int还是double？

	cout << "d = " << d << '\n';
	cout << "p = " << p << '\n';
	cout << "q = " << q << '\n';
}
