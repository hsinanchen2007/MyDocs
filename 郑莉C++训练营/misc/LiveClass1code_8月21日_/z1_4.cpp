//z1_4.cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "输入要分解的整数：";
	cin >> n;
	if (n < 1) {
		cout << "输入不是正整数，程序退出" << endl;
		return 0;
	}
	int element = 2;
	while (n > 1 && element <= n) {
		if (n % element == 0) {
			if (n == element)
				cout << element;
			else
				cout << element << " * ";
			n /= element; // n=n/ element;
		}
		else
			element++;
	}
	cout << endl;
	return 0;
}
