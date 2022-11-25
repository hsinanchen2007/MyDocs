// 读入数值并显示相应个数的*（for语句）

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "显示多少个：";
	cin >> n;

	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';
}
