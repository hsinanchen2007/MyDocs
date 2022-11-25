// 李阳和周燕的银行账户

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string liyang_name    = "李阳";		    // 李阳的账户名称
	string liyang_number  = "12345678";		// 李阳的账号
	long   liyang_balance = 1000;			// 李阳的账户余额

	string zhouyan_name    = "周燕";		    // 周燕的账户名称
	string zhouyan_number  = "87654321";	// 周燕的账号
	long   zhouyan_balance = 200;			// 周燕的账户余额

	liyang_balance -= 200;					// 李阳取出200元
	zhouyan_balance += 100;					// 周燕存入100元

	cout << "李阳的账户：\"" << liyang_name << "\" (" << liyang_number
		 << ") " << liyang_balance << "元\n";

	cout << "周燕的账户：\"" << zhouyan_name << "\" (" << zhouyan_number
		 << ") " << zhouyan_balance << "元\n";
}
