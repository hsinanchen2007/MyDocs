// 银行账户类（第4版）的使用例程

#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

//--- 显示p所指的Account的账户信息（账户名称、账号、账户余额） ---//
void print_Account(string title, Account* p)
{
	cout << title
		 << p->name() << "\" (" << p->no() << ") " << p->balance() << "元\n";
}

int main()
{
	Account liyang("李阳", "12345678", 1000);		    // 李阳的账户
	Account zhouyan("周燕", "87654321",  200);		// 周燕的账户

	liyang.withdraw(200);			// 李阳取出200元
	zhouyan.deposit(100);			// 周燕存入100元

	print_Account("李阳的账户", &liyang);

	print_Account("周燕的账户", &zhouyan);
}
