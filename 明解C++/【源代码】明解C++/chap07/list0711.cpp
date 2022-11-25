// 把同一值赋给n行3列的二维数组的所有构成元素

#include <iomanip>
#include <iostream>

using namespace std;

//---元素类型为“元素类型为int型且元素个数为3的数组”型且元素个数为n的数组 ---//
//---                  把v赋给n行3列的二维数组的所有构成元素 ---//
void fill(int (*a)[3], int n, int v)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = v;
}

int main()
{
	int no;
	int x[2][3] = {0};
	int y[4][3] = {0};

	cout << "赋给所有构成元素的值：";
	cin >> no;

	fill(x, 2, no);		// 把no赋给x的所有构成元素
	fill(y, 4, no);		// 把no赋给y的所有构成元素

	cout << "--- x ---\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << x[i][j];
		cout << '\n';
	}

	cout << "--- y ---\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << y[i][j];
		cout << '\n';
	}
}
