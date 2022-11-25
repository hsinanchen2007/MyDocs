// 显示数组元素的值和地址

#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int* p = a;		// p指向a[0]

	for (int i = 0; i < 5; i++)			// 显示元素的值
		cout << "a[" << i << "] = " << a[i] << "  *(a+" << i << ") = " << *(a + i) << "  "
		     << "p[" << i << "] = " << p[i] << "  *(p+" << i << ") = " << *(p + i) << "\n";

	for (int i = 0; i < 5; i++)			// 显示指向元素的指针
		cout << "&a[" << i << "] = " << &a[i] << "  a+" << i << " = " << a + i << "  "
		     << "&p[" << i << "] = " << &p[i] << "  p+" << i << " = " << p + i << "\n";
}
