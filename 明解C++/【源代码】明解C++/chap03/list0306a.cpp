// 读入数值并显示相应个数的*
// i的初始值为1

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "显示多少个：";
	cin >> n;

	if (n > 0) {
		int i = 1;
		while (i <= n) {
			cout << '*';
			i++;
		}
		cout << '\n';
	}
}
