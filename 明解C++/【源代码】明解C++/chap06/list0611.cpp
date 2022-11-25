// 心算训练

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//--- 确认是否继续 ---//
bool confirm_retry()
{
	int retry;
	do {
		cout << "再来一次？<Yes...1/No...0>:";
		cin >> retry;
	} while (retry != 0 && retry != 1);
	return static_cast<bool>(retry);		// 返回转换为bool型后的值
}

int main()
{
	srand(time(NULL));
	cout << "心算训练开始!!\n";

	do {
		int x = rand() % 900 + 100;		// 三位数
		int y = rand() % 900 + 100;		// 三位数
		int z = rand() % 900 + 100;		// 三位数

		while (true) {
			int k;						// 读入的值
			cout << x << " + " << y << " + " << z << " = ";
			cin >> k;
			if (k == x + y + z)			// 正确答案
				break;
			cout << "\a不对!!\n";
		}
	} while (confirm_retry());
}
