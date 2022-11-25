// 银行账户类（第2版）及类的使用例程

#include <string>
#include <iostream>

using namespace std;

class Account {
private:
	string full_name;		// 账户名称
	string number;			// 账号
	long crnt_balance;		// 账户余额

public:
	//--- 构造函数 ---//
	Account(string name, string num, long amnt) {
		full_name = name;		// 账户名称
		number = num;			// 账号
		crnt_balance = amnt;	// 账户余额
	}

	//--- 返回账户名称 ---//
	string name() {
		return full_name;
	}

	//--- 返回账号 ---//
	string no() {
		return number;
	}

	//--- 返回账户余额 ---//
	long balance() {
		return crnt_balance;
	}

	//--- 存入 ---//
	void deposit(long amnt) {
		crnt_balance += amnt;
	}

	//--- 取出 ---//
	void withdraw(long amnt) {
		crnt_balance -= amnt;
	}
};

int main()
{
	Account liyang("李阳", "12345678", 1000);		    // 李阳的账户
	Account zhouyan("周燕", "87654321",  200);		// 周燕的账户

	liyang.withdraw(200);			// 李阳取出200元
	zhouyan.deposit(100);			// 周燕存入100元

	cout << "李阳的账户：\"" << liyang.name() << "\" (" << liyang.no()
		 << ") " << liyang.balance() << "元\n";

	cout << "周燕的账户：\"" << zhouyan.name() << "\" (" << zhouyan.no()
		 << ") " << zhouyan.balance() << "元\n";
}
