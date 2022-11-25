// 银行账户类（第1版）及类的使用例程

#include <string>
#include <iostream>

using namespace std;

class Account {
public:
	string name;	// 账户名称
	string number;	// 账号
	long balance;	// 账户余额
};

int main()
{
	Account liyang;		    // 李阳的账户
	Account zhouyan;		// 周燕的账户

	liyang.name    = "李阳";	        // 李阳的账户名称
	liyang.number  = "12345678";	// 李阳的账号
	liyang.balance = 1000;			// 李阳的账户余额

	zhouyan.name    = "周燕";      	// 周燕的账户名称
	zhouyan.number  = "87654321";	// 周燕的账号
	zhouyan.balance = 200;			// 周燕的账户余额

	liyang.balance -= 200;			// 李阳取出200元
	zhouyan.balance += 100;			// 周燕存入100元

	cout << "李阳的账户：\"" << liyang.name << "\" (" << liyang.number
		 << ") " << liyang.balance << "元\n";

	cout << "周燕的账户：\"" << zhouyan.name << "\" (" << zhouyan.number
		 << ") " << zhouyan.balance << "元\n";
}
