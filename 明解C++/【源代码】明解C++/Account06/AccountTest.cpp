// 银行账户类（第6版）的使用例程

#include <iostream>
#include "Date.h"
#include "Account.h"

using namespace std;

int main()
{
	// 李阳的账户
	Account liyang("李阳", "12345678", 1000, Date(2125, 1, 24));
	string dw[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

	cout << "李阳的账户\n";
	cout << "账户名称=" << liyang.name() << '\n';
	cout << "账号=" << liyang.no() << '\n';
	cout << "账户余额=" << liyang.balance() << "元\n";
	cout << "开设日期=" << liyang.opening_date();
	cout << "（" << dw[liyang.opening_date().day_of_week()] << "）\n";
}
