// 日期类Date（第2版）的使用例程（确认成员函数preceding_day的作用）

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date today;		// 今天

	cout << "今天是" << today << "。\n";
	cout << "昨天是" << today.preceding_day() << "。\n";
}
