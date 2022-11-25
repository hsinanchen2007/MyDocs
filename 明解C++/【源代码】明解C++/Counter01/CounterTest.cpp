// 计数器类Counter（第1版）的使用例程

#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
	int no;
	Counter x;

	cout << "当前的计数器：" << x.value() << '\n';

	cout << "向上计数次数：";
	cin >> no;

	for (int i = 0; i < no; i++) {
		x.increment();					// 向上计数
		cout << x.value() << '\n';
	}

	cout << "向下计数次数：";
	cin >> no;

	for (int i = 0; i < no; i++) {
		x.decrement();					// 向下计数
		cout << x.value() << '\n';
	}
}
