// 银行账户类（第6版：源文件）

#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

//--- 构造函数 ---//
Account::Account(string name, string num, long amnt, const Date& op) :
				 full_name(name), number(num), crnt_balance(amnt), open(op)
{
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