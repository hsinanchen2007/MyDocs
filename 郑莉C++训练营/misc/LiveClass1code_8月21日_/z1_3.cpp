//z1_3.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	cout << "请输入一大于1的正整数：";
	cin >> a;
	if (a < 2) {
		cout << "输入的数字不是大于1的正整数" << endl;
		return 0;
	}
	if (a == 2) {
		cout << a << "是质数" << endl;
		return 0;
	}
	double s = sqrt(1.0 *a);
	for (int div = 2; div <= s; div++)
		if (a % div == 0)
		{
			cout << a << "不是质数" << endl;
			return 0;
		}
	cout << a << "是质数" << endl;
	return 0;
}
