// 银行账户类（第5版：头文件）

#include <string>
#include "Date.h"

class Account {
	std::string full_name;		// 账户名称
	std::string number;			// 账号
	long crnt_balance;			// 账户余额
	Date open;					// 开户日期

public:
	// 构造函数
	Account(std::string name, std::string num, long amnt, int y, int m, int d);

	void deposit(long amnt);							// 存入
	void withdraw(long amnt);							// 取出

	std::string name() const  { return full_name; }		// 返回账户名称
	std::string no() const    { return number; }		// 返回账号
	long balance() const      { return crnt_balance; }	// 返回账户余额
	Date opening_date() const { return open; }			// 返回开户日期
};
