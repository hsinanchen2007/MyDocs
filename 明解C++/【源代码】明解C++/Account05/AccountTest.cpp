// 银行账户类（第5版）的使用例程

#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
	Account liyang("李阳", "12345678", 1000, 2125, 1, 24);  // 李阳的账户
	Account zhouyan("周燕", "87654321",  200, 2123, 7, 15);   // 周燕的账户

	liyang.withdraw(200);	// 李阳取出200元
	zhouyan.deposit(100);	// 周燕存入100元

	cout << "李阳的账户\n";
	cout << "账户名称=" << liyang.name() << '\n';
	cout << "账号=" << liyang.no() << '\n';
	cout << "账户余额=" << liyang.balance() << "元\n";
	cout << "开设日期=" << liyang.opening_date() << '\n';

	cout << "\n周燕的账户\n";
	cout << "账户名称=" << zhouyan.name() << '\n';
	cout << "账号=" << zhouyan.no() << '\n';
	cout << "账户余额=" << zhouyan.balance() << "元\n";
	cout << "开设日期=" << zhouyan.opening_date().year()  << "年"
						 << zhouyan.opening_date().month() << "月"
						 << zhouyan.opening_date().day()   << "日\n";
}
