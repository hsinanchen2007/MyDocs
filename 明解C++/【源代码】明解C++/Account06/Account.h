// 银行账户类（第6版：头文件）

#ifndef ___Class_Account
#define ___Class_Account

#include <string>
#include "Date.h"

//===== 银行账户类 =====//
class Account {
	std::string full_name;	// 账户名称
	std::string number;		// 账号
	long crnt_balance;		// 账户余额
	Date open;				// 开户日期

public:
	// 构造函数
	Account(std::string name, std::string num, long amnt, const Date& op);

	void deposit(long amnt);							// 存入
	void withdraw(long amnt);							// 取出

	std::string name() const  { return full_name; }		// 返回账户名称
	std::string no() const    { return number; }		// 返回账号
	long balance() const      { return crnt_balance; }	// 返回账户余额
	Date opening_date() const { return open; }			// 返回开户日期
};

#endif
