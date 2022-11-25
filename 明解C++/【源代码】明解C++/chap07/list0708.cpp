// 恐怕会让大家惊讶的程序

#include <iostream>

using namespace std;

int main()
{
	int a[4];

	0[a] = a[1] = *(a + 2) = *(3 + a) = 7;				// 把7赋给所有元素

	for (int i = 0; i < 4; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';	// 显示a[i]的值
}
