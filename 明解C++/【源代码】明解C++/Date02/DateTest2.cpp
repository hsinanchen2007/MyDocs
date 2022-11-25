// 日期类Date（第2版）的使用例程（确认成员函数to_string的作用）

#include <iostream>
#include "Date.h"

using namespace std;
 
int main()
{
	const Date birthday(1963, 11, 18);		// 生日
	Date day[3];							// 数组（今天的日期）

	cout << "birthday = " << birthday << '\n';
	cout << "birthday的字符串表示：\"" << birthday.to_string() << "\"\n"; 

	for (int i = 0; i < 3; i++)
		cout << "day[" << i << "]的字符串表示：\"" << day[i].to_string() << "\"\n";
}
