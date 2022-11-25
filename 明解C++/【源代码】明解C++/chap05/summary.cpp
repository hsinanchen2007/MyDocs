#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	const int A_SIZE = 5;		// 数组a的元素个数

	// 数组a和b为一维数组（元素类型为int且元素个数为5）
	int a[A_SIZE];
	int b[] = {1, 2, 3, 4, 5};

	// 数组b的元素个数
	int b_size = sizeof(b) / sizeof(b[0]);

	// 将数组b的所有元素复制到a
	for (int i = 0; i < A_SIZE; i++)
		a[i] = b[i];

	// 显示数组a的所有元素的值
	for (int i = 0; i < A_SIZE; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	// 显示数组b的所有元素的值
	for (int i = 0; i < b_size; i++)
		cout << "b[" << i << "] = " << b[i] << '\n';

	// 计算并显示数组a的所有元素的和sum
	int sum = 0;
	for (int i = 0; i < A_SIZE; i++)
		sum += a[i];
	cout << "数组a的所有元素的和=" << sum << '\n'; 

	// 数组c为二维数组（元素类型为int[3]型且元素个数为2）
	int c[2][3] = { {1, 2, 3},
					{4, 5, 6},
				  };

	int c_height = sizeof(c) / sizeof(c[0]);		// 行数
	int c_width  = sizeof(c[0]) / sizeof(c[0][0]);	// 列数

	cout << "数组c为" << c_height << "行" << c_width << "列的"
		 << "二维数组。\n";

	// 显示数组c的所构成有元素的值
	for (int i = 0; i < c_height; i++) {
		for (int j = 0; j < c_width; j++) {
			cout << "c[" << i << "][" << j << "] = " << c[i][j] << '\n';
		}
	}

	// 显示数组、元素和构成元素的类型
	cout << "数组a的类型：" << typeid(a).name()    << '\n';
	cout << "a的元素类型：" << typeid(a[0]).name() << '\n';
	cout << "数组b的类型：" << typeid(b).name()    << '\n';
	cout << "b的元素类型：" << typeid(b[0]).name() << '\n';
	cout << "数组c的类型：" << typeid(c).name()    << '\n';
	cout << "c的元素类型：" << typeid(c[0]).name() << '\n';
	cout << "c的构成元素类型：" << typeid(c[0][0]).name() << '\n';
}
