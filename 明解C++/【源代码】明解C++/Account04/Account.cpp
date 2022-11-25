// 银行账户类（第4版：源文件）

#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

//--- 构造函数 ---//
Account::Account(string name, string num, long amnt)
{
	full_name = name;		// 账户名称
	number = num;			// 账号
	crnt_balance = amnt;	// 账户余额
}

//--- 存入 ---//
void Account::deposit(long amnt)
{
	crnt_balance += amnt;
}

//--- 取出 ---//
void Account::withdraw(long amnt)
{
	crnt_balance -= amnt;
}
