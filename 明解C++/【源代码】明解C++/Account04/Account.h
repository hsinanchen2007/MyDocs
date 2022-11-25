// 银行账户类（第4版：头文件）

#include <string>

class Account {
	std::string full_name;	// 账户名称
	std::string number;		// 账号
	long crnt_balance;		// 账户余额

public:
	Account(std::string name, std::string num, long amnt);	// 构造函数

	std::string name()  { return full_name; }		// 返回账户名称
	std::string no()    { return number; }			// 返回账号
	long balance()      { return crnt_balance; }	// 返回账户余额

	void deposit(long amnt);						// 存入
	void withdraw(long amnt);						// 取出
};
