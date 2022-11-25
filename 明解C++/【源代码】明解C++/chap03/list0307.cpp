// 读入数值并交替显示相应个数的+和-

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "显示多少个：";
	cin >> n;

	if (n > 0) {
		int i = 0;
		while (i < n / 2)  {
			cout << "+-";
			i++;
		}
		if (n % 2) cout << '+';
		cout << '\n';
	}
}
