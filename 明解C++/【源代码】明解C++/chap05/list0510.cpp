// 向3行2列的二维数组的所有构成元素读入值并显示

#include <iostream>

using namespace std;

int main()
{
	int m[3][2];	// 3行2列的二维数组

	cout << "对各构成元素赋值。\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "m[" << i << "][" << j << "]：";
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "m[" << i << "][" << j << "]：" << m[i][j] << '\n';
		}
	}
}
